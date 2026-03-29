//Projeto de Intercomunicador para disciplina de Sistemas Microprossessados I:
//Autor: Vítor Becker
//Turma: 4324
//Professor: Marcos Zuccolotto

/* Includes */
#include "stm32f4xx.h"//Biblioteca padrãoda família f4xx.

//Taxa de amostragem: 8000 amostras por segundo.
//Taxa de transmissão: 115200 bps.

/* Protótipos de função */
void config_adc(void);//Função para configuração do periférico ADC(Analogic-Digital Converter).
void config_usart(void);//Função para configuração do periférico USART(Universal Synchronous Assynchronous Reciever Transmitter).
void config_timer(void);//Função para configuração do periférico TIM(Timer).

/* Função principal */
int main(void)
{


  /* Loop infinito */
  while (1)
  {

  }
}

/* Configuração GPIOC e ADC1 */
void config_adc(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//Habilita clock para GPIOC.
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;//Hablilita clock para ADC1.
	//Entrada do microfone de eletreto: PC0(ADC123_IN10).
	GPIOA->MODER |= GPIO_MODER_MODER0;//Torna os dois bits em '11' para modo de entrada analogica.
	//Configurações ADC Control Register 1:
	ADC1->CR1 &= ~ADC_CR1_RES;//Resolução do AD igual a 12 bits.
	//Configurações ADC Control Register 2:
	ADC1->CR2 |= ADC_CR2_CONT;//Conversão do AD será contínua.
	ADC1->CR2 &=~ADC_CR2_ALIGN;//Alinhamento dos dados à direita.
	ADC1->CR2 |= ADC_CR2_ADON;//Liga o ADC.
	//Configurações ADC Sample Register 2: Canal Zero.
	ADC1->SMPR2 |= ADC_SMPR2_SMP0;//480 ciclos de amostra para o canal 0 do ADC1.
	//Configurações ADC Sequence Register 1/3:
    ADC1->SQR1 &= ~ADC_SQR1_L;// Somente um canal será convertido.
    ADC1->SQR3 &= ~ADC_SQR3_SQ1;// O canal 0 será o primeiro (e único) a ser convertido.
	//Configuração NVIC:
	NVIC_SetPriority(ADC_IRQn, 1);//Seta prioridade da interrupção da USART.
	NVIC_EnableIRQ(ADC_IRQn);//Habilita interrupção.

}
void config_usart(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;//Ativa clock USART1.
	//Configuração Tx e Rx: Respectivamente PA09 e PA10.
	GPIOA->MODER &=~ GPIO_MODER_MODER9;//Pino 09 para função alternativa
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->MODER &=~ GPIO_MODER_MODER10;//Pino 10 para função alternativa.
	GPIOA->MODER |= GPIO_MODER_MODER10_1;
	GPIOA->MODER &=~GPIO_MODER_MODER5;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;
	//Função alternativa:
	GPIOA->AFR[1] |= 0x0770;//Habilita os pinos PA9 e PA10 para AF7.
	//Registradores USART;
	USART1->CR1 |= USART_CR1_UE|USART_CR1_TE;//Habilita a USART, a transmissão, a recepção e a interrupção da transmissão.
	USART1->CR2 = 0x00;//Configura como um stop bit, oito bits de dados e um start bit.
	USART1->CR3 = 0x00;//Registrador que trabalha com outros protocolos. Permanescer em zero.
	USART1->BRR |= (8<<4);//Configura Baud Rate para 115200.
	USART1->BRR |= 0x0A;//0,6805 para parte fracionária.
	//Configuração NVIC:
	NVIC_SetPriority(USART1_IRQn, 2);//Seta prioridade da interrupção da USART.
	NVIC_EnableIRQ(USART1_IRQn);//Habilita interrupção.
}

void config_timer(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;//Habilita clock TIM10.
	TIM10->PSC = 9999;//Para 480 amostras do ADC, precisamos de uma frequência de 17Hz do TIM10 para aproximadamente 8000 amostras.
	TIM10->ARR = 99;
	TIM10->CR1|=TIM_CR1_CEN;//Habilita o timer.
	TIM10->CR1|=TIM_CR1_ARPE;// Habilita o timer e o modo de autoreload
	TIM10->DIER|=TIM_DIER_UIE;// Habilita interrupcao por update.
	NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0);//Seta prioridade da interrupção do TIM10.
	NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);//Habilita interrupção.
}
