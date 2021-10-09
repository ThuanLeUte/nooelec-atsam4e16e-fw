/**
 * @file       bsp_io.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package IO
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_IO_H
#define __BSP_IO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <asf.h>
#include "bsp/bsp_io_10.h"

/* Public defines ----------------------------------------------------- */
#define SENSOR_COUNT_MAX  (99)

#define PORT(i)            BSP_IO_GET_PORT(&IO_SENSOR[i])
#define PORT_ID(i)         BSP_IO_GET_PORT_ID(&IO_SENSOR[i])
#define PIN(i)             BSP_IO_GET_PIN(&IO_SENSOR[i])
#define PIN_INDEX(i)       BSP_IO_GET_PIN_INDEX(&IO_SENSOR[i])

/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
#define BSP_IO_GET_PORT(x)              bsp_io_get_port_address(x)
#define BSP_IO_GET_PORT_ID(x)           bsp_io_get_port_id(x)
#define BSP_IO_GET_PIN(x)               bsp_io_get_pin(x)
#define BSP_IO_GET_PIN_INDEX(x)         bsp_io_get_pin_index(x)

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
Pio *bsp_io_get_port_address(const bsp_io_10_t *io);
uint32_t bsp_io_get_port_id(const bsp_io_10_t *io);
uint32_t bsp_io_get_pin(const bsp_io_10_t *io);
uint32_t bsp_io_get_pin_index(const bsp_io_10_t *io);

void bsp_gpio_init(void);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_IO_H

/* End of file -------------------------------------------------------- */
