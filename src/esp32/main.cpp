#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    Serial.println("IoT Building Monitoring System");
    Serial.println("System starting...");
}

void loop()
{
    Serial.println("System running");

    delay(5000);
}