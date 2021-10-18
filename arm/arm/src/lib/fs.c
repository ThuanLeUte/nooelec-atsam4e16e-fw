
/**
 * @file       bsp.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package (BSP)
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "fs.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
bool_t fs_init(void)
{
  FATFS fs;    // File system variable

  // Mount the file system
  if (f_mount(LUN_ID_SD_MMC_0_MEM, &fs) != FR_OK)
    return BS_FALSE;

  return BS_TRUE;
}

bool_t fs_write(const char *path, char *data)
{
  FIL fhandle; // File handle variable
  static uint32_t pos = 0;

  // Open a file
  if (f_open(&fhandle, path, FA_OPEN_ALWAYS | FA_WRITE) == FR_OK)
  {
    // Seek to write position
    if (f_tell(&fhandle) != pos)
      f_lseek(&fhandle, pos);

    // Write data to file
    if (f_puts(data, &fhandle) == -1)
      return BS_FALSE;

    // Get the current position
    pos = f_tell(&fhandle);
    
    // Close the file # IMPORTANT
    f_close(&fhandle);
  }
  else
  {
    return BS_FALSE;
  }

  return BS_TRUE;
}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
