/**
 * @file       sys.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-25
 * @author     Thuan Le
 * @brief      System file
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include "bsp/bsp.h"
#include "bsp/bsp_can.h"
#include "bsp/bsp_lcd.h"
#include "bsp/bsp_io.h"
#include "bsp/bsp_rtc.h"
#include "lib/fs.h"
#include "sys.h"
#include "sys_damos_ram.h"

/* Private defines ---------------------------------------------------- */
#define SENSOR_TASK_STACK_SIZE       (2048)
#define SENSOR_TASK_PRIORITY         (3)

#define MAIN_TASK_STACK_SIZE         (2048)
#define MAIN_TASK_PRIORITY           (3)

#define SD_PATH   "0:sensor_events.log"

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static xTaskHandle m_sensor_task_hdl;
static xTaskHandle m_main_task_hdl;

/* Private function prototypes ---------------------------------------- */
static void m_sensor_hande_task(void *params);
static void m_lcd_write_sensor_event(date_time_t *dt, uint8_t sensor_name);
static void m_sdcard_write_sensor_event(date_time_t *dt, uint8_t sensor_name);

/* Function definitions ----------------------------------------------- */
void sys_init(void)
{
  g_sensor_evt_queue = xQueueCreate(10, sizeof(uint8_t));

  sysclk_init();   // Initialize System Clock
  board_init();    // Board init
  bsp_hw_init();   // Hardware init
  bsp_can_init();  // Can bus init
  bsp_lcd_init();  // LCD init
  fs_init();       // FS init

  // Create task to handle sensor events
  xTaskCreate(m_sensor_hande_task,
              "SensorHandleTask",
              SENSOR_TASK_STACK_SIZE,
              NULL,
              SENSOR_TASK_PRIORITY,
              m_sensor_task_hdl);

  // Create task to handle main system
  xTaskCreate(sys_run,
              "SystemRun",
              MAIN_TASK_STACK_SIZE,
              NULL,
              MAIN_TASK_PRIORITY,
              m_main_task_hdl);

  vTaskStartScheduler();
}

void sys_run(void)
{
  date_time_t dt_send;
  date_time_t dt_get;
  uint8_t sensor;

  while (1)
  {
    bsp_rtc_get_time_struct(&dt_send);

    bsp_can_send_sensor_event(&dt_send, 1);

    if (bsp_can_is_available())
    {
      bsp_can_get_sensor_event(&dt_get, &sensor);
    }

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

/* Private function definitions --------------------------------------- */
/**
 * @brief Sensor handle task
 */
static void m_sensor_hande_task(void *params)
{
  date_time_t dt;

  while (1)
  {
    for (uint8_t i = 1; i <= 99; i++)
    {
      if (!ioport_get_pin_level(PIN_INDEX(i)) && !IO_SENSOR_STATE[i])
      {
        bsp_rtc_get_time_struct(&dt);
        
        m_lcd_write_sensor_event(&dt, i);
        m_sdcard_write_sensor_event(&dt,i);
        IO_SENSOR_STATE[i] = true;
      }
      else if (ioport_get_pin_level(PIN_INDEX(i)) && IO_SENSOR_STATE[i])
      {
        IO_SENSOR_STATE[i] = false;
      }

      // if (pio_get(PORT(i), PIO_TYPE_PIO_INPUT, PIN(i)) && !IO_SENSOR_STATE[i])
      // {
      //   m_lcd_write_sensor_event(i);
      //   IO_SENSOR_STATE[i] = true;
      // }
      // else if (!pio_get(PORT(i), PIO_TYPE_PIO_INPUT, PIN(i)) && IO_SENSOR_STATE[i])
      // {
      //   IO_SENSOR_STATE[i] = false;
      // }
    }

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

/**
 * @brief LCD write sensor event
 */
static void m_lcd_write_sensor_event(date_time_t *dt, uint8_t sensor_name)
{
  static uint8_t m_current_row = 0;
  char time[14];

  bsp_rtc_make_string_time_style(time, dt);

  bsp_lcd_write_string(0, m_current_row++, "%s: SS%02d", time, sensor_name);
  if (m_current_row == 4)
    m_current_row = 0;
}

/**
 * @brief SDcard write sensor event
 */
static void m_sdcard_write_sensor_event(date_time_t *dt, uint8_t sensor_name)
{
  char str[200];
  char time[14];

  bsp_rtc_make_string_time_style(time, dt);

  sprintf(str, "%s: SS%2d\n", time, sensor_name);

  fs_write(SD_PATH, str);
}

/* End of file -------------------------------------------------------- */
