# stm32-intercom

Intercomunicador bidirecional desenvolvido para a disciplina de Sistemas Microprocessados I.

## Descrição

Projeto de comunicação de voz entre dois módulos STM32F4xx utilizando o periférico USART como canal de transmissão. O sinal de áudio é capturado pelo ADC, transmitido serialmente e reconstruído pelo DAC na outra ponta.

## Hardware

- Microcontrolador: STM32F4xx
- Entrada: Microfone de eletreto (PA0 — ADC1 canal 0)
- Saída: DAC

## Parâmetros

| Parâmetro | Valor |
|-----------|-------|
| Taxa de amostragem | 8.000 Hz |
| Taxa de transmissão (USART1) | 115.200 bps |
| Resolução ADC | 12 bits |
| Pinos Tx/Rx | PA9 / PA10 |

## Periféricos utilizados

- **ADC1** — conversão contínua, alinhamento à direita, 480 ciclos de amostra
- **USART1** — transmissão/recepção serial
- **TIM** — base de tempo para taxa de amostragem
- **NVIC** — tratamento de interrupções

## Estrutura do projeto

```
InterCom/
├── src/
│   ├── main.c
│   ├── system_stm32f4xx.c
│   ├── startup_stm32f446xx.s
│   └── tiny_printf.c
├── Drivers/       # STM32F4xx HAL drivers
└── stm32_flash.ld
```

## IDE

Atollic TrueSTUDIO 9.3 / STM32CubeIDE

## Autores

- Vitor Becker — Turma 4324
- Professor: Marcos Zuccolotto

## Escola

Centro Tecnológico Liberato — Novo Hamburgo/RS
