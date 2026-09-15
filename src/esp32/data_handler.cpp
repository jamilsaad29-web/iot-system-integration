#include "data_handler.h"

bool isSensorDataValid(float temperature, float humidity)
{
    if (temperature < -40 || temperature > 80)
    {
        return false;
    }

    if (humidity < 0 || humidity > 100)
    {
        return false;
    }

    return true;
}

String createSensorJson(float temperature, float humidity)
{
    String json = "{";
    json += "\"sensorId\":\"room-a-dht11-01\",";
    json += "\"temperature\":" + String(temperature, 1) + ",";
    json += "\"humidity\":" + String(humidity, 1) + ",";
    json += "\"temperatureUnit\":\"C\",";
    json += "\"humidityUnit\":\"%\"";
    json += "}";

    return json;
}
