#include <WiFi.h>

#define TRIG_PIN 26   // Pino Trig (fio cinza)
#define ECHO_PIN 25   // Pino Echo (fio cinza com resistor ou direto)

// ==================== CREDENCIAIS Wi-Fi ====================
const char* NomeRede = "NOME_DA_REDE";          // ← Mude aqui quando necessário
const char* SenhaRede = "SENHA_DA_REDE";   // ← Mude aqui quando necessário
// ===========================================================

// ==================== CONFIGURAÇÃO DA LIXEIRA ====================
const int LIMITE_CHEIA = 7;          // Distância ≤ 7cm  → LIXEIRA CHEIA!
const int LIMITE_QUASE_CHEIA = 15;   // Distância ≤ 15cm → Quase cheia...
const int DISTANCIA_MAXIMA = 27;     // Fundo da lixeira (calibrado ano passado)
// ===========================================================

float distancia;
String statusLixeira;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("\n=== Lixeira Inteligente - Versão Final ===");
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
  // === Leitura do sensor (mesma lógica do ano passado) ===
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH, 30000);        // timeout de 30ms
  distancia = duracao * 0.0343 / 2.0;

  // === Lógica de status da lixeira (igual ao código antigo) ===
  if (distancia == 0 || distancia > DISTANCIA_MAXIMA) {
    statusLixeira = (distancia == 0) ? "Falha no sensor" : "Vazia";
    distancia = DISTANCIA_MAXIMA;                    // trava no fundo da lixeira
  }
  else if (distancia <= LIMITE_CHEIA) {
    statusLixeira = "LIXEIRA CHEIA!";
  }
  else if (distancia <= LIMITE_QUASE_CHEIA) {
    statusLixeira = "Quase cheia...";
  }
  else {
    statusLixeira = "Vazia";
  }

  // === Mostra no Serial Monitor ===
  Serial.printf("Distância: %.2f cm | Status: %s\n", distancia, statusLixeira.c_str());

  delay(500);  // Atualiza a cada meio segundo
}
