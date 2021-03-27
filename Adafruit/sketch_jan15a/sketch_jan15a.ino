#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BLEGatt.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "BluefruitConfig.h"
#include <Servo.h>


Servo  xServo;
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
Adafruit_BLEGatt gatt(ble);
uint8_t pastNum;
uint8_t charID;
const int xServoPin = 7;

void setup() {
  uint8_t serviceUUID[] = {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11};
  uint8_t charUUID[] = {22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22};
  ble.reset(true); 
  gatt.addService(serviceUUID);
  charID = gatt.addCharacteristic(charUUID, 0x04,0,20,BLE_DATATYPE_INTEGER);
  xServo.attach(xServoPin);
}

void loop() {
  if(gatt.getChar(charID) != pastNum){
     xServo.write(gatt.getChar(charID));
     pastNum = gatt.getChar(charID);
     delay(15);
  }

}
