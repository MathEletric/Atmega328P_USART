#define F_CPU 16000000
#define BAUD 9600
#define MY_UBRR0 (F_CPU/16*BAUD) - 1

#include<avr/io.h>
#include<util/delay.h>

//Inicia USART
void USART_init(unsigned int ubrr){
    UBRR0H = (unsigned char)(ubrr>>8); //Recebe MY_BOUD. Ajusta a taxa de transmissão.
    UBRR0L = (unsigned char)(ubrr);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0); //Habilita transmissor e o receptor.
    UCSR0B |= (1<<RXCIE0); //Habilita interrupção.

    UCSR0C = (1<<USBS0)|(3<<UCSZ00); //Ajusta o formato do frame: 8 bits de dados e 2 de parada.    
}

//Função para envio o frame
void USART_transmit(unsigned char data){
    while(!((UCSR0A)&(1<<UDRE0))); //Espera a limpeza do registrador.
    UDR0 = data; //Coloca o dado no registrador de envio.
}

void USART_receive(){
    while(!((UCSR0A)&(1<<RXC0))); //Espera a recepção do dado.
    return UDR0; // Lê o dado recebido e retrona
}

void main(){
    USART_init(MY_UBRR0);
    while(1){
        USART_transmit('O que quiser enviar');
    }
}













