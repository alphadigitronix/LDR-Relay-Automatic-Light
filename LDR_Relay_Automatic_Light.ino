/*
 * ALPHA DIGITRONIX SOLUTIONS
 * ADS Arduino Inventor Kit
 *
 * PROJECT 27: LDR RELAY AUTOMATIC LIGHT
 *
 * LDR Module:
 * VCC -> 5V
 * GND -> GND
 * AO  -> A0
 *
 * Relay Module:
 * VCC -> 5V
 * GND -> GND
 * IN  -> D8
 *
 * Status LED:
 * D6 -> 330 ohm resistor -> LED -> GND
 *
 * Example thresholds:
 * DARK   <= 400 : Light ON
 * BRIGHT >= 600 : Light OFF
 */

#define LDR_PIN A0
#define RELAY_PIN 8
#define STATUS_LED 6

#define DARK_THRESHOLD 400
#define BRIGHT_THRESHOLD 600

bool lightState = false;

void setLight(bool state) {

  lightState = state;

  // Most common relay modules are active LOW
  digitalWrite(RELAY_PIN, state ? LOW : HIGH);

  digitalWrite(STATUS_LED, state ? HIGH : LOW);
}

void setup() {

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);

  setLight(false);

  Serial.begin(9600);

  Serial.println("--------------------------------");
  Serial.println("ALPHADIGITRONIX SOLUTIONS");
  Serial.println("LDR RELAY AUTOMATIC LIGHT");
  Serial.println("--------------------------------");
}

void loop() {

  int lightValue = analogRead(LDR_PIN);

  Serial.print("LDR Value: ");
  Serial.print(lightValue);
  Serial.print(" | ");

  // DARK CONDITION
  if (!lightState &&
      lightValue <= DARK_THRESHOLD) {

    setLight(true);

    Serial.println("DARK -> LIGHT ON");
  }

  // BRIGHT CONDITION
  else if (lightState &&
           lightValue >= BRIGHT_THRESHOLD) {

    setLight(false);

    Serial.println("BRIGHT -> LIGHT OFF");
  }

  else {

    Serial.print("LIGHT: ");
    Serial.println(lightState ? "ON" : "OFF");
  }

  delay(500);
}