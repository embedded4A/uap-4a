# Ujian Akhir Praktikum Embedded System: Smart Farming - Sistem Ventilasi Kandang Otomatis

Proyek ini merupakan implementasi sistem *Smart Farming* berbasis mikrokontroler ESP8266 NodeMCU yang dirancang untuk memantau kondisi lingkungan kandang ternak secara otomatis. Sistem menggunakan sensor **DHT22** untuk mengukur suhu dan kelembapan kandang serta sensor **MQ-2** untuk mendeteksi peningkatan kadar gas di lingkungan peternakan yang dapat memengaruhi kesehatan ternak.

Data yang diperoleh dari sensor digunakan untuk mengendalikan aktuator berupa **Fan Module L9110** sebagai ventilasi otomatis dan dua buah **LED indikator** sebagai penanda kondisi kandang. Ketika suhu kandang atau kadar gas melebihi batas yang telah ditentukan, sistem akan mengaktifkan ventilasi guna meningkatkan sirkulasi udara dan menjaga kenyamanan ternak. Selain itu, LED merah akan menyala sebagai indikator peringatan, sedangkan LED hijau menunjukkan kondisi kandang dalam keadaan normal.

## Fitur Utama

* **Monitoring Suhu Kandang:** Mengukur suhu lingkungan kandang menggunakan sensor DHT22 secara *real-time*.
* **Monitoring Kelembapan Kandang:** Memantau tingkat kelembapan udara untuk menjaga kondisi lingkungan yang optimal bagi ternak.
* **Deteksi Gas:** Menggunakan sensor MQ-2 untuk mendeteksi peningkatan kadar gas di area kandang.
* **Ventilasi Otomatis:** Mengaktifkan Fan Module L9110 secara otomatis ketika suhu kandang mencapai atau melebihi batas kritis (≥ 32°C) atau kadar gas melebihi nilai ambang (≥ 400).
* **Indikator Status Kandang:** LED hijau menyala saat kondisi kandang normal, sedangkan LED merah menyala saat kondisi kandang memerlukan perhatian.
* **Data Logging:** Menampilkan data suhu, kelembapan, kadar gas, serta status aktuator secara berkala melalui Serial Monitor dengan baud rate 9600.

## Komponen Perangkat Keras

1. ESP8266 NodeMCU
2. Sensor Suhu dan Kelembapan DHT22
3. Sensor Gas MQ-2
4. Fan Module L9110
5. LED Hijau
6. LED Merah
7. Breadboard
8. Kabel Jumper
9. Kabel USB untuk pemrograman dan catu daya

## Konfigurasi Pin Penghubung

| Komponen         | Pin NodeMCU |    Tipe Pin    | Keterangan                          |
| :--------------- | :---------: | :------------: | :---------------------------------- |
| **DHT22 (Data)** |      D4     |  Digital Input | Membaca suhu dan kelembapan kandang |
| **MQ-2 (AO)**    |      A0     |  Analog Input  | Membaca kadar gas lingkungan        |
| **L9110 (INA)**  |      D5     | Digital Output | Kontrol Fan Module                  |
| **L9110 (INB)**  |      GND     | Digital Output | Kontrol Fan Module                  |
| **LED 1**    |      D7     | Digital Output | Indikator kondisi normal            |
| **LED 2**    |      D0     | Digital Output | Indikator kondisi peringatan        |

## Logika Sistem

### Kondisi Normal

* Suhu kandang < 32°C
* Kadar gas < 400
* Fan Module OFF
* LED Hijau ON
* LED Merah OFF

### Kondisi Peringatan

* Suhu kandang ≥ 32°C atau
* Kadar gas ≥ 400
* Fan Module ON
* LED Hijau OFF
* LED Merah ON

