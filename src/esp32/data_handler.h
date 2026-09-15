#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <Arduino.h>

bool isSensorDataValid(float temperature, float humidity);

String createSensorJson(float temperature, float humidity);

#endif
