
/**
 * @file       bsp_rtc.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package RTC
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_rtc.h"
#include "bsp.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
void bsp_rtc_init(void)
{
  pmc_switch_sclk_to_32kxtal(PMC_OSC_XTAL);

  while (!pmc_osc_is_ready_32kxtal());

  rtc_set_hour_mode(RTC, 0);
}

void bsp_rtc_get_time_struct(date_time_t *dt)
{
  rtc_get_time(RTC, (uint32_t *)&dt->tm_hour, (uint32_t *)&dt->tm_min, (uint32_t *)&dt->tm_sec);
  rtc_get_date(RTC, (uint32_t *)&dt->tm_year, (uint32_t *)&dt->tm_mon, (uint32_t *)&dt->tm_mday, NULL);

  dt->tm_year %= 1000;
}

void bsp_rtc_make_string_time_style(char *out, date_time_t *dt)
{
  sprintf(out, "%02d%02d%02d:%02d%02d%02d", dt->tm_year, dt->tm_mon, dt->tm_mday,
                                            dt->tm_hour, dt->tm_min, dt->tm_sec);
}

/* Function definitions ----------------------------------------------- */
/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
