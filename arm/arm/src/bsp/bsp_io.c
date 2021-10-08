
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

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
void bsp_gpio_init(void)
{
  for (uint8_t i = 1; i <= 10; i++)
  {
    // Configure as input with pull-up and denouncing
    pio_set_input(PORT, PIN, PIO_INPUT | PIO_OPENDRAIN | PIO_DEBOUNCE);

    // Configure debounce filter at 25Hz
    pio_set_debounce_filter(PORT, PIN, 25);

    // Configure External Interrupt on falling edge
    pio_handler_set(PORT, PORT_ID, PIN, PIO_IT_RISE_EDGE, bsp_io_interrupt_handler);

    // Enable external interrupt
    pio_enable_interrupt(PORT, PIN);
  }

  // Configure Ext Interrupt in NVIC
  irq_register_handler(PIOA_IRQn, 0);
  irq_register_handler(PIOB_IRQn, 0);
  irq_register_handler(PIOC_IRQn, 0);
  irq_register_handler(PIOD_IRQn, 0);
  irq_register_handler(PIOE_IRQn, 0);
}

void bsp_io_interrupt_handler(uint32_t id, uint32_t index)
{
  for (uint8_t i = 1; i <= 10; i++)
  {
    if ((id == PORT_ID) && (index == PIN))
    {
      if (pio_get(PORT, PIO_TYPE_PIO_INPUT, PIN))
      {
        static uint8_t m_current_row = 0;
        char time[14];

        bsp_rtc_make_string_time_style(time);

        bsp_lcd_write_string(0, m_current_row++, "%s: SS%d", time, i);
        if (m_current_row == 4)
          m_current_row = 0;
      }
    }
  }
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
