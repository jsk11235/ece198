#define AT_SEND_SIZE 8
#define ADR_ID_SIZE 6
#define TERM_SIZE 2
#define TOT_SIZE AT_SEND_SIZE+ADR_ID_SIZE+TERM_SIZE

void lora_send(uint8_t * data_buff, size_t message_size, UART_HandleTypeDef * huart);
