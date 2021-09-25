
/**
 * @file       bsp.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp.h"

/* Private defines ---------------------------------------------------- */
#define TWI_INSTANCE         0
#define SPI_INSTANCE         1

/* Private enumerate/structure ---------------------------------------- */
static nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE);
static nrf_drv_spi_t m_spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);

/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static void m_bsp_i2c_init(void);
static void m_bsp_spi_init(void);
static void m_bsp_gpio_init(void);

/* Function definitions ----------------------------------------------- */
void bsp_hw_init(void)
{
  m_bsp_i2c_init();
  m_bsp_spi_init();
  m_bsp_gpio_init();
}

int bsp_i2c_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len)
{
}

int bsp_i2c_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *p_data, uint32_t len)
{
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief         I2C init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
static void m_bsp_i2c_init(void)
{
}

/**
 * @brief         Gpio init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
static void m_bsp_gpio_init(void)
{

}

/* End of file -------------------------------------------------------- */
