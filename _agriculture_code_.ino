#define SOIL_PIN 34
#define RELAY_PIN 26

int threshold = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {

  int moisture = analogRead(SOIL_PIN);

  Serial.print("Moisture Value: ");
  Serial.println(moisture);

  if (moisture < threshold) {
    Serial.println("Soil Dry -> Pump ON");
    digitalWrite(RELAY_PIN, HIGH);
  }
  else {
    Serial.println("Soil Wet -> Pump OFF");
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(1000);
}