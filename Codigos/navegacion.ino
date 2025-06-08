// Archivo: robot_navegacion.ino
#define TRIG_PIN 9
#define ECHO_PIN 10
const int SENSOR_R = A0;
const int SENSOR_G = A1;
const int SENSOR_B = A2;
const int MOTOR_IZQ = 3;
const int MOTOR_DER = 5;

int umbral_rojo = 150;
int umbral_verde = 150;
int umbral_azul = 150;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_IZQ, OUTPUT);
  pinMode(MOTOR_DER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duracion = pulseIn(ECHO_PIN, HIGH);
  long distancia = duracion * 0.034 / 2;

  int r = analogRead(SENSOR_R);
  int g = analogRead(SENSOR_G);
  int b = analogRead(SENSOR_B);
  String color;

  if (r > umbral_rojo && g < 100 && b < 100) {
    color = "ROJO";
  } else if (g > umbral_verde && r < 100 && b < 100) {
    color = "VERDE";
  } else if (b > umbral_azul && r < 100 && g < 100) {
    color = "AZUL";
  } else {
    color = "NINGUNO";
  }

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Color: ");
  Serial.println(color);

  if (distancia < 10) {
    detener();
    girarDerecha();
  } else if (color == "ROJO") {
    detener();
  } else if (color == "VERDE") {
    avanzar();
  } else if (color == "AZUL") {
    girarIzquierda();
  } else {
    avanzar();
  }
  delay(200);
}

void avanzar() {
  analogWrite(MOTOR_IZQ, 200);
  analogWrite(MOTOR_DER, 200);
}

void detener() {
  analogWrite(MOTOR_IZQ, 0);
  analogWrite(MOTOR_DER, 0);
}

void girarDerecha() {
  analogWrite(MOTOR_IZQ, 200);
  analogWrite(MOTOR_DER, 0);
  delay(500);
}

void girarIzquierda() {
  analogWrite(MOTOR_IZQ, 0);
  analogWrite(MOTOR_DER, 200);
  delay(500);
}
