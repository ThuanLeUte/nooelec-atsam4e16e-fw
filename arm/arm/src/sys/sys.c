/**
 * @file       sys.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-09-25
 * @author     Thuan Le
 * @brief      System file
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include <string.h>
#include <asf.h>
#include "sys.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
void SetupPeripherals(void); //Initialize MCU Peripherals
void WaitForSDCard(void);    //Waits until SD Card is inserted

/* Function definitions ----------------------------------------------- */
void sys_init(void)
{
  FATFS fs;    //File system variable
  FIL fhandle; //File handle variable
  char buf[25];

  //Test file name (note 0: indicates volume 0)
  const char test_file_name[] = "0:sam_arm_sd.txt";

  //Initialize System Clock
  sysclk_init();

  //Peripheral Setup
  SetupPeripherals();

  //Wait for SD Card Inserted
  WaitForSDCard();

  //Mount the file system
  memset(&fs, 0, sizeof(FATFS)); //initially clear it
  if (f_mount(LUN_ID_SD_MMC_0_MEM, &fs) != FR_OK)
  {
    return; //failed
  }

  //Open a file
  if (f_open(&fhandle, test_file_name, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
  {
    //File opened successfully, read card capacity
    uint32_t cap = sd_mmc_get_capacity(0);
    sprintf(buf, "Capacity: %lu\n", cap);
    //Write capacity to file
    if (f_puts(buf, &fhandle) != 0) //# chars written
    {
      pio_set_pin_low(PIO_PA20_IDX); //success LED
    }

    //Close the file (important!!)
    f_close(&fhandle);
  }

  //Nothing else to do
  while (1)
    ;
}

void sys_run(void)
{

}

/* Private function definitions --------------------------------------- */

//Waits until SD Card is inserted
void WaitForSDCard(void)
{
  Ctrl_status status;

  //Wait until SD stack initialized and SD card inserted
  do
  {
    //Check if stack ready
    status = sd_mmc_test_unit_ready(0);
    if (status == CTRL_FAIL)
    {
      //Wait for a card to be inserted
      while (sd_mmc_check(0) != CTRL_NO_PRESENT)
      {
        //Use a timeout here for real projects.
      }
    }
  } while (status != CTRL_GOOD);
}

//Initialize MCU Peripherals
void SetupPeripherals(void)
{
  //Disable watchdog timer
	board_init();

  //Enable PIOA clock to detect Card Detect (CD) change
  sysclk_enable_peripheral_clock(ID_PIOA);

  //Configure SD card pins as per MCI peripheral (periph C)
  pio_set_peripheral(PIOA, PIO_PERIPH_C, PIO_PA30C_MCDA0 |     //MCI Data 0
                                             PIO_PA31C_MCDA1 | //MCI Data 1
                                             PIO_PA26C_MCDA2 | //MCI Data 2
                                             PIO_PA27C_MCDA3 | //MCI Data 3
                                             PIO_PA28C_MCCDA | //MCI Command
                                             PIO_PA29C_MCCK);  //MCI Clock
  //SD Card Detect Pin (active low)
  pio_set_input(PIOA, PIO_PA6, PIO_INPUT | PIO_PULLUP);

  //Configure LEDs for status update
  pio_set_output(PIOA, PIO_PA19, PIO_TYPE_PIO_OUTPUT_0, PIO_DEFAULT, PIO_DEFAULT);
  pio_set_output(PIOA, PIO_PA20, PIO_TYPE_PIO_OUTPUT_0, PIO_DEFAULT, PIO_DEFAULT);

  //Initialize SD MMC stack
  sd_mmc_init();
}

/* End of file -------------------------------------------------------- */
