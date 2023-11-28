# Atmega328P_USART

__USART: Universal Synchronous and Asynchronous serial Receiver and Transmiter.__

Na comunicação serial, os participantes enviam e recebem ao mesmo tempo, conceito chamado de *full duplex*. Interessante para longas distâncias por ser robusta ao ruído, quando comparado a comunicação paralela. Exemplos de comunicação paralela é o tipo de comunicação entre elementos de dentro de um circuito integrado. Para comunicação serial, um exemplo é a internet.

<img src="/imagens/imagens_texto/usart_1.png">

Na comunicação síncrona, os envolvidos estão sincronizados por um sinal de clock externo.
Na comunicação assíncrona, os envolvidos geram seu próprio clock. A imagem acima demonstra a comunicação entre quaisquer dispositivos que tenham implementado um modulo USART.

Como estamos falando de comunicação serial, estamos de antemão falando da camada de enlace, ou *Data Link Layer*, onde dados são empacotados no *frame*. O padrão USART permite enviar frames de 5 a 9 bits. Além dos bits de dados, vemos:

<img src="/imagens/imagens_texto/usart_2.png">

A taxa de transmissão deve ser a mesma no transmissor e no receptor. O valor da taxa de transmissão é definido pelo registrador *UBRR0*.

<img src="/imagens/imagens_texto/usart_3.png">

Segue o diagrama de blocos da USART no atmega328P:

<img src="/imagens/imagens_texto/usart_4.png">

Vemos no bloco *Clock Generator* que a partir do registrador UBRR0 e da frequência de oscilação do uC (OSC), geramos a taxa de transmissão ou *Baund Rate Generator* para comunicação assíncrona. Para comunicação síncrona, usamos o pino *XCKn* como fonte de clock externo. Os pinos TxDn e RxDn são os responsáveis pela transmissão e recepção, respectivamente.

A transmissão ocorre da seguinte maneira:
1) O dado é escrito no registrador *UDRn* de 8 bits;
2) O dado é copiado para o registrador de deslocamento *Transmit Shift Register*. O qual a cada pulso de clock será deslocado;
3) Bit é enviado a cada clock;

Na prática, observamos que o registrador UDRn tem o mesmo nome, tanto na transmissão,quanto na recpção, e ambos possuem o mesmo endereço.0 Porém, ao escrever nele, efetivamente é preenchido o registrador da transmissão. Caso seja lido, efetivamente é lido o registrador da recepção.

Os registradores de configuração do periférico USART são os *UCSRnA*, *UCSRnB* e *UCSRnC*.

__Registradores da USART__





