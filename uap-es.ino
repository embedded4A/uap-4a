#include "DHT.h"

// ======================================
// SMART FARMING - SISTEM VENTILASI KANDANG
// Sensor : DHT22 + MQ-2
// Aktuator : Fan Module L9110 + LED
// Board : NodeMCU ESP8266
// ======================================

// ===== KONFIGURASI PIN =====
#define DHTPIN D4
#define DHTTYPE DHT22

const int pinMQ2 = A0;
const int pinFan = D5;
const int pinLED = D6;

// ===== BATAS AMAN KANDANG =====
const float BATAS_SUHU = 32.0;
const int BATAS_GAS = 400;

// Inisialisasi DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(pinFan, OUTPUT);
  pinMode(pinLED, OUTPUT);

  digitalWrite(pinFan, LOW);
  digitalWrite(pinLED, LOW);

  Serial.println();
  Serial.println("================================================");
  Serial.println(" SMART FARMING - SISTEM VENTILASI KANDANG");
  Serial.println("================================================");
  Serial.println("Monitoring suhu, kelembapan, dan kualitas udara");
  Serial.println("Sensor  : DHT22 + MQ-2");
  Serial.println("Aktuator: Fan Module L9110 + LED");
  Serial.println("Status  : Inisialisasi Sistem...");
  Serial.println("Menunggu kalibrasi sensor MQ-2...");
  Serial.println("================================================");

  delay(5000);
}

void loop() {

  // Membaca sensor DHT22
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  // Membaca sensor MQ-2
  int nilaiGas = analogRead(pinMQ2);

  // Validasi pembacaan DHT22
  if (isnan(suhu) || isnan(kelembapan)) {

    Serial.println();
    Serial.println("!!! ERROR SISTEM !!!");
    Serial.println("Gagal membaca sensor DHT22");
    Serial.println("Periksa koneksi sensor");
    delay(2000);

    return;
  }

  // Menampilkan data sensor
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

  // Logika kontrol Smart Farming
  if (suhu >= BATAS_SUHU || nilaiGas >= BATAS_GAS) {

    digitalWrite(pinFan, HIGH);
    digitalWrite(pinLED, HIGH);

    Serial.println("STATUS KANDANG : PERINGATAN");

    if (suhu >= BATAS_SUHU) {
      Serial.println("- Suhu kandang melebihi batas aman");
    }

    if (nilaiGas >= BATAS_GAS) {
      Serial.println("- Kadar gas kandang meningkat");
    }

    Serial.println();
    Serial.println("TINDAKAN OTOMATIS:");
    Serial.println("✓ Fan Module AKTIF");
    Serial.println("✓ LED Indikator MENYALA");
    Serial.println("✓ Sirkulasi udara ditingkatkan");
    Serial.println();
    Serial.println("Tujuan : Menjaga kesehatan");
    Serial.println("         dan kenyamanan ternak");

  } else {

    digitalWrite(pinFan, LOW);
    digitalWrite(pinLED, LOW);

    Serial.println("STATUS KANDANG : NORMAL");
    Serial.println("✓ Suhu kandang dalam batas aman");
    Serial.println("✓ Kualitas udara baik");
    Serial.println("✓ Lingkungan ternak nyaman");

    Serial.println();
    Serial.println("Fan Module     : NONAKTIF");
    Serial.println("LED Indikator  : MATI");
  }

  Serial.println("================================================");

  delay(2000);
}
