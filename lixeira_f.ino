#define TRIG_PIN 26
#define ECHO_PIN 25

void setup() {
  Serial.begin(115200);           // Monitor Serial em 115200 baud
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Sensor ultrassônico HC-SR04 iniciado!");
}

void loop() {
  // Dispara o pulso
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Lê o tempo de eco
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calcula distância em cm (velocidade do som ≈ 343 m/s)
  float distance_cm = duration * 0.0343 / 2;

  // Mostra no Serial Monitor
  Serial.printf("Distância: %.2f cm\n", distance_cm);

  delay(500);  // Atualiza a cada meio segundo
}
