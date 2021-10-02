/**
 * @file       bsp_lcd.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support LCD for Spo2 and Heartrate board
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <math.h>
#include "bsp_lcd.h"
#include "delay.h"
#include "bsp.h"

/* Private defines ---------------------------------------------------- */
ssd1311_t m_ssd1311;

/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_lcd_init(void)
{
  m_ssd1311.device_address = SSD1311_I2C_ADDRESS;
  m_ssd1311.i2c_write      = bsp_i2c_write;
  m_ssd1311.delay          = bsp_delay;
  
  ssd1311_init(&m_ssd1311);
}

/* Public function for project ---------------------------------------- */
/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
