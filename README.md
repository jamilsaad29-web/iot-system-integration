# Secure and Integrated IoT Solution

## Project Overview

This project implements a network-based IoT solution for monitoring
environmental conditions inside a building.

A physical DHT11 sensor connected to an ESP32-WROOM-32E measures
temperature and humidity. The ESP32 connects to Wi-Fi and sends the
sensor measurements using MQTT.

Sensor data is transferred in JSON format and made available to other
systems through a REST API.

The solution also includes security measures, logging, monitoring and
error handling.

## System Architecture

The basic data flow is:

DHT11 Sensor
      |
      v
ESP32-WROOM-32E
      |
      | Wi-Fi / MQTT / JSON
      v
MQTT Broker
      |
      v
Processing / API
      |
      | HTTP REST
      v
Client

More information is available in:

`docs/architecture.md`

## Hardware

The project uses:

- ESP32-WROOM-32E
- DHT11 temperature and humidity sensor
- Breadboard
- Jumper wires
- USB cable
- Wi-Fi connection

## Software

The ESP32 application is developed using:

- C++
- Arduino framework
- PlatformIO
- Visual Studio Code

Additional software and libraries will be documented when the complete
system has been implemented.

## Network Communication

MQTT is used for communication between the ESP32 and the MQTT broker.

MQTT is suitable for IoT systems because it is lightweight and uses a
publish/subscribe communication model.

Planned MQTT topic:

`iot/building/room-a/environment`

The exact broker hostname, port and security configuration will be added
after the MQTT connection has been implemented and tested.

## Data Format

Sensor measurements are transferred using JSON.

Example:

{
  "sensorId": "room-a-dht11-01",
  "temperature": 22.4,
  "humidity": 48,
  "temperatureUnit": "C",
  "humidityUnit": "%"
}

## API

The latest sensor data will be available through a REST API.

Planned endpoint:

`GET /api/sensors/latest`

More information is available in:

`docs/api.md`

## Security

The solution includes security measures such as:

- Encrypted network communication where supported
- Secure handling of passwords and credentials
- Input and sensor value validation
- Sensitive configuration excluded from Git version control

More information is available in:

`docs/security.md`

## Logging and Monitoring

The system will log important events such as:

- Wi-Fi connection and reconnection
- MQTT connection and reconnection
- Sensor readings
- Published MQTT messages
- Invalid sensor values
- Communication errors
- API requests and errors

At least one monitoring metric will also be implemented, for example:

- Number of successfully published MQTT messages
- Number of communication errors
- Time of the latest sensor measurement

## Error Testing

Two errors will intentionally be introduced and analyzed:

1. Incorrect MQTT broker address
2. Unrealistic sensor value

The observed symptoms, cause, troubleshooting process, solution and
verification will be documented after testing.

More information is available in:

`docs/troubleshooting.md`

## Installation

### Requirements

Before running the ESP32 application, install:

- Visual Studio Code
- PlatformIO IDE extension
- USB driver for the ESP32 if required

### ESP32 Setup

1. Connect the DHT11 sensor to the ESP32-WROOM-32E.
2. Connect the ESP32 to the computer using USB.
3. Open the project in Visual Studio Code.
4. Open PlatformIO.
5. Configure the required Wi-Fi and MQTT settings.
6. Build the project.
7. Upload the application to the ESP32.
8. Open the Serial Monitor to view logs.

Exact pin connections and configuration will be added after the physical
hardware has been connected and tested.

## Configuration

Sensitive information such as Wi-Fi passwords must not be committed to
GitHub.

Configuration that may be required includes:

- Wi-Fi SSID
- Wi-Fi password
- MQTT broker hostname
- MQTT port
- MQTT credentials if authentication is used

Example configuration should use placeholder values instead of real
credentials.

## Running the System

When the implementation is complete, the normal startup process will be:

1. Start the required MQTT/API services.
2. Connect and start the ESP32.
3. Verify the Wi-Fi connection in the Serial Monitor.
4. Verify the MQTT broker connection.
5. Verify that sensor measurements are being published.
6. Request the latest measurement through the API.

## Verifying the Data Flow

The complete data flow will be verified by checking that:

1. The DHT11 produces a physical temperature and humidity measurement.
2. The ESP32 reads the measurement.
3. Valid JSON is generated.
4. The JSON message is published to the MQTT broker.
5. The message is received and processed.
6. The latest measurement can be retrieved through the API.
7. Relevant events are visible in the logs.

## Known Limitations

The current solution has several limitations:

- DHT11 has limited measurement accuracy compared with more advanced sensors.
- The system depends on Wi-Fi connectivity.
- The system depends on availability of the MQTT broker.
- The ESP32 has limited processing power and memory.
- The current system is intended as a small educational IoT solution rather
  than a production deployment.

Additional limitations and possible improvements will be documented during
development.

## Project Structure

systemintegration/
├── docs/
│   ├── api.md
│   ├── architecture.md
│   ├── security.md
│   └── troubleshooting.md
├── src/
│   ├── esp32/
│   │   └── main.cpp
│   └── server/
├── tests/
├── .gitignore
└── README.md
