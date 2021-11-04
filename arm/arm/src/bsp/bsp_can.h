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
#include "bsp.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/**
 * @brief Can message enum
 */
typedef enum
{
  MSG_SENSOR = 0
}
bsp_can_msg_t;

/**
 * @brief Can message sensor event
 */
typedef struct
{
  uint8_t tm_year;
  uint8_t tm_mon;
  uint8_t tm_mday;
  uint8_t tm_hour;
  uint8_t tm_min;
  uint8_t tm_sec;
  uint8_t sensor;
  uint8_t unused;
}
bsp_can_sensor_event_t;

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

bool_t bsp_can_is_available(void);

void bsp_can_send_sensor_event(date_time_t *dt, uint8_t sensor_name);

void bsp_can_get_sensor_event(date_time_t *dt, uint8_t *sensor_name);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_CAN_H

/* End of file -------------------------------------------------------- */
