const int trigPin = 9;     // Pin Trigger
const int echoPin = 10;    // Pin Echo

long duration;
float distance;

void setup() {
  Serial.begin(9600);              
  pinMode(trigPin, OUTPUT);        
  pinMode(echoPin, INPUT);         
}

void loop() {
  // Enviar un pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir duración del pulso de eco
  duration = pulseIn(echoPin, HIGH);

  // Calcular distancia en centímetros
  distance = (duration * 0.0343) / 2;

  // Mostrar distancia
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
