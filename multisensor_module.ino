#include <DHT.h>

#define DHTPIN 14
#define DHTTYPE DHT11
#define LDR_PIN 35


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(33, OUTPUT);
}

void loop() {
  delay(2000); 

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("FAIL");
    return; // prevents crash
  }
 int lightValue = analogRead(LDR_PIN);

  Serial.print("Light Level: ");
  Serial.print(lightValue);

  if (lightValue < 2000) {
    Serial.println(" → DARK");
    digitalWrite(33,HIGH);
    
  } else {
    Serial.println(" → BRIGHT");
    digitalWrite(33,LOW);
   
  }
  delay(500);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" | Humidity: ");
  Serial.println(humidity);
}