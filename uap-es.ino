#include "DHT.h"

// ======================================
// SMART FARMING - SISTEM VENTILASI KANDANG
// Sensor : DHT22 + MQ-2
// Aktuator : Fan Module L9110 + 2 LED
// ======================================

// ===== PIN SENSOR =====
#define DHTPIN D4
#define DHTTYPE DHT22

const int pinMQ = A0;

// ===== FAN L9110 =====
const int INA = D5;
const int INB = D6;

// ===== LED INDIKATOR =====
const int pinLEDHijau = D7;
const int pinLEDMerah = D0;

// ===== THRESHOLD =====
const float BATAS_SUHU = 32.0;
const int BATAS_GAS = 400;

// Inisialisasi DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  // Fan
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);

  // LED
  pinMode(pinLEDHijau, OUTPUT);
  pinMode(pinLEDMerah, OUTPUT);

  // Kondisi awal
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);

  digitalWrite(pinLEDHijau, HIGH);
  digitalWrite(pinLEDMerah, LOW);

  Serial.println();
  Serial.println("================================================");
  Serial.println(" SMART FARMING - SISTEM VENTILASI KANDANG");
  Serial.println("================================================");
  Serial.println("Monitoring suhu, kelembapan, dan kualitas udara");
  Serial.println("Menunggu kalibrasi sensor...");
  Serial.println("================================================");

  delay(5000);
}

void loop() {

  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  int nilaiGas = analogRead(pinMQ);

  // Validasi pembacaan sensor
  if (isnan(suhu) || isnan(kelembapan)) {

    Serial.println("ERROR : Gagal membaca DHT22");

    digitalWrite(pinLEDHijau, LOW);
    digitalWrite(pinLEDMerah, HIGH);

    delay(2000);
    return;
  }

  Serial.println();
  Serial.println("================================================");
  Serial.println(" DATA LINGKUNGAN KANDANG");
  Serial.println("================================================");

  Serial.print("Suhu Kandang       : ");
  Serial.print(suhu);
  Serial.println(" C");

  Serial.print("Kelembapan Kandang : ");
  Serial.print(kelembapan);
  Serial.println(" %");

  Serial.print("Nilai Gas MQ-2     : ");
  Serial.println(nilaiGas);

  Serial.println("------------------------------------------------");

  // ===== KONDISI PERINGATAN =====
  if (suhu >= BATAS_SUHU || nilaiGas >= BATAS_GAS) {

    // Fan ON
    digitalWrite(INA, HIGH);
    digitalWrite(INB, LOW);

    // LED
    digitalWrite(pinLEDHijau, LOW);
    digitalWrite(pinLEDMerah, HIGH);

    Serial.println("STATUS KANDANG : PERINGATAN");

    if (suhu >= BATAS_SUHU)
      Serial.println("- Suhu kandang melebihi batas aman");

    if (nilaiGas >= BATAS_GAS)
      Serial.println("- Kadar gas kandang meningkat");

    Serial.println();
    Serial.println("TINDAKAN OTOMATIS:");
    Serial.println("✓ Fan Module AKTIF");
    Serial.println("✓ LED Merah MENYALA");
    Serial.println("✓ Sirkulasi udara ditingkatkan");

    Serial.println();
    Serial.println("Tujuan : Menjaga kesehatan");
    Serial.println("         dan kenyamanan ternak");
  }

  // ===== KONDISI NORMAL =====
  else {

    // Fan OFF
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);

    // LED
    digitalWrite(pinLEDHijau, HIGH);
    digitalWrite(pinLEDMerah, LOW);

    Serial.println("STATUS KANDANG : NORMAL");
    Serial.println("✓ Suhu kandang dalam batas aman");
    Serial.println("✓ Kualitas udara baik");
    Serial.println("✓ Lingkungan ternak nyaman");

    Serial.println();
    Serial.println("Fan Module     : MATI");
    Serial.println("LED Hijau      : MENYALA");
  }

  Serial.println("================================================");

  delay(2000);
}
