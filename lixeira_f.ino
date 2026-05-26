#include <WiFi.h>

#define TRIG_PIN 26
#define ECHO_PIN 25

// ==================== CREDENCIAIS Wi-Fi ====================
const char* NomeRede = "NOME_DA_REDE";          // ← Nome da sua rede Wi-Fi
const char* SenhaRede = "SENHA_DA_REDE";   // ← Senha da sua rede Wi-Fi
// ===========================================================

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("\n=== Lixeira Inteligente - Teste Final ===");
  Serial.println("Conectando ao Wi-Fi...");

  WiFi.begin(NomeRede, SenhaRede);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Wi-Fi CONECTADO!");
  Serial.print("📡 IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("=====================================\n");
}

void loop() {
  // Leitura do sensor ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = duration * 0.0343 / 2.0;

  // Mostra no Serial Monitor
  Serial.printf("Distância: %.2f cm", distance_cm);

  // Status do Wi-Fi
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("   ✅ Wi-Fi OK");
  } else {
    Serial.println("   ❌ Wi-Fi DESCONECTADO");
  }

  delay(500);  // Atualiza a cada meio segundo
}
