
/**
 * @file       bsp_io.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Interrupt callback
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "it_callback.h"
#include "bsp_io.h"
#include "sys/sys_damos_ram.h"
#include "sys/sys.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void exint_io_handler(uint32_t id, uint32_t index)
{
  for (uint8_t i = 1; i <= 50; i++)
  {
    if ((id == PORT_ID(i)) && (index == PIN(i)))
    {
      if (!pio_get(PORT(i), PIO_TYPE_PIO_INPUT, PIN(i)))
      {
        xQueueSendFromISR(g_sensor_evt_queue, (void *)&i, pdMS_TO_TICKS(100));
      }
    }
  }
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
