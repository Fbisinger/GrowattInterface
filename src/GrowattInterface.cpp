// GrowattInterface
// MIT License Copyright (c) 2023 F. Bisinger

#include "Arduino.h"
#include "GrowattInterface.h"
#include "ModbusMaster.h"

ModbusMaster modbus;

GrowattInterface::GrowattInterface()
{
  
}

void GrowattInterface::begin(SoftwareSerial serial, int id, int pinDE)
{
  _pinDE = pinDE;
  modbus.begin(id, *serial);
  modbus.preTransmission(preTransmission);
  modbus.postTransmission(postTransmission);
}

/*
Reads Modbus Input registers and updates internal buffer 
*/
bool GrowattInterface::updateBuffer()
{
  return true;
}

float GrowattInterface::getSolarPower()
{
  return 0.0f;
}

float GrowattInterface::getPv1Voltage()
{
  return 0.0f;
}

float GrowattInterface::getPv1Current()
{
  return 0.0f;
}

float GrowattInterface::getPv1Power()
{
  return 0.0f;
}

float GrowattInterface::getOutpuPower()
{
  return 0.0f;
}

float GrowattInterface::getGridFrequency()
{
  return 0.0f;
}

float GrowattInterface::getGridVoltage()
{
  return 0.0f;
}

float GrowattInterface::getEnergyToday()
{
  return 0.0f;
}

float GrowattInterface::getEnergyTotal()
{
  return 0.0f;
}

float GrowattInterface::getTotalWorktime()
{
  return 0.0f;
}

void GrowattInterface::preTransmission()
{
  digitalWrite(_pinDE, 1);
}

void GrowattInterface::postTransmission()
{
  digitalWrite(_pinDE, 0);
}

int GrowattInterface::getStatus()
{
  return 
}

void GrowattInterface::setMbTimeout(int timeout)
{
  _mbTimeout = timeout;
}
