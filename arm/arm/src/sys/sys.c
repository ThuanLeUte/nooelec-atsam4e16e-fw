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
#include "sys.h"
#include "bsp/bsp.h"
#include "bsp/bsp_can.h"
#include "bsp/bsp_lcd.h"
#include "bsp/bsp_io.h"
#include "bsp/bsp_rtc.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static void m_sys_sdcard_test(void);
void vTaskCode(void *pvParameters);

/* Function definitions ----------------------------------------------- */

void vTaskCode(void *pvParameters)
{
  for (;;)
  {
    // Task code goes here.
  }
}

void sys_init(void)
{

  sysclk_init();  // Initialize System Clock
  board_init();   // Board init
  bsp_hw_init();  // Hardware init
  bsp_can_init(); // Can bus init
  bsp_lcd_init();

  xTaskCreate(vTaskCode,
              "ExampleTask",
              1024,
              NULL,
              2,
              NULL);

  vTaskStartScheduler();

  // Will only get here if there was insufficient memory to create the idle
	// and/or timer task.
}

void sys_run(void)
{
  bsp_can_send();
  
  // for (uint8_t i = 1; i <= 1; i++)
  // {
  //   if (pio_get(PORT, PIO_TYPE_PIO_INPUT, PIN))
  //   {
  //     static uint8_t m_current_row = 0;
  //     char time[14];

  //     bsp_rtc_make_string_time_style(time);

  //     bsp_lcd_write_string(0, m_current_row++, "%s: SS%d", time, i);
  //     if (m_current_row == 4)
  //       m_current_row = 0;
  //   }
  // }
}

/* Private function definitions --------------------------------------- */
/**
 * @brief SDcard test
 */
static void m_sys_sdcard_test(void)
{
  FATFS fs;    // File system variable
  FIL fhandle; // File handle variable
  char buf[25];

  // Test file name (note 0: indicates volume 0)
  const char test_file_name[] = "0:sam_arm_sd.txt";

  // Mount the file system
  if (f_mount(LUN_ID_SD_MMC_0_MEM, &fs) != FR_OK)
    return;

  // Open a file
  if (f_open(&fhandle, test_file_name, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
  {
    // File opened successfully, read card capacity
    uint32_t cap = sd_mmc_get_capacity(0);
    sprintf(buf, "Capacity: %lu\n", cap);

    // Write capacity to file
    if (f_puts(buf, &fhandle) != 0)
      pio_set_pin_high(LED_0_PIN);

    // Close the file #IMPORTANT
    f_close(&fhandle);
  }

  // Nothing else to do
  while (1)
    ;
}

/* End of file -------------------------------------------------------- */
