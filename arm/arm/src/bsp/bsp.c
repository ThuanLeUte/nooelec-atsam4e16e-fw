
/**
 * @file       bsp.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp.h"
#include "bsp_io.h"
#include "bsp_rtc.h"
#include "platform.h"

/* Private defines ---------------------------------------------------- */
#define UART_SERIAL_BAUDRATE              9600
#define UART_SERIAL_MODE                  UART_MR_PAR_NO

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static uint8_t m_read_buffer[500];
static uint16_t m_read_buffer_index = 0;

/* Private function prototypes ---------------------------------------- */
static void m_bsp_i2c_init(void);
static void m_bsp_uart_init(void);
static void m_bsp_sdcard_init(void);

/* Function definitions ----------------------------------------------- */
void bsp_hw_init(void)
{
  m_bsp_i2c_init();
  m_bsp_uart_init();
  bsp_rtc_init();

#if (_CONFIG_ELEVATOR_BOARD) // {
#else // }{
  m_bsp_sdcard_init();
#endif // }

  bsp_gpio_init();
}

int bsp_i2c_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len)
{
  twi_package_t packet_write;

  packet_write.chip        = slave_addr;        // TWI slave bus address
  packet_write.addr[0]     = reg_addr;          // TWI slave memory address data
  packet_write.addr_length = sizeof(reg_addr);  // TWI slave memory address data size
  packet_write.buffer      = (void *)p_data;    // Transfer data source buffer
  packet_write.length      = len;               // Transfer data size (bytes)

  return twi_master_write(TWI0, &packet_write);
}

uint32_t bsp_uart_write(uint8_t p_data)
{
  return uart_write(UART0, p_data);
}

void bsp_delay(uint32_t ms)
{
  delay_ms(ms);
}

void UART0_Handler()
{
  uint32_t dw_status = uart_get_status(UART0);

  if (dw_status & UART_SR_RXRDY)
  {
    uint8_t received_byte;
    uart_read(UART0, &received_byte);
    m_read_buffer[m_read_buffer_index] = received_byte;
    m_read_buffer_index++;
    if (m_read_buffer_index == 10)
      m_read_buffer_index = 0;
  }
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief I2C init
 */
static void m_bsp_i2c_init(void)
{
  twi_master_options_t opt = {
      .speed = 100000
  };

  twi_master_setup(TWI0, &opt);
}

/**
 * @brief Uart init
 */
static void m_bsp_uart_init(void)
{
  const sam_uart_opt_t uart_settings = { sysclk_get_cpu_hz(), UART_SERIAL_BAUDRATE, UART_SERIAL_MODE };

  // Enable the uart peripheral clock
  sysclk_enable_peripheral_clock(ID_UART0);

  // Set the pins to use the uart peripheral
  pio_set_peripheral(PIOA, PIO_TYPE_PIO_PERIPH_A, PINS_UART0);

  // Init UART0 and enable Rx and Tx
  uart_init(UART0, &uart_settings);

  // Interrupt reading ready
  uart_enable_interrupt(UART0, UART_IER_RXRDY);
  NVIC_EnableIRQ(UART0_IRQn);
}

/**
 * @brief Sdcard init
 */
static void m_bsp_sdcard_init(void)
{
  Ctrl_status status;

  // Enable PIOA clock to detect Card Detect (CD) change
  sysclk_enable_peripheral_clock(ID_PIOA);

  // Configure SD card pins as per MCI peripheral (periph C)
  pio_set_peripheral(PIOA, PIO_PERIPH_C, PIO_PA30C_MCDA0 | // MCI Data 0
                                         PIO_PA31C_MCDA1 | // MCI Data 1
                                         PIO_PA26C_MCDA2 | // MCI Data 2
                                         PIO_PA27C_MCDA3 | // MCI Data 3
                                         PIO_PA28C_MCCDA | // MCI Command
                                         PIO_PA29C_MCCK);  // MCI Clock

  // Initialize SD MMC stack
  sd_mmc_init();

  //  Wait until SD stack initialized and SD card inserted
  do
  {
    // Check if stack ready
    status = sd_mmc_test_unit_ready(0);
    if (status == CTRL_FAIL)
    {
      // Wait for a card to be inserted
      while (sd_mmc_check(0) != CTRL_NO_PRESENT)
      {
        // Use a timeout here for real projects.
      }
    }
  } while (status != CTRL_GOOD);
}

/* End of file -------------------------------------------------------- */
