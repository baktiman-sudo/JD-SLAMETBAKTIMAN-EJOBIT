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

// Nilai kalibrasi sensor kelembapan tanah
const int AirValue = 620;   // Nilai saat tanah kering
const int WaterValue = 310; // Nilai saat tanah basah

// Variabel global
int soilMoistureValue = 0;
int soilmoist = 0;
int humi, temp;

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

  lcd.clear();
  lcd.print("Mst= %, T= C");
  lcd.setCursor(0, 1);
  lcd.print("Hum= %, P= OFF");
}

void loop(void) {
 // Baca suhu dari DS18B20
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  Serial.print("Temp : ");
  Serial.println(temp);
  lcd.setCursor(12, 0);
  lcd.print(temp);

  // Baca kelembapan tanah
  soilMoistureValue = analogRead(A0);
  soilmoist = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if (soilmoist >= 100) soilmoist = 100;
  else if (soilmoist <= 0) soilmoist = 0;
  Serial.print("Soil Moisture : ");
  Serial.print(soilmoist);
  Serial.println("%");
  lcd.setCursor(4, 0);
  lcd.print(soilmoist);
  lcd.print(" ");

  // Baca kelembapan udara
  humi = dht.readHumidity();
  if (isnan(humi)) {
    Serial.println("DHT11 tidak terbaca... !");
  } else {
    Serial.print("Humi: ");
    Serial.println(humi);
    lcd.setCursor(4, 1);
    lcd.print(humi);
  }

  delay(1500); // Update setiap 1.5 detik
}
