/**
 * @file       bsp_io_10.h
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-23
 * @author     Thuan Le
 * @brief      Pin description for hardware version 1.0
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp/bsp_io_10.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
bool IO_SENSOR_STATE[100] = { 0 };

const bsp_io_10_t IO_SENSOR[] = {
     { IO_SENSOR_0 , FALLING_EDGE }
    ,{ IO_SENSOR_1 , FALLING_EDGE }
    ,{ IO_SENSOR_2 , FALLING_EDGE }
    ,{ IO_SENSOR_3 , FALLING_EDGE }
    ,{ IO_SENSOR_4 , FALLING_EDGE }
    ,{ IO_SENSOR_5 , FALLING_EDGE }
    ,{ IO_SENSOR_6 , FALLING_EDGE }
    ,{ IO_SENSOR_7 , FALLING_EDGE }
    ,{ IO_SENSOR_8 , FALLING_EDGE }
    ,{ IO_SENSOR_9 , FALLING_EDGE }
    ,{ IO_SENSOR_10, FALLING_EDGE }
    ,{ IO_SENSOR_11, FALLING_EDGE }
    ,{ IO_SENSOR_12, FALLING_EDGE }
    ,{ IO_SENSOR_13, FALLING_EDGE }
    ,{ IO_SENSOR_14, FALLING_EDGE }
    ,{ IO_SENSOR_15, FALLING_EDGE }
    ,{ IO_SENSOR_16, FALLING_EDGE }
    ,{ IO_SENSOR_17, FALLING_EDGE }
    ,{ IO_SENSOR_18, FALLING_EDGE }
    ,{ IO_SENSOR_19, FALLING_EDGE }
    ,{ IO_SENSOR_20, FALLING_EDGE }
    ,{ IO_SENSOR_21, FALLING_EDGE }
    ,{ IO_SENSOR_22, FALLING_EDGE }
    ,{ IO_SENSOR_23, FALLING_EDGE }
    ,{ IO_SENSOR_24, FALLING_EDGE }
    ,{ IO_SENSOR_25, FALLING_EDGE }
    ,{ IO_SENSOR_26, FALLING_EDGE }
    ,{ IO_SENSOR_27, FALLING_EDGE }
    ,{ IO_SENSOR_28, RISING_EDGE  }
    ,{ IO_SENSOR_29, RISING_EDGE  }
    ,{ IO_SENSOR_30, RISING_EDGE  }
    ,{ IO_SENSOR_31, RISING_EDGE  }
    ,{ IO_SENSOR_32, RISING_EDGE  }
    ,{ IO_SENSOR_33, RISING_EDGE  }
    ,{ IO_SENSOR_34, RISING_EDGE  }
    ,{ IO_SENSOR_35, RISING_EDGE  }
    ,{ IO_SENSOR_36, RISING_EDGE  }
    ,{ IO_SENSOR_37, RISING_EDGE  }
    ,{ IO_SENSOR_38, RISING_EDGE  }
    ,{ IO_SENSOR_39, RISING_EDGE  }
    ,{ IO_SENSOR_40, RISING_EDGE  }
    ,{ IO_SENSOR_41, RISING_EDGE  }
    ,{ IO_SENSOR_42, RISING_EDGE  }
    ,{ IO_SENSOR_43, RISING_EDGE  }
    ,{ IO_SENSOR_44, RISING_EDGE  }
    ,{ IO_SENSOR_45, RISING_EDGE  }
    ,{ IO_SENSOR_46, RISING_EDGE  }
    ,{ IO_SENSOR_47, RISING_EDGE  }
    ,{ IO_SENSOR_48, RISING_EDGE  }
    ,{ IO_SENSOR_49, RISING_EDGE  }
    ,{ IO_SENSOR_50, RISING_EDGE  }
    ,{ IO_SENSOR_51, RISING_EDGE  }
    ,{ IO_SENSOR_52, RISING_EDGE  }
    ,{ IO_SENSOR_53, RISING_EDGE  }
    ,{ IO_SENSOR_54, RISING_EDGE  }
    ,{ IO_SENSOR_55, RISING_EDGE  }
    ,{ IO_SENSOR_56, RISING_EDGE  }
    ,{ IO_SENSOR_57, RISING_EDGE  }
    ,{ IO_SENSOR_58, RISING_EDGE  }
    ,{ IO_SENSOR_59, RISING_EDGE  }
    ,{ IO_SENSOR_60, RISING_EDGE  }
    ,{ IO_SENSOR_61, RISING_EDGE  }
    ,{ IO_SENSOR_62, RISING_EDGE  }
    ,{ IO_SENSOR_63, RISING_EDGE  }
    ,{ IO_SENSOR_64, RISING_EDGE  }
    ,{ IO_SENSOR_65, RISING_EDGE  }
    ,{ IO_SENSOR_66, RISING_EDGE  }
    ,{ IO_SENSOR_67, RISING_EDGE  }
    ,{ IO_SENSOR_68, RISING_EDGE  }
    ,{ IO_SENSOR_69, RISING_EDGE  }
    ,{ IO_SENSOR_70, RISING_EDGE  }
    ,{ IO_SENSOR_71, RISING_EDGE  }
    ,{ IO_SENSOR_72, RISING_EDGE  }
    ,{ IO_SENSOR_73, RISING_EDGE  }
    ,{ IO_SENSOR_74, RISING_EDGE  }
    ,{ IO_SENSOR_75, RISING_EDGE  }
    ,{ IO_SENSOR_76, RISING_EDGE  }
    ,{ IO_SENSOR_77, RISING_EDGE  }
    ,{ IO_SENSOR_78, RISING_EDGE  }
    ,{ IO_SENSOR_79, RISING_EDGE  }
    ,{ IO_SENSOR_80, RISING_EDGE  }
    ,{ IO_SENSOR_81, RISING_EDGE  }
    ,{ IO_SENSOR_82, RISING_EDGE  }
    ,{ IO_SENSOR_83, RISING_EDGE  }
    ,{ IO_SENSOR_84, RISING_EDGE  }
    ,{ IO_SENSOR_85, RISING_EDGE  }
    ,{ IO_SENSOR_86, RISING_EDGE  }
    ,{ IO_SENSOR_87, RISING_EDGE  }
    ,{ IO_SENSOR_88, RISING_EDGE  }
    ,{ IO_SENSOR_89, RISING_EDGE  }
    ,{ IO_SENSOR_90, RISING_EDGE  }
    ,{ IO_SENSOR_91, RISING_EDGE  }
    ,{ IO_SENSOR_92, RISING_EDGE  }
    ,{ IO_SENSOR_93, RISING_EDGE  }
    ,{ IO_SENSOR_94, RISING_EDGE  }
    ,{ IO_SENSOR_97, RISING_EDGE  }
    ,{ IO_SENSOR_95, RISING_EDGE  }
    ,{ IO_SENSOR_96, RISING_EDGE  }
    ,{ IO_SENSOR_98, RISING_EDGE  }
    ,{ IO_SENSOR_99, FALLING_EDGE }
};

/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
/* Private function definitions ---------------------------------------- */
/* End of file -------------------------------------------------------- */
