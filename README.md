# Atmega328P_USART

__USART: Universal Synchronous and Asynchronous serial Receiver and Transmiter.__

Na comunicação serial, os participantes enviam e recebem ao mesmo tempo, conceito chamado de *full duplex*. Interessante para longas distâncias por ser robusta ao ruído, quando comparado a comunicação paralela. Exemplos de comunicação paralela é o tipo de comunicação entre elementos de dentro de um circuito integrado. Para comunicação serial, um exemplo é a internet.

<img src="/imagens/imagens_texto/usart_1.png">

Na comunicação síncrona, os envolvidos estão sincronizados por um sinal de clock externo.
Na comunicação assíncrona, os envolvidos geram seu próprio clock. A imagem acima demonstra a comunicação entre quaisquer dispositivos que tenham implementado um modulo USART.

Como estamos falando de comunicação serial, estamos de antemão falando da camada de enlace, ou *Data Link Layer*, onde dados são empacotados no *frame*. O padrão USART permite enviar frames de 5 a 9 bits, além dos bits de dado:

<img src="/imagens/imagens_texto/usart_2.png">

A taxa de transmissão deve ser a mesma no transmissor e no receptor.

<img src="/imagens/imagens_texto/usart_3.png">



__Comunicação SPI__

Sincronia por sinal externo de clock. Enquanto o master envia para o slave, o slave envia
para o master, ou seja, do tipo MISO e MOSI. Pode atuar com mais de um escravo. Interessante em curtas distâncias.


