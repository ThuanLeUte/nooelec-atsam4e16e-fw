/**
 * @file       bsp_lcd.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support LCD for Spo2 and Heart rate board
 * 
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <math.h>
#include <stdarg.h>
#include <string.h>
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
void m_bsp_lcd_set_position(uint8_t row, uint8_t col);

/* Function definitions ----------------------------------------------- */
void bsp_lcd_init(void)
{
  m_ssd1311.device_address = SSD1311_I2C_ADDRESS;
  m_ssd1311.i2c_write      = bsp_i2c_write;
  m_ssd1311.delay          = bsp_delay;
  
  ssd1311_init(&m_ssd1311);
}

void bsp_lcd_write_string(uint8_t x, uint8_t y, char *fmt_string, ...)
{
  char str[256] = "";
  unsigned char i = 0;

  va_list args;
  va_start(args, fmt_string);
  vsprintf(str + strlen(str), fmt_string, args);
  va_end(args);

  m_bsp_lcd_set_position(x, y);
  while(str[i])
  {
    ssd1311_write_data_byte(&m_ssd1311, str[i]);
    i++;
  }
}

/* Private function definitions --------------------------------------- */
void m_bsp_lcd_set_position(uint8_t x, uint8_t y)
{
  ssd1311_write_cmd(&m_ssd1311, 0x80 + 0x20 * y + x);
}

/* End of file -------------------------------------------------------- */
