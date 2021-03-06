#ifndef HYDROMONITORGROWINGPARAMETERS_H
#define HYDROMONITORGROWINGPARAMETERS_H

#include <HydroMonitorCore.h>
#include <HydroMonitorMySQL.h>

class HydroMonitorGrowingParameters {

  public:
  
    struct Settings {
      char systemName[64];
      uint16_t solutionVolume;
      uint16_t fertiliserConcentration;
      float targetEC;
      float pHMinusConcentration;
      float targetpH;
      float timezone;
    };

    // Constructor.    
    HydroMonitorGrowingParameters(void);

    // The various functions to set up and control this module.
    void begin(HydroMonitorCore::SensorData*, HydroMonitorMySQL*);
    String settingsHtml(void);    
    void updateSettings(String[], String[], uint8_t);
    
    // The getters. Variables are set in updateSettings.
    uint16_t getSolutionVolume(void);
    float getTargetEC(void);
    uint16_t getFertiliserConcentration(void);
    float getpHMinusConcentration(void);
    float getTargetpH(void);
    
  private:
    void updateSensorData(void);
    Settings settings;
    HydroMonitorCore core;
    HydroMonitorCore::SensorData *sensorData;
    HydroMonitorMySQL *logging;
};

#endif
