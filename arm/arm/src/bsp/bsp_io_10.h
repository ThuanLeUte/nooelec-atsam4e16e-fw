/**
 * @file       bsp_io_11.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-23
 * @author     Thuan Le
 * @brief      Pin description for hardware version 1.0
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_IO_10_H
#define __BSP_IO_10_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>

/* Public defines ----------------------------------------------------- */
                                    // Schematic
// PIN NAME PORT 0 ``````````````````````````````
#define IO_LCD_BACKLIGHT        (25)    // LCD backlight control
#define IO_LCD_RST              (26)    // LCD reset - Active Low
#define IO_LCD_DC               (27)    // LCD display data - command
#define IO_LCD_SCL              (28)    // LCD clock
#define IO_LCD_SDA              (29)    // LCD data
#define IO_LCD_CS               (30)    // LCD chip select - Active Low
#define IO_LCD_POWER            (31)    // LCD power control

/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/* -------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_IO_10_H

/* End of file -------------------------------------------------------- */
