/**
 * @file       bsp_can.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-26
 * @author     Thuan Le
 * @brief      Board Support Package for CAN BUS
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_CAN_H
#define __BSP_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <asf.h>

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Board support package CAN init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
void bsp_can_init(void);

void bsp_can_send(void);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_CAN_H

/* End of file -------------------------------------------------------- */
