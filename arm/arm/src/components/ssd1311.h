/**
 * @file       ssd1311.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-06
 * @author     Thuan Le
 * @brief      Driver support SSD1311 (LCD driver)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SSD1311_H
#define __SSD1311_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "ssd1311_defs.h"

/* Public defines ----------------------------------------------------- */
#define SSD1311_I2C_ADDRESS   (0x3C)  // 7 Bits - SA0 = 0

/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief SSD1311 sensor struct
 */
typedef struct 
{
  uint8_t device_address; // I2C device address

  // Write n-bytes from device's internal address <reg_addr> via I2C bus
  int (*i2c_write) (uint8_t slave_addr, uint8_t reg_addr, uint8_t *data, uint32_t len);

  // Delay ms
  void (*delay) (uint32_t ms);
}
ssd1311_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Initialize SSD1311
 *
 * @param[in]     me     Pointer to handle of SSD1311 module.
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t ssd1311_init(ssd1311_t *me);

/**
 * @brief         SSD1311 write comamnd
 *
 * @param[in]     me      Pointer to handle of SSD1311 module.
 * @param[in]     cmd     Comamnd
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t ssd1311_write_cmd(ssd1311_t *me, uint8_t cmd);

/**
 * @brief         SSD1311 write 1 byte data
 *
 * @param[in]     me      Pointer to handle of SSD1311 module.
 * @param[in]     data    Data to write
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t ssd1311_write_data_byte(ssd1311_t *me, uint8_t data);

/**
 * @brief         SSD1311 write data
 *
 * @param[in]     me      Pointer to handle of SSD1311 module.
 * @param[in]     data    Pointer to data
 * @param[in]     len     Data lenght
 *
 * @attention     None
 *
 * @return
 * - BS_OK
 * - BS_ERROR
 */
base_status_t ssd1311_write_data(ssd1311_t *me, uint8_t *data, uint16_t len);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __SSD1311_H

/* End of file -------------------------------------------------------- */
