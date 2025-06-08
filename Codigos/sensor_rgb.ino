#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Sensor RGB TCS34725 detectado.");
  } else {
    Serial.println("No se encontró el sensor TCS34725. Verifica la conexión.");
    while (1); // Detener si no hay sensor
  }
}

void loop() {
  uint16_t r, g, b, c;
  float r_norm, g_norm, b_norm;

  tcs.getRawData(&r, &g, &b, &c);

  // Normalizar los valores RGB
  r_norm = (float)r / c;
  g_norm = (float)g / c;
  b_norm = (float)b / c;

  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" => Color: ");

  // Clasificación simple de color
  if (r_norm > 0.4 && g_norm < 0.3 && b_norm < 0.3) {
    Serial.println("Rojo");
  } else if (g_norm > 0.4 && r_norm < 0.3 && b_norm < 0.3) {
    Serial.println("Verde");
  } else if (b_norm > 0.4 && r_norm < 0.3 && g_norm < 0.3) {
    Serial.println("Azul");
  } else if (r_norm > 0.3 && g_norm > 0.3 && b_norm < 0.2) {
    Serial.println("Amarillo");
  } else if (r_norm > 0.3 && g_norm > 0.3 && b_norm > 0.3) {
    Serial.println("Blanco o claro");
  } else {
    Serial.println("Color desconocido");
  }

  delay(1000);
}
