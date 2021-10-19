
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
#include "platform.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
static can_mb_conf_t m_can1_mailbox;
static bsp_can_sensor_event_t m_sensor_event;
static uint8_t m_can_tx_data[8];
static uint8_t m_can_rx_data[8];

/* Private function prototypes ---------------------------------------- */
static void m_bsp_can_send_msg(bsp_can_msg_t msg);
static void m_bsp_can_transmit(uint8_t msg_id, uint8_t *p_data);
static void m_bsp_can_receive(uint8_t *msg_id, uint8_t *p_data);
static void m_bsp_can_pack_msg_sensor(uint8_t *can_data);
static void m_bsp_can_unpack_msg_sensor(uint8_t *can_data);

/* Function definitions ----------------------------------------------- */
void bsp_can_init(void)
{
  uint32_t ul_sysclk = sysclk_get_cpu_hz();

  pmc_enable_periph_clk(ID_CAN1);

  can_init(CAN1, ul_sysclk, CAN_BPS_250K);
  can_reset_all_mailbox(CAN1);

  m_can1_mailbox.ul_mb_idx   = 0;
  m_can1_mailbox.uc_tx_prio  = 15;
  m_can1_mailbox.uc_id_ver   = 0;
  m_can1_mailbox.uc_length   = 8;

#if (_CONFIG_ELEVATOR_BOARD) // {
  m_can1_mailbox.uc_obj_type = CAN_MB_TX_MODE;
  m_can1_mailbox.ul_id_msk   = 0;
#else // }{
  m_can1_mailbox.uc_obj_type = CAN_MB_RX_MODE;
  m_can1_mailbox.ul_id_msk   = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
  m_can1_mailbox.ul_id       = CAN_MID_MIDvA(0x07);
#endif // }

  can_mailbox_init(CAN1, &m_can1_mailbox);
}

bool_t bsp_can_is_available(void)
{
  return (can_mailbox_get_status(CAN1, 0) & CAN_MSR_MRDY);
}

void bsp_can_send_sensor_event(date_time_t *dt, uint8_t sensor_name)
{
  m_sensor_event.tm_year = dt->tm_year;
  m_sensor_event.tm_mon  = dt->tm_mon;
  m_sensor_event.tm_mday = dt->tm_mday;
  m_sensor_event.tm_hour = dt->tm_hour;
  m_sensor_event.tm_min  = dt->tm_min;
  m_sensor_event.tm_sec  = dt->tm_sec;
  m_sensor_event.sensor  = sensor_name;
  m_sensor_event.unused  = 0;

  m_bsp_can_send_msg(MSG_SENSOR);
}

void bsp_can_get_sensor_event(date_time_t *dt, uint8_t *sensor_name)
{
  uint8_t msg_id;

  m_bsp_can_receive(&msg_id, m_can_rx_data);

  m_bsp_can_unpack_msg_sensor(m_can_rx_data);

  dt->tm_year  = m_sensor_event.tm_year;
  dt->tm_mon   = m_sensor_event.tm_mon;
  dt->tm_mday  = m_sensor_event.tm_mday;
  dt->tm_hour  = m_sensor_event.tm_hour;
  dt->tm_min   = m_sensor_event.tm_min;
  dt->tm_sec   = m_sensor_event.tm_sec;
  *sensor_name = m_sensor_event.sensor;
}

/* Private function definitions --------------------------------------- */
static void m_bsp_can_send_msg(bsp_can_msg_t msg)
{
  uint8_t msg_id;

  switch (msg)
  {
  case MSG_SENSOR:
    msg_id = 0x07;
    m_bsp_can_pack_msg_sensor(m_can_tx_data);
    break;

  default:
    break;
  }

  m_bsp_can_transmit(msg_id, m_can_tx_data);
}

static void m_bsp_can_transmit(uint8_t msg_id, uint8_t *p_data)
{
  m_can1_mailbox.ul_id = CAN_MID_MIDvA(msg_id);
  memcpy((uint8_t *)&m_can1_mailbox.ul_datal, p_data, 4);
  memcpy((uint8_t *)&m_can1_mailbox.ul_datah, &p_data[4], 4);

  can_mailbox_write(CAN1, &m_can1_mailbox);

  can_global_send_transfer_cmd(CAN1, CAN_TCR_MB0);
}

static void m_bsp_can_receive(uint8_t *msg_id, uint8_t *p_data)
{
  can_mailbox_read(CAN1, &m_can1_mailbox);

  *msg_id = m_can1_mailbox.ul_id;
  memcpy(p_data, (uint8_t *)&m_can1_mailbox.ul_datal, 4);
  memcpy(&p_data[4], (uint8_t *)&m_can1_mailbox.ul_datah, 4);
}

static void m_bsp_can_pack_msg_sensor(uint8_t *can_data)
{
  can_data[0] = m_sensor_event.tm_year;
  can_data[1] = m_sensor_event.tm_mon;
  can_data[2] = m_sensor_event.tm_mday;
  can_data[3] = m_sensor_event.tm_hour;
  can_data[4] = m_sensor_event.tm_min;
  can_data[5] = m_sensor_event.tm_sec;
  can_data[6] = m_sensor_event.sensor;
  can_data[7] = m_sensor_event.unused;
}

static void m_bsp_can_unpack_msg_sensor(uint8_t *can_data)
{
  m_sensor_event.tm_year = can_data[0];
  m_sensor_event.tm_mon  = can_data[1];
  m_sensor_event.tm_mday = can_data[2];
  m_sensor_event.tm_hour = can_data[3];
  m_sensor_event.tm_min  = can_data[4];
  m_sensor_event.tm_sec  = can_data[5];
  m_sensor_event.sensor  = can_data[6];
  m_sensor_event.unused  = can_data[7];
}

/* End of file -------------------------------------------------------- */
