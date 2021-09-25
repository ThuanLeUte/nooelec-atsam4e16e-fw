/**
 * @file       main.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-25
 * @author     Thuan Le
 * @brief      Main file
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <asf.h>

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
int main (void)
{
  board_init();

  while (1)
  {
    if (ioport_get_pin_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE)
      ioport_set_pin_level(LED_0_PIN, LED_0_ACTIVE);
    else
      ioport_set_pin_level(LED_0_PIN, !LED_0_ACTIVE);
  }
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */

