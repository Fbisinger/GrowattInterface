// GrowattInterface
// MIT License Copyright (c) 2023 F. Bisinger

// Example sketch of GrowattInterface Library

#include <GrowattInterface.h>
#include <SoftwareSerial.h>

#define MODBUS_RATE_GROWATT 9600  // Baud Rate
#define MAX485_DE 33              // GPIO33, DE pin on the TTL to RS485 converter
#define MAX485_RX 34              // GPIO34, RO pin on the TTL to RS485 converter
#define MAX485_TX 17              // GPIO17, DI pin on the TTL to RS485 converter
#define SLAVE_ID_GROWATT 3        // Configured slave ID of Growatt Inverter

// Serial communication to the RS485 converter via SoftwareSerial
// Harware Serial will work fine as well
SoftwareSerial *serial;

GrowattInterface interface;

void setup()
{
  serial = new SoftwareSerial(MAX485_RX, MAX485_TX, false); //RX, TX
  serial->begin(MODBUS_RATE_GROWATT); //Growatt Inverter uses 9600 bit/sec, 8 data bit, no parity bit, 1 stop bit
  interface.begin(*serial, SLAVE_ID_GROWATT, MAX485_DE);
}

void loop()
{
  interface.updateBuffer();
}