# JD-SLAMETBAKTIMAN-EJOBIT
Live Coding Jagoan Digital 2025


**EjoBIT** adalah solusi IoT berbasis NodeMCU untuk monitoring, kontrol irigasi dan pemupukan secara otomatis pada tanaman, dirancang untuk petani yang menghadapi tantangan iklim seperti kekeringan dan banjir. 

Sistem ini menggunakan sensor kelembaban tanah, Sensor PH, sensor NPK, suhu, dan udara untuk meng-otomatisasi pompa air, menampilkan data di LCD, dan terhubung ke aplikasi Blynk untuk kontrol real-time. 

Proyek ini mendukung ekosistem pertanian presisi, dengan potensi menghemat air hingga 30%, efisiensi pupuk dan meningkatkan hasil panen, sejalan dengan SDGs 2 (Zero Hunger) dan 13 (Climate Action).

**Insight:**
- Jumlah penduduk Indonesia tahun 2023 hampir mencapai 300jt, dengan pertumbuhan rata-rata sebesar 2,8jt per tahun.
- Kebutuhan pangan nasional terus meningkat, sementara lahan pertanian & jumlah petani justru semakin menurun.
- Artinya, "pertanian presisi" saat ini adalah suatu keharusan sebagai solusi dari permasalahan di Indonesia dan dunia.

## Fitur Utama 
- Monitoring real-time kelembaban tanah, suhu tanah, dan kelembaban udara via LCD dan Blynk.
- Kontrol pompa otomatis (berdasarkan setpoint kelembaban) dan manual via aplikasi.
- Desain hemat biaya untuk petani.
- Skalabel untuk mendukung program ketahanan pangan di Banyuwangi.

## Daftar Isi
- [Kebutuhan](#kebutuhan)
- [Instalasi & Setup](#instalasi--setup)
- [Cara Penggunaan](#cara-penggunaan)
- [Progres Live Coding](#progres-live-coding)
- [Troubleshooting](#troubleshooting)
- [Changelog](#changelog)
- [Kontributor](#kontributor)
- [Lisensi](#lisensi)
- [Kontak](#kontak)

## Kebutuhan

### Hardware
| Komponen             | Deskripsi                    | Pin NodeMCU |
|----------------------|------------------------------|-------------|
| NodeMCU ESP8266      | Mikrokontroler utama         | -           |
| Soil Moisture Sensor | Kelembaban tanah             | A0          |
| DHT11                | Kelembaban dan suhu udara    | D3          |
| DS18B20              | Suhu tanah/air               | D5          |
| Relay Module         | Kontrol pompa air            | D6          |
| LCD I2C 16x2         | Display status               | SDA/SCL     |

**Catatan**: Gunakan power supply 5V eksternal untuk stabilitas.

### Software
- **Arduino IDE**: Versi 2.x ([download](<https://www.arduino.cc/en/software>)).
- **Libraries**: Blynk, DallasTemperature, OneWire, DHT sensor, LiquidCrystal_I2C.
- **Blynk App**: iOS/Android, template ID: `xxx`, token: `xxx`.
- **WiFi**: Koneksi stabil (hotspot/mobile data).

## Instalasi & Setup
1. **Install Arduino IDE**:
   - Download dari [arduino.cc](<https://www.arduino.cc/en/software>).
   - Tambah board ESP8266 di `Preferences` > `Additional Boards Manager URLs` > `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Install board ESP8266 via Boards Manager.
2. **Install Libraries**:
   - Buka Arduino IDE > `Sketch` > `Include Library` > `Manage Libraries`.
   - Cari dan install: `Blynk`, `DallasTemperature`, `OneWire`, `DHT`, `LiquidCrystal_I2C`
3. **Setup Hardware**:
   - Hubungkan komponen sesuai skema.
     ![schematic](assets/schematic.png)
   - Pastikan pin: Soil Moisture (A0), DHT11 (D3), DS18B20 (D5), Relay (D6), LCD I2C (SDA/SCL).
   - Gunakan power supply 5V eksternal untuk stabilitas.
4. **Setup Blynk**:
   - Daftar di [blynk.io](<https://blynk.io>), buat template dengan ID dan token di atas.
   - Widget akan dikonfigurasi setelah integrasi Blynk selesai.

## Cara Penggunaan
1. **Nyalakan Device**:
   - Hubungkan NodeMCU ke power supply 5V.
   - LCD menampilkan splash screen, lalu status: "Mst= %, T= C | Hum= %, P= OFF".
2. **Monitoring Sensor**:
   - Data kelembaban tanah (%), suhu tanah (°C), dan kelembaban udara (%) ditampilkan di LCD.
   - Cek Serial Monitor untuk log data (9600 baud).
3. **Kontrol Pompa**:
   - Mode otomatis: Pompa nyala jika kelembaban tanah <40%, mati jika >60% (hysteresis).
   - Mode manual: Kontrol pompa via aplikasi (akan diintegrasikan dengan Blynk).
   - Status pompa ditampilkan di LCD: "P: ON" atau "P: OFF".
   - Tes: Simulasi tanah kering (pompa ON) dan basah (pompa OFF).
     
## Progres dan Live Coding
Proyek ini akan dikembangkan menjadi 4 tahap selama 2 hari, antara lain:
1. **Tahap 1** : Inisialisasi Hardware dan display LCD (hari ke 1).
- Inisialisasi NodeMCU, sensor (Soil Moisture, DHT11, DS18B20), relay, dan LCD I2C.
- LCD menampilkan splash screen: "EjoBIT | Smart Farming".
- Kode: Inisialisasi library, pin konfigurasi, dan setup awal.
- Hasil: LCD menyala, hardware siap untuk pembacaan sensor.
     ![inisialisasi](assets/inisialisasi.jpg)
  
2. **Tahap 2** : Pembacaan sensor dan output ke display LCD (hari ke 1).
- Implementasi pembacaan sensor: Soil Moisture (A0), DHT11 (D3), DS18B20 (D5).
- Kalibrasi soil moisture (AirValue=620, WaterValue=310) untuk skala 0-100%.
- Output data ke LCD dengan format rapi.
- Hasil: Data sensor ditampilkan di LCD (e.g., "Mst: 45% T: 28C"), akurasi ±5%.
     ![tahap2](assets/tahap2.jpg)
  
3. **Tahap 3** : Kontrol pompa otomatis dan manual (hari ke 2).
- Implementasi logika kontrol pompa dengan hysteresis (SP_LOW=40%, SP_HIGH=60%).
- Mode otomatis: Pompa responsif terhadap kelembaban tanah.
- Mode manual: Simulasi kontrol via kode (akan dihubungkan ke Blynk).
- Hasil: Pompa nyala/mati stabil, LCD update status pompa.
     ![tahap3](assets/tahap3.png)
  
5. **Tahap 4** : Integrasi Blynk untuk monitoring dan kontrol via aplikasi (hari ke 2).

## Troubleshooting
- **WiFi Tidak Connect**: Cek SSID/password di kode, gunakan hotspot jika sinyal lemah.

## Changelog
- **v0.1 (Hari 1):** Setup dasar, inisialisasi LCD, sensor, dan relay.
- **v0.2 (Hari 1):** Inisialisasi hardware dan LCD selesai. Tes splash screen berhasil.
- **v0.3 (Hari 2)**: Tambah kontrol pompa otomatis (hysteresis) dan manual.
- 

## Kontributor
- Slamet Baktiman - Full Stack IoT Developer
