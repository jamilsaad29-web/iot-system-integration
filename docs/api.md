# API Documentation

## Overview

The system uses an API to make sensor data available to other systems.

Sensor data originates from an ESP32 connected to a physical DHT11 sensor.
The ESP32 measures temperature and humidity and sends the data through the
network using MQTT in JSON format.

The API is used to access the latest sensor data.

## Data Format

Sensor data is represented as JSON.

Example:

{
  "sensorId": "room-a-dht11-01",
  "temperature": 22.4,
  "humidity": 48,
  "temperatureUnit": "C",
  "humidityUnit": "%"
}

## Endpoint

### Get latest sensor data

Method:

GET

Endpoint:

/api/sensors/latest

Example request:

GET /api/sensors/latest

Example response:

{
  "sensorId": "room-a-dht11-01",
  "temperature": 22.4,
  "humidity": 48,
  "temperatureUnit": "C",
  "humidityUnit": "%"
}

## HTTP Status Codes

200 OK  
The request was successful and sensor data was returned.

404 Not Found  
No sensor data is currently available.

500 Internal Server Error  
An unexpected server error occurred.

## Error Handling

If sensor data is unavailable, the API returns an appropriate HTTP status code
instead of invalid sensor data.

Errors are also logged so that communication and API problems can be
identified during troubleshooting.
