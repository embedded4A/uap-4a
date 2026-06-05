# Tutorial Perakitan Smart Farming - Sistem Ventilasi Kandang Otomatis

Panduan ini menjelaskan langkah-langkah merangkai sistem Smart Farming menggunakan ESP8266 NodeMCU, sensor DHT22, sensor MQ-2, Fan Module L9110, serta dua LED indikator.

## Komponen yang Dibutuhkan

* 1x ESP8266 NodeMCU
* 1x Sensor DHT22
* 1x Sensor MQ-2
* 1x Fan Module L9110
* 1x LED Hijau
* 1x LED Merah
* 1x Breadboard
* Kabel Jumper secukupnya
* Kabel USB

---

## Langkah 1 - Menyiapkan NodeMCU

Letakkan NodeMCU pada breadboard agar seluruh pin mudah dihubungkan ke sensor dan aktuator.

Pastikan NodeMCU belum terhubung ke sumber listrik selama proses perakitan.

---

## Langkah 2 - Menghubungkan Sensor DHT22

Hubungkan pin-pin DHT22 ke NodeMCU sebagai berikut:

| Pin DHT22 | Pin NodeMCU |
| --------- | ----------- |
| VCC       | 3V3         |
| DATA      | D4          |
| GND       | GND         |

Fungsi sensor DHT22 adalah untuk membaca suhu dan kelembapan lingkungan kandang.

---

## Langkah 3 - Menghubungkan Sensor MQ-2

Hubungkan sensor MQ-2 ke NodeMCU:

| Pin MQ-2 | Pin NodeMCU |
| -------- | ----------- |
| VCC      | VIN / 5V    |
| GND      | GND         |
| AO       | A0          |

Sensor MQ-2 digunakan untuk mendeteksi peningkatan kadar gas di lingkungan kandang.

---

## Langkah 4 - Menghubungkan Fan Module L9110

Hubungkan Fan Module L9110 ke NodeMCU:

| Pin L9110 | Pin NodeMCU |
| --------- | ----------- |
| VCC       | VIN / 5V    |
| GND       | GND         |
| INA       | D5          |
| INB       | D6          |

Fan Module L9110 berfungsi sebagai ventilasi otomatis untuk meningkatkan sirkulasi udara saat kondisi kandang tidak ideal.

---

## Langkah 5 - Menghubungkan LED Hijau

Hubungkan LED hijau sebagai indikator kondisi normal.

| Kaki LED Hijau | Pin |
| -------------- | --- |
| Anoda (+)      | D7  |
| Katoda (-)     | GND |

Ketika kondisi kandang normal, LED hijau akan menyala.

---

## Langkah 6 - Menghubungkan LED Merah

Hubungkan LED merah sebagai indikator peringatan.

| Kaki LED Merah | Pin |
| -------------- | --- |
| Anoda (+)      | D0  |
| Katoda (-)     | GND |

Ketika suhu atau kadar gas melebihi batas aman, LED merah akan menyala.

---

## Langkah 7 - Memeriksa Kembali Rangkaian

Pastikan seluruh koneksi telah sesuai:

| Komponen   | Pin NodeMCU |
| ---------- | ----------- |
| DHT22 DATA | D4          |
| MQ-2 AO    | A0          |
| L9110 INA  | D5          |
| L9110 INB  | D6          |
| LED Hijau  | D7          |
| LED Merah  | D0          |

Pastikan seluruh pin GND dari sensor dan aktuator terhubung ke GND NodeMCU.

---

## Langkah 8 - Mengunggah Program

1. Buka Arduino IDE.
2. Pilih board **NodeMCU 1.0 (ESP-12E Module)**.
3. Pilih port yang sesuai.
4. Pastikan library **DHT Sensor Library** telah terinstal.
5. Salin kode program Smart Farming.
6. Klik **Verify** untuk melakukan kompilasi.
7. Klik **Upload** untuk mengunggah program ke NodeMCU.

---

## Langkah 9 - Menjalankan Sistem

Setelah proses upload selesai:

1. Buka **Serial Monitor**.
2. Atur baud rate menjadi **9600**.
3. Tunggu proses kalibrasi sensor selama beberapa detik.
4. Amati data suhu, kelembapan, dan kadar gas yang ditampilkan.

---
