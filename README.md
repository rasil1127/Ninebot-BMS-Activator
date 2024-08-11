# Ninebot-BMS-Activator
Use an ESP32 or STM32 to send commands to the Ninebot BMS and remove the 19A current restriction.
### ESP32
UART 2 is chosen and is assigned to GPIO 17 and GPIO 16. Connect the yellow wire to GPIO 17 and the white wire to GPIO 16. Remember to connect the GND as well. You can power the ESP32 using the battery with a buck converter, but be sure to include a switch to prevent the battery from draining when not in use.
Build project using VScode and platformio 
### STM32
Additional setup is needed, such as configuring the .IOC file. In the STM32 code example, HUART1 is chosen @ 115200 BPS. 
Build project using STM32cubeIDE in C
