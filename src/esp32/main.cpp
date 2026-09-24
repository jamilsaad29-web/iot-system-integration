#include <Arduino.h>

#include "data_handler.h"
#include "wifi_manager.h"
#include "mqtt_manager.h"

void setup()
{
    Serial.begin(115200);

    Serial.println("IoT Building Monitoring System");
    Serial.println("System starting...");

    if (connectToWiFi())
    {
        connectToMQTT();
    }
}

void loop()
{
    mqttLoop();

    // Reconnect WiFi if connection is lost
    if (!isWiFiConnected())
    {
        Serial.println("WARNING: WiFi disconnected");
        connectToWiFi();
    }

    // Reconnect MQTT if connection is lost
    if (isWiFiConnected() && !isMQTTConnected())
    {
        Serial.println("WARNING: MQTT disconnected");
        connectToMQTT();
    }

    // Temporary values until the DHT11 sensor is connected
    float temperature = 22.5;
    float humidity = 45.0;

    if (isSensorDataValid(temperature, humidity))
    {
        String jsonData = createSensorJson(temperature, humidity);

        Serial.println("Sensor data valid");
        Serial.println(jsonData);

        if (isMQTTConnected())
        {
            publishSensorData(jsonData);
        }
    }
    else
    {
        Serial.println("ERROR: Invalid sensor data");
    }

    Serial.print("Published messages: ");
    Serial.println(getPublishedMessageCount());

    Serial.print("MQTT errors: ");
    Serial.println(getMQTTErrorCount());

    delay(5000);
}
