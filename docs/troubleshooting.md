# Troubleshooting

## Overview

During development, two errors will be intentionally introduced into the
system.

Each error will be tested, analyzed and documented according to the
troubleshooting process below.

---

## Error 1 – Incorrect MQTT Broker Address

### Observed Symptom

To be completed during testing.

### How the Error Was Identified

To be completed during testing.

### Tools and Logs Used

- ESP32 Serial Monitor
- MQTT connection logs

### Cause

An incorrect MQTT broker address will be intentionally configured.

### Solution

To be completed during testing.

### Verification

To be completed after the correct broker address has been restored and
the MQTT connection has been tested again.

---

## Error 2 – Unrealistic Sensor Value

### Observed Symptom

To be completed during testing.

### How the Error Was Identified

To be completed during testing.

### Tools and Logs Used

- ESP32 Serial Monitor
- Application logs
- MQTT message output

### Cause

An unrealistic sensor value will be intentionally introduced, for example
a temperature value of 999 degrees Celsius.

### Solution

The system will validate sensor values before accepting or processing them.
Values outside the expected range will be rejected and logged as invalid.

The final solution and observed behavior will be documented during testing.

### Verification

To be completed after a valid sensor value has been restored and successfully
processed by the system.

---

## Troubleshooting Process

For each intentionally introduced error, the following process is used:

1. Observe the system behavior.
2. Check logs and error messages.
3. Identify the affected component.
4. Determine the cause of the error.
5. Correct the configuration or code.
6. Run the system again.
7. Verify that normal operation has been restored.
