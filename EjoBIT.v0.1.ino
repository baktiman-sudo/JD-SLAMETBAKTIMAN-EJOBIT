//Live Coding Jagoan Digital

// Library sensor dan LCD
#include <DallasTemperature.h>
#include <OneWire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pin konfigurasi
#define ONE_WIRE_BUS D5
#define DHTPIN D3
#define DHTTYPE DHT11
#define pump D6

// Inisialisasi sensor
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Setup awal
void setup(void) {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print(" EjoBIT ");
  lcd.setCursor(0, 1);
  lcd.print(" Smart Farming ");
  delay(2000); // Tampilkan splash screen

  sensors.begin();
  dht.begin();
  pinMode(pump, OUTPUT);
  digitalWrite(pump, LOW); // Pastikan pompa OFF
}

void loop(void) {
  // Kosong untuk tahap berikutnya
}
