/**
 * @file       ssd1311.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-06
 * @author     Thuan Le
 * @brief      Driver support SSD1311 (LCD driver)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "ssd1311.h"
#include "bsp_io_11.h"

/* Private defines ---------------------------------------------------- */
#define SSD1311_CMD_MODE    (0x80)
#define SSD1311_DATA_MODE   (0x40)

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
static base_status_t m_ssd1311_run_cfg_script(ssd1311_t *me);

/* Function definitions ----------------------------------------------- */
base_status_t ssd1311_init(ssd1311_t *me)
{
  if ((me == NULL) || (me->spi_send == NULL))
    return BS_ERROR_PARAMS;

  m_ssd1311_run_cfg_script(me);

  return BS_OK;
}

base_status_t ssd1311_write_cmd(ssd1311_t *me, uint8_t cmd)
{
  CHECK(BS_OK == me->i2c_write(me->device_address, SSD1311_CMD_MODE, &cmd, 1), BS_ERROR);

  return BS_OK;
}

base_status_t ssd1311_write_data(ssd1311_t *me, uint8_t *data, uint16_t len)
{
  CHECK(BS_OK == me->i2c_write(me->device_address, SSD1311_DATA_MODE, &data, len), BS_ERROR);

  return BS_OK;
}

base_status_t ssd1311_write_data_byte(ssd1311_t *me, uint8_t data)
{
  CHECK(BS_OK == me->i2c_write(me->device_address, SSD1311_DATA_MODE, &data, 1), BS_ERROR);

  return BS_OK;
}

/* Private function definitions ---------------------------------------- */
/**
 * @brief         SSD1311 run cfg script
 *
 * @param[in]     me      Pointer to handle of SSD1311 module.
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
static base_status_t m_ssd1311_run_cfg_script(ssd1311_t *me)
{
  int i          = 0;
  int end_script = 0;

  do
  {
    switch (SSD1311_CFG_SCRIPT[i].cmd)
    {
    case SSD1311_START:
      break;
    case SSD1311_CMD:
      ssd1311_write_cmd(me, SSD1311_CFG_SCRIPT[i].data & 0xFF);
      break;
    case SSD1311_DATA:
      ssd1311_write_data_byte(me, SSD1311_CFG_SCRIPT[i].data & 0xFF);
      break;
    case SSD1311_DELAY:
      me->delay_ms(SSD1311_CFG_SCRIPT[i].data);
      break;
    case SSD1311_END:
      end_script = 1;
      break;
    }
    i++;
  }
  while (!end_script);

  return BS_OK;
}

/* End of file -------------------------------------------------------- */
