# System Architecture

## Overview

The system is designed to collect environmental data from a physical sensor
connected to an ESP32 and transfer the data over a network.

The main components are:

- DHT11 temperature and humidity sensor
- ESP32-WROOM-32E
- Wi-Fi network
- MQTT broker
- API
- Client

## Architecture Diagram

DHT11 Sensor
      |
      | Temperature / Humidity
      v
ESP32-WROOM-32E
      |
      | Wi-Fi
      | MQTT
      | JSON
      v
MQTT Broker
      |
      | Sensor data
      v
Processing / API
      |
      | HTTP REST
      v
Client

## Components

### DHT11 Sensor

The DHT11 is the physical sensor used by the system.
It measures temperature and relative humidity.

### ESP32-WROOM-32E

The ESP32 reads data from the DHT11 sensor.

It is responsible for:

- Reading temperature and humidity
- Creating structured JSON data
- Connecting to Wi-Fi
- Sending sensor data using MQTT
- Handling connection errors and reconnection
- Logging important events

### MQTT Broker

The MQTT broker receives messages published by the ESP32 and distributes
them to subscribed clients.

Communication model:

Publish/Subscribe

MQTT topic:

iot/building/room-a/environment

### API

The API provides access to the latest sensor data through HTTP.

Endpoint:

GET /api/sensors/latest

### Client

A client can send an HTTP request to the API to retrieve the latest
temperature and humidity data.

## Data Flow

1. The DHT11 measures temperature and humidity.
2. The ESP32 reads the measurements.
3. The ESP32 creates a JSON message.
4. The ESP32 publishes the message to the MQTT broker.
5. The sensor data is received and processed.
6. The latest measurement is made available through the REST API.
7. A client can retrieve the data using an HTTP GET request.

## Protocols and Data Formats

- Sensor communication: Digital signal
- Network: Wi-Fi
- IoT protocol: MQTT
- Data format: JSON
- API protocol: HTTP/HTTPS
- API style: REST
