
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

const int flowSensorPin = 27;
volatile int pulseCount;
float flowRate;
unsigned long oldTime;

void IRAM_ATTR pulseCounter() {
  pulseCount++;
}

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.publish("agua/monitoramento/status", "Online");
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(flowSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  oldTime = millis();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long currentTime = millis();
  if (currentTime - oldTime > 10000) {
    detachInterrupt(digitalPinToInterrupt(flowSensorPin));
    flowRate = (pulseCount / 7.5); // fórmula estimada
    pulseCount = 0;
    oldTime = currentTime;

    char msg[50];
    dtostrf(flowRate, 4, 2, msg);
    client.publish("agua/monitoramento/fluxo", msg);
    attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, FALLING);
  }
}
