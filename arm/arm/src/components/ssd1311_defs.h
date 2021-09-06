/**
 * @file       ssd1311_defs.h
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
#ifndef __SSD1311_DEFS_H
#define __SSD1311_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief SSD1311 init function struct
 */
typedef struct
{
  uint8_t cmd;
  uint8_t data;
}
ssd1311_function_t;

/**
 * @brief SSD1311 init commands struct
 */
typedef enum
{
  SSD1311_START,
  SSD1311_END,
  SSD1311_CMD,
  SSD1311_DATA,
  SSD1311_DELAY
}
ssd1311_cmd_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
#define SSD1311_INFO(_cmd, _data) { .cmd = _cmd, .data =_data }
static const ssd1311_function_t SSD1311_CFG_SCRIPT[] =
{
    SSD1311_INFO(SSD1311_START, SSD1311_START)
  , SSD1311_INFO(SSD1311_CMD,  0x08)
  , SSD1311_INFO(SSD1311_CMD,  0x2A)
  , SSD1311_INFO(SSD1311_CMD,  0x71)
  , SSD1311_INFO(SSD1311_DATA, 0x00)
  , SSD1311_INFO(SSD1311_CMD,  0x72)
  , SSD1311_INFO(SSD1311_DATA, 0x00)
  , SSD1311_INFO(SSD1311_CMD,  0x79)
  , SSD1311_INFO(SSD1311_CMD,  0x81)
  , SSD1311_INFO(SSD1311_CMD,  0x7F)
  , SSD1311_INFO(SSD1311_CMD,  0xD5)
  , SSD1311_INFO(SSD1311_CMD,  0x60)
  , SSD1311_INFO(SSD1311_CMD,  0xD9)
  , SSD1311_INFO(SSD1311_CMD,  0x78)
  , SSD1311_INFO(SSD1311_CMD,  0xDA)
  , SSD1311_INFO(SSD1311_CMD,  0x10)
  , SSD1311_INFO(SSD1311_CMD,  0xDB)
  , SSD1311_INFO(SSD1311_CMD,  0x40)
  , SSD1311_INFO(SSD1311_CMD,  0xDC)
  , SSD1311_INFO(SSD1311_CMD,  0x03)

  , SSD1311_INFO(SSD1311_DELAY, 120)

  , SSD1311_INFO(SSD1311_CMD,  0x78)
  , SSD1311_INFO(SSD1311_CMD,  0x09)
  , SSD1311_INFO(SSD1311_CMD,  0x06)
  , SSD1311_INFO(SSD1311_CMD,  0x28)
  , SSD1311_INFO(SSD1311_CMD,  0x01)
  , SSD1311_INFO(SSD1311_CMD,  0x02)
  , SSD1311_INFO(SSD1311_CMD,  0x06)
  , SSD1311_INFO(SSD1311_CMD,  0x0C)
  , SSD1311_INFO(SSD1311_DELAY, 5)

  , SSD1311_INFO(SSD1311_END, SSD1311_END)
};
#undef SSD1311_INFO

/* Public function prototypes ----------------------------------------- */
/* -------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __SSD1311_DEFS_H

/* End of file -------------------------------------------------------- */
