
/**
 * @file       bsp_can.c
 * @copyright  Copyright (C) 2020 Hydratech. All rights reserved.
 * @license    This project is released under the Hydratech License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Board Support Package for CAN BUS
 * @note       None
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_can.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
can_mb_conf_t m_can1_mailbox;

/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_can_init(void)
{
  uint32_t ul_sysclk = sysclk_get_cpu_hz();

  pmc_enable_periph_clk(ID_CAN1);

  can_init(CAN1, ul_sysclk, CAN_BPS_250K);
  can_reset_all_mailbox(CAN1);

  m_can1_mailbox.ul_mb_idx   = 0;
  m_can1_mailbox.uc_obj_type = CAN_MB_TX_MODE;
  m_can1_mailbox.uc_tx_prio  = 15;
  m_can1_mailbox.uc_id_ver   = 0;
  m_can1_mailbox.ul_id_msk   = 0;
  can_mailbox_init(CAN1, &m_can1_mailbox);
  
  m_can1_mailbox.ul_id     = CAN_MID_MIDvA(0x07);
  m_can1_mailbox.ul_datal  = 0x12345678;
  m_can1_mailbox.ul_datah  = 0x87654321;
  m_can1_mailbox.uc_length = 8;
  can_mailbox_write(CAN1, &m_can1_mailbox);
}

void bsp_can_send(void)
{
  can_global_send_transfer_cmd(CAN1, CAN_TCR_MB0);
}

/* Private function definitions --------------------------------------- */
/* End of file -------------------------------------------------------- */
