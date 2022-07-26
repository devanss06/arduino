#include "DHT.h"            //Library DHT

#define DHTPIN 6              //Inisialisasi DHT pada pin D5

#define DHTTYPE DHT22       //Inisialisasi tipe DHT

DHT dht (DHTPIN, DHTTYPE);  //Mengenalkan pin dan tipe DHT

float t;  //Variabel penampung nilai suhu

const int led1 = 3;   //LED kuning pada pin D3
const int led2 = 4;   //LED hijau pada pin D4
const int PWM_C = 9;  // PWM HANYA BISA DI PIN 3, 5, 6, 9, 10, or 11
int PWM_speed = 0;
int lastStat;


unsigned long sebelum = 0;
float temper = 0;


void setup() {


  Serial.begin(115200);     //Mulai komunikasi serial
  dht.begin();            //Mulai DHT


  pinMode(PWM_C, OUTPUT);

}

void loop() {

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if ((t >= 1) && (t < 30.9) && (lastStat != 1)) {
    //      Serial.println(lastStat);
    PWM_speed = 20;
    analogWrite(PWM_C, 20);
    //      Serial.println("suhu kurang dari 30");
    //      Serial.println("kecepatan kipas 20");
    lastStat = 1;

  }

  else if ((t >= 31.0) && (t < 35.9) && (lastStat != 2)) {
    //      Serial.println(lastStat);
    analogWrite(PWM_C, 50);
    PWM_speed = 50;
    //      Serial.println("suhu lebih dari 31,kurang dari 35");
    //      Serial.println("kecepatan kipas 50");
    lastStat = 2;

  }

  else if ((t >= 36.0) && (t < 40.9) && (lastStat != 3)) {

    //      Serial.println(lastStat);
    analogWrite(PWM_C, 100);
    PWM_speed = 100;
    //      Serial.println("suhu lebih dari 36, kurang dari 40");
    //      Serial.println("kecepatan kipas 100");
    lastStat = 3;

  }

  else if ((t >= 41.0) && (t < 45.9) && (lastStat != 4)) {
    //      Serial.println(lastStat);
    analogWrite(PWM_C, 150);
    PWM_speed = 150;
    //      Serial.println("suhu lebih dari 41, kurang dari 45");
    //      Serial.println("kecepatan kipas 150");
    lastStat = 4;

  }

  else if ((t >= 46.0) && (t < 50.9) && (lastStat != 5) ) {
    //      Serial.println(lastStat);
    analogWrite(PWM_C, 200);
    PWM_speed = 200;
    //      Serial.println("suhu lebih dari 46, kurang dari 50");
    //      Serial.println("kecepatan kipas 200");
    lastStat = 5;

  }

  else if ((t >= 51.0) && (t < 100) && (lastStat != 6)) {
    //      Serial.println(lastStat);
    analogWrite(PWM_C, 250);
    PWM_speed = 250;
    //      Serial.println("suhu lebih dari 51");
    //      Serial.println("kecepatan kipas 250");
    lastStat = 6;
  }
  
  if (t != temper) {
    temper = t;
    Serial.print(t);
    Serial.print(h);
  }

  //delay(1000);


}
