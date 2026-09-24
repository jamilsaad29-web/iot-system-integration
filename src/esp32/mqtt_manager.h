#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H

#include <Arduino.h>

bool connectToMQTT();
bool isMQTTConnected();
bool publishSensorData(const String& jsonData);
void mqttLoop();

unsigned long getPublishedMessageCount();
unsigned long getMQTTErrorCount();

#endif
