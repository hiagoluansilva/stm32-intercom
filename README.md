# STM32 InterCom — ADC → USART → DAC

🇧🇷 **Português** | 🇺🇸 [English](#english)

---

## Português

Sistema de intercomunicação em tempo real para STM32F4xx que captura áudio via ADC, transmite via USART e reproduz via DAC.

### O que faz
- Captura sinal analógico no pino **PA0** com ADC1 a **8 kHz**, resolução de **12 bits**
- Transmite as amostras pelo **USART1** a **115200 bps** (TX: PA9, RX: PA10)
- Recebe amostras do canal oposto e reproduz via **DAC**

### Hardware
| Periférico | Pino | Função |
|---|---|---|
| ADC1 CH0 | PA0 | Entrada analógica (microfone) |
| USART1 TX | PA9 | Transmissão serial |
| USART1 RX | PA10 | Recepção serial |
| DAC CH1 | PA4 | Saída analógica (alto-falante) |

### Parâmetros
- Taxa de amostragem: **8 kHz**
- Resolução ADC/DAC: **12 bits**
- Baud rate: **115200 bps**
- Microcontrolador: STM32F4xx (Atollic TrueSTUDIO)

---

## English

Real-time intercom system for STM32F4xx that captures audio via ADC, transmits via USART, and plays back via DAC.

### What it does
- Captures analog signal on pin **PA0** with ADC1 at **8 kHz**, 12-bit resolution
- Transmits samples over **USART1** at **115200 bps** (TX: PA9, RX: PA10)
- Receives samples from the opposite unit and plays back through **DAC**

### Hardware
| Peripheral | Pin | Function |
|---|---|---|
| ADC1 CH0 | PA0 | Analog input (microphone) |
| USART1 TX | PA9 | Serial transmission |
| USART1 RX | PA10 | Serial reception |
| DAC CH1 | PA4 | Analog output (speaker) |

### Parameters
- Sample rate: **8 kHz**
- ADC/DAC resolution: **12 bits**
- Baud rate: **115200 bps**
- MCU: STM32F4xx (Atollic TrueSTUDIO)
