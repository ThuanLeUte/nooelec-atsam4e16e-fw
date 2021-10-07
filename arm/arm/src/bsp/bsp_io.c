
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
#include "bsp/bsp_io.h"

/* Private defines ---------------------------------------------------- */
#define SENSOR_COUNT_MAX  (99)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
void bsp_gpio_init(void)
{
  #define PORT       BSP_IO_GET_PORT(&IO_SENSOR[i])
  #define PORT_ID    BSP_IO_GET_PORT_ID(&IO_SENSOR[i])
  #define PIN        BSP_IO_GET_PIN(&IO_SENSOR[i])
  #define PIN_INDEX  BSP_IO_GET_PIN_INDEX(&IO_SENSOR[i])

  for (uint8_t i = 1; i <= SENSOR_COUNT_MAX; i++)
  {
    // Configure as input with pull-up and denouncing
    pio_set_input(PORT, PIN, PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE);

    // Configure External Interrupt on falling edge
    pio_handler_set(PORT, PORT_ID, PIN, PIO_IT_FALL_EDGE, bsp_io_interrupt_handler);

    // Enable external interrupt
    pio_enable_pin_interrupt(PIN_INDEX);
  }

  // Configure Ext Interrupt in NVIC
  irq_register_handler(PIOA_IRQn, 0);
  irq_register_handler(PIOB_IRQn, 0);
  irq_register_handler(PIOC_IRQn, 0);
  irq_register_handler(PIOD_IRQn, 0);
  irq_register_handler(PIOE_IRQn, 0);

  #undef PORT
  #undef PORT_ID
  #undef PIN
  #undef PIN_INDEX
}

void bsp_io_interrupt_handler(uint32_t id, uint32_t index)
{

}

/* Function definitions ----------------------------------------------- */
Pio *bsp_io_get_port_address(const bsp_io_10_t *io)
{
  return io->port;
}

uint32_t bsp_io_get_port_id(const bsp_io_10_t *io)
{
  return io->port_id;
}

uint16_t bsp_io_get_pin(const bsp_io_10_t *io)
{
  return io->pin;
}

uint16_t bsp_io_get_pin_index(const bsp_io_10_t *io)
{
  return io->pin_index;
}
/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
