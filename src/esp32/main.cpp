#include <Arduino.h>
#include "data_handler.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("IoT Building Monitoring System");
}

void loop()
{
    // Temporary values until the DHT11 sensor is connected
    float temperature = 22.5;
    float humidity = 45.0;

    if (isSensorDataValid(temperature, humidity))
    {
        String jsonData = createSensorJson(temperature, humidity);
        Serial.println(jsonData);
    }
    else
    {
        Serial.println("ERROR: Invalid sensor data");
    }

    delay(5000);
}
