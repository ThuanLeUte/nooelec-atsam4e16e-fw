/**
 * @file       bsp_rtc.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package RTC
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_RTC_H
#define __BSP_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <asf.h>
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         Bsp rtc init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
void bsp_rtc_init(void);

void bsp_rtc_get_time_struct(date_time_t *dt);

/**
 * @brief Create string from <dt>
 *        char *out = "YYMMDD:HHMMSS\0"
 *
 * @param[in] dt Time struct handle
 * @param[out] out Time in string (buffer size >= 14)
 */
void bsp_rtc_make_string_time_style(char *out, date_time_t *dt);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_RTC_H

/* End of file -------------------------------------------------------- */
