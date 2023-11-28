# Atmega328P_USART

USART: Universal Synchronous and Asynchronous serial Receiver and Transmiter.

Para comunicação serial, os participantes enviam e recebem ao mesmo tempo: full duplex.
Interessante para longas distâncias por ser robusta ao ruído, quando comparado a comunicação paralela.


<img src="/imagens/imagens_texto/usart.png">


Este modulo implementa no atmega:

Comunicação serial assíncrona

Comunicação serial síncrona

__Comunicação SPI__
Sincronia por sinal externo de clock. Enquanto o master envia para o slave, o slave envia
para o master, ou seja, do tipo MISO e MOSI. Pode atuar com mais de um escravo. Interessante em curtas distâncias.


