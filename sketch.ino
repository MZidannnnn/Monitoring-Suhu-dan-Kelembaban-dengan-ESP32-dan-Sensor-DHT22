// INCLUDE library dht
#include "DHT.h"

// deklarasi pin dan tye dht
#define DHTPIN 5
#define DHTTYPE DHT22
#define LED_PIN 4
#define LED_GREEN 16
#define LED_BLUE 17

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   pinMode(LED_PIN, OUTPUT); // Set GPIO sebagai output
   pinMode(LED_GREEN, OUTPUT); // Set GPIO sebagai output
   pinMode(LED_BLUE, OUTPUT); // Set GPIO sebagai output
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Tes Sensor DHT");
  dht.begin();
}
void loop() {
  delay(2000); // Tunggu 2 detik
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);
  float h = dht.readHumidity();

  // Perulangan cek jika ada nilai kosong
  if (isnan(c)||isnan(f)||isnan(h)){
    Serial.print("Error Nilai NAN");
    return;
  }

  // Menampilkan nilai suhu dan kelembaban
  Serial.print("Suhu\t\t: ");
  Serial.print(c);
  Serial.println(" °C");

  Serial.print("Farenheit\t: ");
  Serial.print(f);
  Serial.println(" °F");

  Serial.print("Humidity\t: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println("=============================");

  // Logika LED berdasarkan nilai suhu
  if (c > 30) {
    digitalWrite(LED_PIN, HIGH);   // Nyalakan LED merah
    digitalWrite(LED_GREEN, LOW);  // Matikan LED hijau
    digitalWrite(LED_BLUE, LOW);   // Matikan LED biru
  } else if (c >= 16 && c <= 30) {
    digitalWrite(LED_GREEN, HIGH); // Nyalakan LED hijau
    digitalWrite(LED_PIN, LOW);    // Matikan LED merah
    digitalWrite(LED_BLUE, LOW);   // Matikan LED biru
  } else {
    digitalWrite(LED_BLUE, HIGH);  // Nyalakan LED biru
    digitalWrite(LED_PIN, LOW);    // Matikan LED merah
    digitalWrite(LED_GREEN, LOW);  // Matikan LED hijau
  }
}
