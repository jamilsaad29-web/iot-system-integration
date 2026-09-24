#include "mqtt_manager.h"

#include <WiFi.h>
#include <PubSubClient.h>

const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "iot/building/room-a/environment";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

unsigned long publishedMessageCount = 0;
unsigned long mqttErrorCount = 0;

bool connectToMQTT()
{
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);

    Serial.println("Connecting to MQTT broker...");

    String clientId = "ESP32-BuildingMonitor-";
    clientId += String(random(0xffff), HEX);

    if (mqttClient.connect(clientId.c_str()))
    {
        Serial.println("MQTT connected");
        return true;
    }

    mqttErrorCount++;

    Serial.print("ERROR: MQTT connection failed. State: ");
    Serial.println(mqttClient.state());

    return false;
}

bool isMQTTConnected()
{
    return mqttClient.connected();
}

bool publishSensorData(const String& jsonData)
{
    if (!mqttClient.connected())
    {
        Serial.println("ERROR: Cannot publish - MQTT not connected");
        mqttErrorCount++;
        return false;
    }

    bool success = mqttClient.publish(
        MQTT_TOPIC,
        jsonData.c_str()
    );

    if (success)
    {
        publishedMessageCount++;

        Serial.print("MQTT message published: ");
        Serial.println(jsonData);

        return true;
    }

    mqttErrorCount++;

    Serial.println("ERROR: MQTT publish failed");

    return false;
}

void mqttLoop()
{
    mqttClient.loop();
}

unsigned long getPublishedMessageCount()
{
    return publishedMessageCount;
}

unsigned long getMQTTErrorCount()
{
    return mqttErrorCount;
}
