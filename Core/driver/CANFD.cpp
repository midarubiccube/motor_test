/*#include "CANFD.hpp"

//tx//////////////////////////////////////////////////////////////////////
bool CANFD::tx(CANFD_Frame &tx_data){
	  fdcan1TxHeader.Identifier = 0x1;
	  fdcan1TxHeader.IdType = FDCAN_STANDARD_ID;
	  fdcan1TxHeader.TxFrameType = FDCAN_DATA_FRAME;
	  fdcan1TxHeader.DataLength = FDCAN_DLC_BYTES_32;
	  fdcan1TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	  fdcan1TxHeader.BitRateSwitch = FDCAN_BRS_ON;
	  fdcan1TxHeader.FDFormat = FDCAN_FD_CAN;
	  fdcan1TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	  fdcan1TxHeader.MessageMarker = 0;

	  // Configure TX Header for FDCAN2
	  fdcan2TxHeader.Identifier = 0x2;
	  fdcan2TxHeader.IdType = FDCAN_STANDARD_ID;
	  fdcan2TxHeader.TxFrameType = FDCAN_DATA_FRAME;
	  fdcan2TxHeader.DataLength = FDCAN_DLC_BYTES_32;
	  fdcan2TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	  fdcan2TxHeader.BitRateSwitch = FDCAN_BRS_ON;
	  fdcan2TxHeader.FDFormat = FDCAN_FD_CAN;
	  fdcan2TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	  fdcan2TxHeader.MessageMarker = 0;

	  // Prepare first Tx data for fdcan1
	  for (int32_t i = 0; i < dataLen; i++) {
		  fdcan1TxData[i] = 1;
	  }

	  // Put Tx data to Txfifo
	  if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &fdcan1TxHeader, fdcan1TxData)!= HAL_OK) {
		  printf("HAL_FDCAN_AddMessageToTxFifoQ\r\n");
		  Error_Handler();
	  }
}

//rx//////////////////////////////////////////////////////////////////////////////////////////
uint32_t CANFD::rx_available(void){
	uint32_t count = 0;
	for(uint32_t i = 0; i < CAN_RX_BUFF_N;i++){
		if(!rx_buff[i].is_free) count ++;
	}
	return count;
}*/
/*void CANFD::rx_interrupt_task(void){
	CAN_RxHeaderTypeDef rx_header;

	HAL_CAN_GetRxMessage(can, rx_fifo, &rx_header, rx_buff[head].data);
	rx_buff[head].is_remote = (rx_header.RTR == CAN_RTR_DATA)? false : true;
	rx_buff[head].id = (rx_header.IDE == CAN_ID_STD)? rx_header.StdId : rx_header.ExtId;
	rx_buff[head].is_ext_id = (rx_header.IDE == CAN_ID_STD)? false : true;
	rx_buff[head].size = rx_header.DLC;
	rx_buff[head].is_free = false;

	head = (head+1)&CAN_RX_BUFF_AND;
}
bool CANFD::rx(CANFD_Frame &rx_frame){
	if(!rx_buff[tail].is_free){
		rx_frame = rx_buff[tail];
		rx_buff[tail].is_free = true;
		tail = (tail+1)&CAN_RX_BUFF_AND;
		return true;
	}else{
		return false;
	}
}

//filter///////////////////////////////////////////////////////////////////////////////////
void CANFD::set_filter_mask(uint32_t id,uint32_t mask,filter_mode mode,bool as_std){
	FDCAN_FilterTypeDef filter;
	uint32_t filter_id;
	uint32_t filter_mask;
	switch(mode){
	case filter_mode::only_std:
		if(as_std){
			filter_id = id << 21;
			filter_mask = mask << 21 | 0x4;
		}else{
			filter_id = id << 3;
			filter_mask = mask << 3 | 0x4;
		}
		break;
	case filter_mode::only_ext:
		if(as_std){
//			filter_id = id << 21 | 0x4;
			filter_mask = mask << 21 | 0x4;
		}else{
			filter_id = id << 3 | 0x4;
			filter_mask = mask << 3 | 0x4;
		}
		break;
	case filter_mode::std_and_ext:
		if(as_std){
			filter_id = id << 21;
			filter_mask = mask << 21;
		}else{
			filter_id = id << 3;
			filter_mask = mask << 3;
		}

	}

	filter.FilterIdHigh         = filter_id >> 16;
	filter.FilterIdLow          = filter_id;
	filter.FilterMaskIdHigh     = filter_mask >> 16;
	filter.FilterMaskIdLow      = filter_mask;
	filter.FilterScale          = CAN_FILTERSCALE_32BIT; // 32モード
	filter.FilterFIFOAssignment = rx_fifo;      // FIFO0へ格納
	filter.FilterBank           = 0;
	filter.FilterMode           = CAN_FILTERMODE_IDMASK; // IDマスクモード
	filter.SlaveStartFilterBank = 14;
	filter.FilterActivation     = ENABLE;

	HAL_FDCAN_ConfigGlobalFilter(can, &filter);
}
void CANFD::set_filter_free(void){
	FDCAN_FilterTypeDef filter;
	filter.FilterIdHigh         = 0;
	filter.FilterIdLow          = 0;
	filter.FilterMaskIdHigh     = 0;
	filter.FilterMaskIdLow      = 0;
	filter.FilterScale          = CAN_FILTERSCALE_32BIT;
	filter.FilterFIFOAssignment = rx_fifo;
	filter.FilterBank           = 0;
	filter.FilterMode           = CAN_FILTERMODE_IDMASK;
	filter.SlaveStartFilterBank = 14;
	filter.FilterActivation     = ENABLE;
	HAL_FDCAN_ConfigGlobalFilter(can, &filter);
}*/
