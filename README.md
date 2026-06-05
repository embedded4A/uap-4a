# Ujian Akhir Praktikum Embedded System: Smart Farming - Sistem Ventilasi Kandang Otomatis

Proyek ini merupakan implementasi sistem *Smart Farming* berbasis mikrokontroler ESP8266 NodeMCU yang dirancang untuk memantau kondisi lingkungan kandang ternak secara otomatis. Sistem menggunakan sensor **DHT22** untuk mengukur suhu dan kelembapan kandang serta sensor **MQ-2** untuk mendeteksi peningkatan konsentrasi gas di lingkungan peternakan yang dapat memengaruhi kesehatan ternak.

Data yang diperoleh dari sensor digunakan untuk mengendalikan aktuator berupa **Fan Module L9110** sebagai ventilasi otomatis dan **LED indikator** sebagai penanda kondisi kandang. Ketika suhu kandang atau kadar gas melebihi batas yang telah ditentukan, sistem akan mengaktifkan ventilasi guna meningkatkan sirkulasi udara dan menjaga kenyamanan ternak.

## Fitur Utama

* **Monitoring Suhu Kandang:** Mengukur suhu lingkungan kandang menggunakan sensor DHT22 secara *real-time*.
* **Monitoring Kelembapan Kandang:** Memantau tingkat kelembapan udara untuk menjaga kondisi lingkungan yang optimal bagi ternak.
* **Deteksi Gas:** Menggunakan sensor MQ-2 untuk mendeteksi peningkatan kadar gas di area kandang.
* **Ventilasi Otomatis:** Mengaktifkan Fan Module L9110 secara otomatis ketika suhu kandang mencapai atau melebihi batas kritis (≥ 32°C) atau kadar gas melebihi nilai ambang (≥ 400).
* **Indikator Peringatan:** Menyalakan LED sebagai indikator visual ketika kondisi kandang memerlukan perhatian.
* **Data Logging:** Menampilkan data suhu, kelembapan, kadar gas, dan status aktuator secara berkala melalui Serial Monitor dengan baud rate 9600.

## Komponen Perangkat Keras

1. ESP8266 NodeMCU
2. Sensor Suhu dan Kelembapan DHT22
3. Sensor Gas MQ-2
4. Fan Module L9110
5. LED Indikator
6. Breadboard
7. Kabel Jumper
8. Kabel USB untuk pemrograman dan catu daya

## Konfigurasi Pin Penghubung

| Komponen             | Pin NodeMCU |    Tipe Pin    | Keterangan                          |
| :------------------- | :---------: | :------------: | :---------------------------------- |
| **DHT22 (Data)**     |      D4     |  Digital Input | Membaca suhu dan kelembapan kandang |
| **MQ-2 (AO)**        |      A0     |  Analog Input  | Membaca kadar gas lingkungan        |
| **Fan Module L9110** |      D5     | Digital Output | Mengendalikan ventilasi kandang     |
| **LED Indikator**    |      D6     | Digital Output | Menunjukkan kondisi kandang         |

## Logika Sistem

### Kondisi Normal

* Suhu kandang < 32°C
* Kadar gas < 400
* Fan Module OFF
* LED OFF

### Kondisi Peringatan

* Suhu kandang ≥ 32°C atau
* Kadar gas ≥ 400
* Fan Module ON
* LED ON

## Alur Kerja Sistem

1. Sistem membaca suhu dan kelembapan dari sensor DHT22.
2. Sistem membaca kadar gas dari sensor MQ-2.
3. Data sensor ditampilkan pada Serial Monitor.
4. Sistem membandingkan hasil pembacaan dengan nilai ambang yang telah ditentukan.
5. Jika suhu atau kadar gas melebihi batas aman, Fan Module L9110 dan LED indikator akan diaktifkan.
6. Jika kondisi kembali normal, Fan Module dan LED akan dimatikan.
7. Proses monitoring berlangsung secara terus-menerus setiap 2 detik.

## Output Serial Monitor

Sistem akan menampilkan informasi berupa:

* Suhu kandang (°C)
* Kelembapan kandang (%)
* Nilai pembacaan gas MQ-2
* Status ventilasi kandang
* Status LED indikator
* Kondisi kandang (Normal atau Peringatan)

Melalui sistem ini, peternak dapat melakukan pemantauan kondisi kandang secara otomatis sehingga kualitas udara dan kenyamanan lingkungan ternak tetap terjaga. Ventilasi akan bekerja secara otomatis ketika terjadi peningkatan suhu atau kadar gas, sehingga membantu menciptakan lingkungan yang lebih sehat bagi ternak.
