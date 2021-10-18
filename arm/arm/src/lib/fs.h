/**
 * @file       fs.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      File System (FS)
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __FS_H
#define __FS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <asf.h>
#include "bsp/bsp.h"

/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/**
 * @brief         FS init
 *
 * @param[in]     None
 *
 * @attention     None
 *
 * @return        None
 */
bool_t fs_init(void);

/**
 * @brief         Fs write
 *
 * @param[in]     path    File path
 * @param[in]     data    Pointer to data
 *
 * @attention     None
 *
 * @return        None
 */
bool_t fs_write(const char *path, char *data);

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __FS_H

/* End of file -------------------------------------------------------- */
