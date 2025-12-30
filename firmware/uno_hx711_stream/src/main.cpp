#include <Arduino.h>
#include "HX711.h"

static const int PIN_DOUT = 3;
static const int PIN_SCK  = 2;

HX711 scale;

static bool stream_on = true;
static long raw_zero = 0;
static float counts_per_N = 1.0f;
static uint16_t rate_hz = 50;

long read_raw() {
  return scale.read(); // raw counts
}

void setup() {
  Serial.begin(115200);
  delay(200);

  scale.begin(PIN_DOUT, PIN_SCK);
  // Optional: scale.set_gain(128); // A channel gain 128 (default)

  Serial.println("ts_ms,raw,force_N");
  Serial.println("Send: T (tare), C <known_mass_kg>, P (print), S (toggle stream)");
}

void loop() {
  // simple command handling
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "S") stream_on = !stream_on;

    if (cmd == "T") {
      raw_zero = read_raw();
      Serial.print("raw_zero="); Serial.println(raw_zero);
    }

    if (cmd == "P") {
      Serial.print("raw_zero="); Serial.print(raw_zero);
      Serial.print(" counts_per_N="); Serial.println(counts_per_N, 6);
    }

    if (cmd.startsWith("C")) {
      // C <known_mass_kg>
      float m = cmd.substring(1).toFloat();
      float F = m * 9.80665f;
      long raw_m = read_raw();
      counts_per_N = (raw_m - raw_zero) / F;
      Serial.print("counts_per_N="); Serial.println(counts_per_N, 6);
    }
  }

  // stream
  static uint32_t last_ms = 0;
  uint32_t now = millis();
  uint32_t period_ms = 1000UL / rate_hz;

  if (stream_on && (now - last_ms >= period_ms)) {
    last_ms = now;
    long raw = read_raw();
    float forceN = (raw - raw_zero) / counts_per_N;

    Serial.print(now); Serial.print(",");
    Serial.print(raw); Serial.print(",");
    Serial.println(forceN, 4);
  }
}
