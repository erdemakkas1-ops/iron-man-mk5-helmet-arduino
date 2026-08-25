# 🦾 Iron Man MK5 Helmet Controller - Arduino

Bu proje; çoklu servo motor senkronizasyonu, kademeli mekanik kapak hareketi ve senkronize LED aydınlatma efektlerini yöneten Arduino tabanlı bir Iron Man MK5 kask kontrol sistemidir.

## ⚙️ Özellikler
- **Senkronize Servo Kontrolü:** Vizör ve çene mekanizmalarının pürüzsüz açılıp kapanması için kademeli açı kontrolü.
- **Durum Yönetimi (State Machine):** Tek bir buton/dokunmatik tetikleyici ile açık/kapalı durumları arasında geçiş.
- **Senkronize LED Animasyonları:** Kask açılırken/kapanırken göze kademeli PWM parlaklık ve flaş efektleri.

## 🛠️ Donanım Bileşenleri
- **Mikrodenetleyici:** Arduino Nano / Uno
- **Aktüatörler:** 2x veya 4x SG90 / MG90S Metal Dişli Servo Motor
- **Tetikleyici:** Dokunmatik Sensör (TTP223) veya Buton
- **Aydınlatma:** 2x 5mm Beyaz/Mavi LED
- **Güç Beslemesi:** Harici 5V / 2A Regüle Güç Kaynağı

## 🔌 Pin Bağlantı Tablosu
| Bileşen | Arduino Pini | Açıklama |
| :--- | :--- | :--- |
| Sol Servo (Vizör/Plaka) | Pin 9 | PWM Sinyal |
| Sağ Servo (Vizör/Plaka) | Pin 10 | PWM Sinyal |
| Dokunmatik Sensör / Buton | Pin 2 | Harici Tetikleme Girişi (Interrupt uyumlu) |
| Göz LED'leri | Pin 6 | PWM Parlaklık / Durum Kontrolü |

> **Önemli Güç Uyarısı:** Servo motorlar eşzamanlı hareket ederken yüksek anlık akım çeker. Motor beslemeleri doğrudan harici 5V kaynağından verilmeli, Arduino'nun GND hattı harici güç kaynağının GND hattı ile birleştirilmelidir (Ortak Toprak / Common Ground).

## 🚀 Kurulum
1. Arduino IDE üzerinden `Servo.h` kütüphanesini hazır bulundurun.
2. `src/iron_man_mk5.ino` dosyasını kartınıza yükleyin.
3. Servo merkezleme açılarını kaskınızın mekanik limitlerine göre kod içerisinden kalibre edin.
