#include "main.h"
#include <string.h>
#include "lora_send.h"

void lora_send(uint8_t * data_buff, size_t message_size, UART_HandleTypeDef * huart){
	size_t buff_size = message_size+TOT_SIZE;
	uint8_t send_buff[buff_size]; // has size of message and AT+SEND=xx,xx, and \r\n
	strcpy(send_buff, "AT+SEND=");
	sprintf(send_buff + AT_SEND_SIZE,"69,%d,",message_size);
	strcpy(send_buff + AT_SEND_SIZE + ADR_ID_SIZE, data_buff);
	sprintf(send_buff + AT_SEND_SIZE + ADR_ID_SIZE + message_size, "\r\n");
	HAL_UART_Transmit(huart, send_buff, message_size+TOT_SIZE, 10);
}
