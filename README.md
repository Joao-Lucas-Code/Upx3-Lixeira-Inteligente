# 🗑️ Lixeira Inteligente - Smart Waste Management

![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)
![Hardware](https://img.shields.io/badge/Hardware-ESP32%20%7C%20HC--SR04-blue)
![Platform](https://img.shields.io/badge/Platform-Firebase%20%7C%20React%20Native-success)
![Institution](https://img.shields.io/badge/Facens-Engenharia%20de%20Computação-red)

> Projeto de IoT para **Cidades Inteligentes e Sustentabilidade**, desenvolvido para a disciplina de UPx (Usina de Projetos Experimentais) - 2026.

---

## 📸 O Projeto

<div align="center">
  <img src="images/lixeira_final.jpg" alt="Protótipo Final" width="550">
</div>

### 🎯 O Problema
A coleta de lixo urbana tradicional usa rotas fixas, gerando desperdício de combustível, tempo e emissão desnecessária de poluentes. Muitas lixeiras ficam vazias enquanto outras transbordam.

### 💡 A Solução
Um ecossistema completo de **Smart Waste Management** que monitora em tempo real o nível de preenchimento das lixeiras e gera **rotas inteligentes** de coleta automaticamente.

---

## 🛠️ Hardware e Componentes

| Componente              | Função                          |
|-------------------------|---------------------------------|
| **ESP32 Dev Module**    | Microcontrolador com Wi-Fi      |
| **HC-SR04**             | Sensor ultrassônico (distância) |
| **Protoboard + Jumpers**| Conexões do circuito            |
| **Fonte 5V**            | Alimentação via USB             |

### 🔌 Esquema de Ligação (Pinout)

| Sensor HC-SR04 | ESP32          |
|----------------|----------------|
| **VCC**        | VIN (5V)       |
| **GND**        | GND            |
| **Trig**       | GPIO 26 (D26)  |
| **Echo**       | GPIO 25 (D25)  |

**Atenção:** Recomendado usar divisor de tensão no pino Echo (5V → 3.3V).

---

## 📱 Software e Arquitetura

- **Microcontrolador:** ESP32 enviando dados via Wi-Fi
- **Banco de Dados:** Firebase Realtime Database
- **Aplicativo Móvel:** React Native (visualização em tempo real + mapas)
- **Roteirização Inteligente:** Google Maps API (prioriza apenas lixeiras ≥ 75% cheias)

**Funcionalidades principais:**
- Monitoramento contínuo do nível de resíduos
- Envio automático para a nuvem
- Dashboard com status das lixeiras
- Geração automática de rota otimizada de coleta

---

## 🚀 Como Executar o Projeto (Hardware)

### Pré-requisitos
- Arduino IDE instalado
- Placa selecionada: **ESP32 Dev Module**
- Sensor HC-SR04 conectado conforme pinout acima

### Instalação
1. Clone este repositório:
   ```bash
   git clone https://github.com/Joao-Lucas-Code/Lixeira-Inteligente.git
