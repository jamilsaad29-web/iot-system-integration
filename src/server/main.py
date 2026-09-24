from flask import Flask, jsonify
import paho.mqtt.client as mqtt
import json
import threading

app = Flask(__name__)

# Latest sensor data
sensor_data = {
    "temperature": 0.0,
    "humidity": 0.0
}

# MQTT settings
MQTT_BROKER = "broker.hivemq.com"
MQTT_PORT = 1883
MQTT_TOPIC = "jamil/iot/sensors"


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.subscribe(MQTT_TOPIC)
        print(f"Subscribed to: {MQTT_TOPIC}")
    else:
        print(f"MQTT connection failed: {rc}")


def on_message(client, userdata, msg):
    global sensor_data

    try:
        payload = msg.payload.decode("utf-8")
        data = json.loads(payload)

        sensor_data["temperature"] = data.get("temperature", 0.0)
        sensor_data["humidity"] = data.get("humidity", 0.0)

        print("Received sensor data:", sensor_data)

    except (json.JSONDecodeError, UnicodeDecodeError) as error:
        print("Invalid MQTT message:", error)


def start_mqtt():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message

    print("Connecting to MQTT broker...")
    client.connect(MQTT_BROKER, MQTT_PORT, 60)

    client.loop_forever()


@app.route("/api/sensors", methods=["GET"])
def get_sensor_data():
    return jsonify(sensor_data)


if __name__ == "__main__":
    mqtt_thread = threading.Thread(target=start_mqtt, daemon=True)
    mqtt_thread.start()

    app.run(host="0.0.0.0", port=5000, debug=True)
    