#include "Utils.hpp"
#include "MQTT_Config.hpp"

WiFiClient esp;
PubSubClient client(esp);

void print_byte(unsigned long b) {
  for (int i = 0; i < 8; i++) {
    int x = b & (1 << i);
    Serial.print(x >> i, DEC);
    Serial.print(" ");
  }
}

void print_conditions(blc_bits32 temperature, blc_bits32 humidity) {
  if (temperature == -1 || humidity == -1)
    Serial.println("Checksum error!");
  else {
    Serial.print("T=");
    Serial.print(temperature, DEC);
    Serial.print("°C, H=");
    Serial.print(humidity, DEC);
    Serial.print("%\n");
  }
}

void print_conditions_raw(blc_bits32 temperature, blc_bits32 humidity) {
  Serial.print("T=");
  print_byte(temperature);
  Serial.print(" °C, H=");
  print_byte(humidity);
  Serial.print("%\n");
}

void publish_conditions(blc_bits32 temperature, blc_bits32 humidity) {
  char out_msg[40];
  memset(out_msg, 0, 40);
  snprintf(out_msg, 40, "{\"temperature\" : %d, \"humidity\" : %d}",
           temperature, humidity);
  Serial.print("Publish message: ");
  Serial.println(out_msg);

  client.publish(mqttTopic, out_msg);
}

void interrupts_off(void) { noInterrupts(); }

void interrupts_on(void) { interrupts(); }

void LED_on(void) {
  digitalWrite(LED_ONBOARD, LOW);
}

void LED_off(void) {
  digitalWrite(LED_ONBOARD, HIGH);
}

// See examples from https://github.com/knolleary/pubsubclient
void setup_wifi_and_mqtt() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PSK);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setServer(MQTT_BROKER, 1883);
}

void client_loop() { client.loop(); }

blc_bool is_client_connected() { return client.connected(); }

blc_bool connect() {
  Serial.println("Connecting to MQTT");
  return client.connect("ESP8266Client_withDHT11", mqttUser, mqttPassword);
}