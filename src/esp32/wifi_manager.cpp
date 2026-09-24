#include "wifi_manager.h"
#include <WiFi.h>
#include "secrets.h"

bool connectToWiFi()
{
    Serial.println("Connecting to WiFi...");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    const int maxAttempts = 20;

    while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts)
    {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println();
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());

        return true;
    }

    Serial.println();
    Serial.println("ERROR: WiFi connection failed");

    return false;
}

bool isWiFiConnected()
{
    return WiFi.status() == WL_CONNECTED;
}
