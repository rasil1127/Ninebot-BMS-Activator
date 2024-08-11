#include <Arduino.h>

// for Ninebot BMS activation

byte buf_30[] = {0x5A, 0xA5, 0x06, 0x20, 0x22, 0x30, 0x00, 0x00, 0x00, 0xB6, 0xFF};

void setup() {
  Serial.begin(115200, SERIAL_8N1, 16, 17);
  delay(100);
}

void loop() {
  // Calculate the checksum for the message
  uint16_t checksum = 0;
  for (int i = 2; i < 8; i++) {
    checksum += buf_30[i];
  }
  checksum ^= 0xFFFF;

  // Place the checksum in the buffer
  buf_30[8] = checksum & 0xFF;       // Lower byte of checksum
  buf_30[9] = (checksum >> 8) & 0xFF; // Upper byte of checksum

  // Send the message
  Serial.write(buf_30, sizeof(buf_30));

  // Wait and clear the buffer
  delay(10);
  while (Serial.available() > 0) Serial.read();
  delay(200);
}
