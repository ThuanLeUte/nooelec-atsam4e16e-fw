
/**
 * @file       bsp_io.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package IO
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_io.h"
#include "bsp_lcd.h"
#include "bsp_rtc.h"
#include "it_callback.h"

/* Private defines ---------------------------------------------------- */
#define ioport_set_pin_input_mode(pin, mode, sense) \
  do                                                \
  {                                                 \
    ioport_set_pin_dir(pin, IOPORT_DIR_INPUT);      \
    ioport_set_pin_mode(pin, mode);                 \
    ioport_set_pin_sense_mode(pin, sense);          \
  } while (0)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_gpio_init(void)
{
  for (uint8_t i = 1; i <= SENSOR_COUNT_MAX; i++)
  {
    ioport_set_pin_dir(PIN_INDEX(i), IOPORT_DIR_INPUT);
    ioport_set_pin_level(PIN_INDEX(i), IOPORT_PIN_LEVEL_LOW);
    ioport_set_pin_mode(PIN_INDEX(i), IOPORT_MODE_PULLDOWN);
  }
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
