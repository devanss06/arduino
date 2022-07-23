#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "devv";
const char* password = "gabutbet";
const char* mqtt_server = "104.248.156.51";

WiFiClient espClient;
PubSubClient client(espClient);

#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;
#define DHTPIN 2
DHT dht(DHTPIN, DHT22);
float temp, humi;
float temper = 0;
float Temperature;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("connecting To ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("Wifi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT Connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), "ali", "1234")) {
      Serial.println("Connected");
      client.subscribe("ARDUI1");
    }
    else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Try Again In 5 Seconds");
      delay(5000);
    }
  }
}
void setup() {
  dht.begin();
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  delay(3000);
}
void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  if (isnan(humi) || isnan(temp)) {
    Serial.println("DHT22 Tidak Terbaca...");
    return;
  }

   if (Temperature != temper) {
    temper = Temperature;

    Serial.println("Humidity: ");
    Serial.println(Humidity);
    Serial.println(" Temperature: ");
    Serial.println(Temperature);
    Serial.print(" *C ");

    sprintf(msg, "%.2f", Temperature);
    Serial.print("Publish Message: ");
    Serial.println(msg);
    client.publish("Temperature", msg);
    sprintf(msg, "%.2f", Humidity);
    Serial.print("Publish Message: ");
    Serial.println(msg);
    client.publish("Humidity", msg);

  }
}
