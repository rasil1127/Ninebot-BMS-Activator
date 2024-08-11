// for Ninebot BMS activation

// activation message buffer
uint8_t buf_30[] = {0x5A, 0xA5, 0x06, 0x20, 0x22, 0x30, 0x00, 0x00, 0x00, 0xB6, 0xFF};



int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART1_UART_Init();

  while (1) {
    // Calculate the checksum for the message
    uint16_t checksum = 0;
    for (int i = 2; i < 8; i++) {
      checksum += buf_30[i];
    }
    checksum ^= 0xFFFF;

    // Place the checksum in the buffer
    buf_30[8] = checksum & 0xFF;       // Lower byte of checksum
    buf_30[9] = (checksum >> 8) & 0xFF; // Upper byte of checksum

    // Send the message via UART
    HAL_UART_Transmit(&huart1, buf_30, sizeof(buf_30), HAL_MAX_DELAY);

    // Wait and clear the buffer
    HAL_Delay(10);
    uint8_t dummy;
    while (HAL_UART_Receive(&huart1, &dummy, 1, 10) == HAL_OK);

    HAL_Delay(200);
  }
}