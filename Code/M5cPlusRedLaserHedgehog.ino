#include <Wire.h>
#include <M5StickCPlus.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "router12";
const char* password = "iot123456789";
const char* mqtt_server = "192.168.14.1";  

const int sensorPin1 = 32;
int lightVal1;

// WiFi 和 MQTT 客户端
WiFiClient espClient;
PubSubClient client(espClient);

// MQTT Topic
const char* mqtt_topic = "fruit/lightval";

// ---------- 连接 WiFi ----------
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  M5.Lcd.print("Connecting to WiFi...\n");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    M5.Lcd.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  M5.Lcd.println("WiFi connected");
  M5.Lcd.println(WiFi.localIP());
}

// ---------- MQTT 重连 ----------
void reconnect() {
  // 一直尝试连接直到成功
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      
       client.subscribe("fruit/check");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      delay(2000);
    }
  }
}

// ---------- 初始化 ----------
void setup() {
  Serial.begin(115200);
  pinMode(sensorPin1, INPUT);
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  lightVal1 = analogRead(sensorPin1);
  Serial.print("Light Value: ");
  Serial.println(lightVal1);

  // 在屏幕上显示
  M5.Lcd.setCursor(30, 55);
  M5.Lcd.printf("Sending ... \n");
  M5.Lcd.fillRect(37, 75, 180, 40, BLACK);
  M5.Lcd.setCursor(30, 75);
  M5.Lcd.printf("Laser V : %04d\n", lightVal1);

  // 构建 MQTT 消息并发布
  char msg[50];
  sprintf(msg, "%d", lightVal1);
  client.publish(mqtt_topic, msg);

  delay(2000);  // 每 2 秒发送一次
}
