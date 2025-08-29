# JD-SLAMETBAKTIMAN-EJOBIT
Live Coding Jagoan Digital 2025


**EjoBIT** adalah solusi IoT berbasis NodeMCU untuk monitoring, kontrol irigasi dan pemupukan secara otomatis pada tanaman, dirancang untuk petani yang menghadapi tantangan iklim seperti kekeringan dan banjir. 

Sistem ini menggunakan sensor kelembaban tanah, sensor NPK, suhu, dan udara untuk meng-otomatisasi pompa air, menampilkan data di LCD, dan terhubung ke aplikasi Blynk untuk kontrol real-time. 

Proyek ini mendukung ekosistem pertanian presisi, dengan potensi menghemat air hingga 30%, efisiensi pupuk dan meningkatkan hasil panen, sejalan dengan SDGs 2 (Zero Hunger) dan 13 (Climate Action).

Insight:
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
- [Progres Live Coding](#progres-live-coding)
- [Troubleshooting](#troubleshooting)
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


