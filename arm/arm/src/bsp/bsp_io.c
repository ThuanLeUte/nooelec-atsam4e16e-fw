
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
  for (uint8_t i = 1; i <= 99; i++)
  {
    ioport_set_pin_input_mode(PIN_INDEX(i), IOPORT_MODE_PULLUP, IOPORT_SENSE_BOTHEDGES);

    // Configure as input with pull-down and denouncing
    // pio_set_input(PORT(i), PIN(i), PIO_DEFAULT);
    pio_pull_down(PORT(i), PIN(i), ENABLE);

    // // Configure debounce filter at 25Hz
    // pio_set_debounce_filter(PORT(i), PIN(i), 1000);

    // // Configure External Interrupt on falling edge
    // pio_handler_set(PORT(i), PORT_ID(i), PIN(i), PIO_IT_RISE_EDGE, exint_io_handler);

    // // Enable external interrupt
    // pio_enable_interrupt(PORT(i), PIN(i));
  }

  // Configure Ext Interrupt in NVIC
  // irq_register_handler(PIOA_IRQn, 0);
  // irq_register_handler(PIOB_IRQn, 0);
  // irq_register_handler(PIOC_IRQn, 0);
  // irq_register_handler(PIOD_IRQn, 0);
  // irq_register_handler(PIOE_IRQn, 0);
}

Pio *bsp_io_get_port_address(const bsp_io_10_t *io)
{
  return io->port;
}

uint32_t bsp_io_get_port_id(const bsp_io_10_t *io)
{
  return io->port_id;
}

uint32_t bsp_io_get_pin(const bsp_io_10_t *io)
{
  return io->pin;
}

uint32_t bsp_io_get_pin_index(const bsp_io_10_t *io)
{
  return io->pin_index;
}

/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
