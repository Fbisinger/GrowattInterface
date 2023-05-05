// GrowattInterface
// MIT License Copyright (c) 2023 F. Bisinger

#ifndef GrowattInterface_h
#define GrowattInterface_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class GrowattInterface
{
  public:
    GrowattInterface();
    void begin(SoftwareSerial serial, int id, int pinDE);
    bool updateBuffer();
    float getSolarPower();    //Currently same result as pv1power
    float getPv1Voltage(); 	  //currently only support for inverters with one mpp tracker
    float getPv1Current();
    float getPv1Power();
    float getOutpuPower();
    float getGridFrequency(); //Currently only one phase inverter supported
    float getGridVoltage();
    float getEnergyToday();
    float getEnergyTotal();
    float getTotalWorktime();
    
    int getStatus();

    void setMbTimeout(int timeout);

  private:
    void preTransmission();
    void postTransmission()
    
    int _slaveID;
    int _mbSpeed;
    int _mbTimeout;
    int _pinDE;

    struct modbus_input_registers_growatt
    {
      int status;
      float solarpower, pv1voltage, pv1current, pv1power, outputpower, gridfrequency, gridvoltage;
      float energytoday, energytotal, totalworktime;
    };
    
};

#endif