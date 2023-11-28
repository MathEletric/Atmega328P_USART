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

Registrador de dados:

<img src="/imagens/imagens_texto/usart_5.png">

Registrador de configuração A:

<img src="/imagens/imagens_texto/usart_6.png">

*Bit 6 e 7:* Assumem 1 quando a transmissão e/ou recepção é completada.  
*Bit 5:* Indica que o registrador de dados está vazio. Em dois casos isso acontece: dado é apagado após leitura e dado é apagado após transmitido.  
*Bit 4:* Erro de frame. Quando não envia STOP BIT, por exemplo.  
*Bit 3:* Erro de recepção. Quando o registrador de entrada de dados está cheio, e chega mais bit.  
*Bit 2:* Erro de bit de paridade, ou seja, pacote corrompido.  
*Bit 1 e 0:* Modo velocidade dobrada e multi-processador.  

Registrador de configuração B:

<img src="/imagens/imagens_texto/usart_7.png">

*Bit 6 e 7:* Habilita fonte de interrupção ao terminar a tranmissão ou recepção.  
*Bit 5:* Habilita fonte de interrupção quando o registrador de dados está vazio.  
*Bit 4:* Habilita a recepção.  
*Bit 3:* Habilita a transmissão.  
*Bit 2:* Sinaliza a condição de frame de 9 bits.  
*Bit 1 e 0:* São armazenados o nono bit, na recepção e na transmissão.  

Registrador de configuração C:

<img src="/imagens/imagens_texto/usart_8.png">

*Bit 6 e 7:* Modo de transmissão.  
*Bit 4 e 5:* Desabilita ou habilita o tipo de paridade.  
*Bit 3:* Quantidade de STOP BIT.  

<img src="/imagens/imagens_texto/usart_9.png">

*Bit 1 e 2:* Indica o tamanho dos caracteres. Dependem do bit 2 do registrador B.
*Bit 0:* Indica a borda do clock do modo síncrono.

O registrador UBRR0L e UBRR0H contêm o valor de contagem que gera a taxa de transmissão em bits/s.




