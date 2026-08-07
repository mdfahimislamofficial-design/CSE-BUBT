#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Sensor Pins
const int MQ2_PIN = A0;
const int VIB_PIN = 2;

// Output Pins
const int GREEN_LED = 8;
const int YELLOW_LED = 9;
const int BLUE_LED = 10;
const int RED_LED = 11;
const int BUZZER = 12;

// Thresholds
const float TEMP_LIMIT = 35.0;   
const int GAS_LIMIT = 250;    
const float HUM_LIMIT = 80.0;  

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(VIB_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, HIGH);
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int gasValue = analogRead(MQ2_PIN);
  int vibration = digitalRead(VIB_PIN);

  bool heatAlert = (temp >= TEMP_LIMIT);
  bool gasAlert = (gasValue >= GAS_LIMIT);
  bool vibrationAlert = (vibration == HIGH);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  if (!heatAlert && !gasAlert && !vibrationAlert) {
    digitalWrite(GREEN_LED, HIGH);
  }

  if (heatAlert) {
    digitalWrite(RED_LED, HIGH);
  }

  if (vibrationAlert) {
    digitalWrite(YELLOW_LED, HIGH);
  }

  if (gasAlert) {
    digitalWrite(BLUE_LED, HIGH);
  }

  if (heatAlert || gasAlert || vibrationAlert) {
    digitalWrite(BUZZER, HIGH);
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C  ");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  ");

  Serial.print("Gas: ");
  Serial.print(gasValue);

  Serial.print("  Vibration: ");
  Serial.println(vibration);

  delay(1000);
}