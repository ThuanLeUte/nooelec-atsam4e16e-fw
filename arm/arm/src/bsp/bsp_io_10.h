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

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_IO_10_H
#define __BSP_IO_10_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <asf.h>

/* Public defines ----------------------------------------------------- */
                                    // Schematic
// PIN NAME PORT 0 ``````````````````````````````
#define IO_SENSOR_0         NULL, 0      , 0       , 0
#define IO_SENSOR_1         PIOB, ID_PIOB, PIO_PB14, PIO_PB14_IDX
#define IO_SENSOR_2         PIOB, ID_PIOB, PIO_PB13, PIO_PB13_IDX
#define IO_SENSOR_3         PIOD, ID_PIOD, PIO_PD0,  PIO_PD0_IDX
#define IO_SENSOR_4         PIOD, ID_PIOD, PIO_PD31, PIO_PD31_IDX
#define IO_SENSOR_5         PIOE, ID_PIOE, PIO_PE3,  PIO_PE3_IDX
#define IO_SENSOR_6         PIOE, ID_PIOE, PIO_PE0,  PIO_PE0_IDX
#define IO_SENSOR_7         PIOE, ID_PIOE, PIO_PE1,  PIO_PE1_IDX
#define IO_SENSOR_8         PIOE, ID_PIOE, PIO_PE2,  PIO_PE2_IDX
#define IO_SENSOR_9         PIOC, ID_PIOC, PIO_PC27, PIO_PC27_IDX
#define IO_SENSOR_10        PIOC, ID_PIOC, PIO_PC0,  PIO_PC0_IDX
#define IO_SENSOR_11        PIOC, ID_PIOC, PIO_PC26, PIO_PC26_IDX
#define IO_SENSOR_12        PIOC, ID_PIOC, PIO_PC31, PIO_PC31_IDX
#define IO_SENSOR_13        PIOC, ID_PIOC, PIO_PC30, PIO_PC30_IDX
#define IO_SENSOR_14        PIOC, ID_PIOC, PIO_PC29, PIO_PC29_IDX
#define IO_SENSOR_15        PIOC, ID_PIOC, PIO_PC13, PIO_PC13_IDX
#define IO_SENSOR_16        PIOB, ID_PIOB, PIO_PB0,  PIO_PB0_IDX
#define IO_SENSOR_17        PIOB, ID_PIOB, PIO_PB1,  PIO_PB1_IDX
#define IO_SENSOR_18        PIOA, ID_PIOA, PIO_PA20, PIO_PA20_IDX
#define IO_SENSOR_19        PIOA, ID_PIOA, PIO_PA17, PIO_PA17_IDX
#define IO_SENSOR_20        PIOE, ID_PIOE, PIO_PE4,  PIO_PE4_IDX
#define IO_SENSOR_21        PIOA, ID_PIOA, PIO_PA19, PIO_PA19_IDX
#define IO_SENSOR_22        PIOE, ID_PIOE, PIO_PE5,  PIO_PE5_IDX
#define IO_SENSOR_23        PIOB, ID_PIOB, PIO_PB2,  PIO_PB2_IDX
#define IO_SENSOR_24        PIOA, ID_PIOA, PIO_PA18, PIO_PA18_IDX
#define IO_SENSOR_25        PIOA, ID_PIOA, PIO_PA21, PIO_PA21_IDX
#define IO_SENSOR_26        PIOB, ID_PIOB, PIO_PB3,  PIO_PB3_IDX
#define IO_SENSOR_27        PIOD, ID_PIOD, PIO_PD26, PIO_PD26_IDX
#define IO_SENSOR_28        PIOD, ID_PIOD, PIO_PD30, PIO_PD30_IDX
#define IO_SENSOR_29        PIOA, ID_PIOA, PIO_PA23, PIO_PA23_IDX
#define IO_SENSOR_30        PIOA, ID_PIOA, PIO_PA14, PIO_PA14_IDX
#define IO_SENSOR_31        PIOD, ID_PIOD, PIO_PD21, PIO_PD21_IDX
#define IO_SENSOR_32        PIOD, ID_PIOD, PIO_PD25, PIO_PD25_IDX
#define IO_SENSOR_33        PIOA, ID_PIOA, PIO_PA16, PIO_PA16_IDX
#define IO_SENSOR_34        PIOD, ID_PIOD, PIO_PD20, PIO_PD20_IDX
#define IO_SENSOR_35        PIOA, ID_PIOA, PIO_PA15, PIO_PA15_IDX
#define IO_SENSOR_36        PIOC, ID_PIOC, PIO_PC7,  PIO_PC7_IDX
#define IO_SENSOR_37        PIOD, ID_PIOD, PIO_PD27, PIO_PD27_IDX
#define IO_SENSOR_38        PIOA, ID_PIOA, PIO_PA22, PIO_PA22_IDX
#define IO_SENSOR_39        PIOC, ID_PIOC, PIO_PC1,  PIO_PC1_IDX
#define IO_SENSOR_40        PIOC, ID_PIOC, PIO_PC2,  PIO_PC2_IDX
#define IO_SENSOR_41        PIOC, ID_PIOC, PIO_PC3,  PIO_PC3_IDX
#define IO_SENSOR_42        PIOC, ID_PIOC, PIO_PC4,  PIO_PC4_IDX
#define IO_SENSOR_43        PIOA, ID_PIOA, PIO_PA13, PIO_PA13_IDX
#define IO_SENSOR_44        PIOC, ID_PIOC, PIO_PC5,  PIO_PC5_IDX
#define IO_SENSOR_45        PIOC, ID_PIOC, PIO_PC6,  PIO_PC6_IDX
#define IO_SENSOR_46        PIOD, ID_PIOD, PIO_PD24, PIO_PD24_IDX
#define IO_SENSOR_47        PIOA, ID_PIOA, PIO_PA24, PIO_PA24_IDX
#define IO_SENSOR_48        PIOD, ID_PIOD, PIO_PD23, PIO_PD23_IDX
#define IO_SENSOR_49        PIOA, ID_PIOA, PIO_PA25, PIO_PA25_IDX
#define IO_SENSOR_50        PIOD, ID_PIOD, PIO_PD22, PIO_PD22_IDX
#define IO_SENSOR_51        PIOD, ID_PIOD, PIO_PD19, PIO_PD19_IDX
#define IO_SENSOR_52        PIOA, ID_PIOA, PIO_PA12, PIO_PA12_IDX
#define IO_SENSOR_53        PIOD, ID_PIOD, PIO_PD18, PIO_PD18_IDX
#define IO_SENSOR_54        PIOA, ID_PIOA, PIO_PA11, PIO_PA11_IDX
#define IO_SENSOR_55        PIOD, ID_PIOD, PIO_PD13, PIO_PD13_IDX
#define IO_SENSOR_56        PIOC, ID_PIOC, PIO_PC9,  PIO_PC9_IDX
#define IO_SENSOR_57        PIOD, ID_PIOD, PIO_PD14, PIO_PD14_IDX
#define IO_SENSOR_58        PIOD, ID_PIOD, PIO_PD28, PIO_PD28_IDX
#define IO_SENSOR_59        PIOC, ID_PIOC, PIO_PC28, PIO_PC28_IDX
#define IO_SENSOR_60        PIOB, ID_PIOB, PIO_PB6,  PIO_PB6_IDX
#define IO_SENSOR_61        PIOA, ID_PIOA, PIO_PA5,  PIO_PA5_IDX
#define IO_SENSOR_62        PIOD, ID_PIOD, PIO_PD17, PIO_PD17_IDX
#define IO_SENSOR_63        PIOD, ID_PIOD, PIO_PD16, PIO_PD16_IDX
#define IO_SENSOR_64        PIOC, ID_PIOC, PIO_PC8,  PIO_PC8_IDX
#define IO_SENSOR_65        PIOD, ID_PIOD, PIO_PD12, PIO_PD12_IDX
#define IO_SENSOR_66        PIOC, ID_PIOC, PIO_PC11, PIO_PC11_IDX
#define IO_SENSOR_67        PIOA, ID_PIOA, PIO_PA2,  PIO_PA2_IDX
#define IO_SENSOR_68        PIOB, ID_PIOB, PIO_PB12, PIO_PB12_IDX
#define IO_SENSOR_69        PIOC, ID_PIOC, PIO_PC14, PIO_PC14_IDX
#define IO_SENSOR_70        PIOD, ID_PIOD, PIO_PD7,  PIO_PD7_IDX
#define IO_SENSOR_71        PIOB, ID_PIOB, PIO_PB7,  PIO_PB7_IDX
#define IO_SENSOR_72        PIOC, ID_PIOC, PIO_PC10, PIO_PC10_IDX
#define IO_SENSOR_73        PIOD, ID_PIOD, PIO_PD11, PIO_PD11_IDX
#define IO_SENSOR_74        PIOA, ID_PIOA, PIO_PA1,  PIO_PA1_IDX
#define IO_SENSOR_75        PIOC, ID_PIOC, PIO_PC16, PIO_PC16_IDX
#define IO_SENSOR_76        PIOD, ID_PIOD, PIO_PD10, PIO_PD10_IDX
#define IO_SENSOR_77        PIOA, ID_PIOA, PIO_PA0,  PIO_PA0_IDX
#define IO_SENSOR_78        PIOC, ID_PIOC, PIO_PC17, PIO_PC17_IDX
#define IO_SENSOR_79        PIOC, ID_PIOC, PIO_PC19, PIO_PC19_IDX
#define IO_SENSOR_80        PIOB, ID_PIOB, PIO_PB4,  PIO_PB4_IDX
#define IO_SENSOR_81        PIOD, ID_PIOD, PIO_PD15, PIO_PD15_IDX
#define IO_SENSOR_82        PIOD, ID_PIOD, PIO_PD29, PIO_PD29_IDX
#define IO_SENSOR_83        PIOB, ID_PIOB, PIO_PB5,  PIO_PB5_IDX
#define IO_SENSOR_84        PIOD, ID_PIOD, PIO_PD9,  PIO_PD9_IDX
#define IO_SENSOR_85        PIOC, ID_PIOC, PIO_PC18, PIO_PC18_IDX
#define IO_SENSOR_86        PIOD, ID_PIOD, PIO_PD8,  PIO_PD8_IDX
#define IO_SENSOR_87        PIOA, ID_PIOA, PIO_PA6,  PIO_PA6_IDX
#define IO_SENSOR_88        PIOC, ID_PIOC, PIO_PC20, PIO_PC20_IDX
#define IO_SENSOR_89        PIOC, ID_PIOC, PIO_PC22, PIO_PC22_IDX
#define IO_SENSOR_90        PIOD, ID_PIOD, PIO_PD6,  PIO_PD6_IDX
#define IO_SENSOR_91        PIOC, ID_PIOC, PIO_PC21, PIO_PC21_IDX
#define IO_SENSOR_92        PIOC, ID_PIOC, PIO_PC24, PIO_PC24_IDX
#define IO_SENSOR_93        PIOD, ID_PIOD, PIO_PD5,  PIO_PD5_IDX
#define IO_SENSOR_94        PIOD, ID_PIOD, PIO_PD4,  PIO_PD4_IDX
#define IO_SENSOR_95        PIOC, ID_PIOC, PIO_PC23, PIO_PC23_IDX
#define IO_SENSOR_96        PIOD, ID_PIOD, PIO_PD2,  PIO_PD2_IDX
#define IO_SENSOR_97        PIOD, ID_PIOD, PIO_PD3,  PIO_PD3_IDX
#define IO_SENSOR_98        PIOD, ID_PIOD, PIO_PD1,  PIO_PD1_IDX
#define IO_SENSOR_99        PIOC, ID_PIOC, PIO_PC25, PIO_PC25_IDX

/* Public enumerate/structure ----------------------------------------- */
typedef enum
{
   FALLING_EDGE = 0
  ,RISING_EDGE
}
bsp_io_trigger_t;

typedef struct
{
  Pio *port;
  uint32_t port_id;
  uint32_t pin;
  uint32_t pin_index;
  bsp_io_trigger_t trigger_edge;
}
bsp_io_10_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
extern const bsp_io_10_t IO_SENSOR[];
extern volatile bool IO_SENSOR_STATE[];

/* Public function prototypes ----------------------------------------- */
/* -------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_IO_10_H

/* End of file -------------------------------------------------------- */
