O objetivo do dia era fazer alguns testes com o display LCD e preferencialmente com array de bytes para os proximos passos.

para montar o ciruito foi utilizado:

1 - Potenciometro;
1 - Display LCD 16x2;
N - Fios para conectar os itens;
1 - Arduino UNO;
1 - Bread/Proto board.

Base: http://arduino.cc/en/Tutorial/LiquidCrystal

O código de exemplo já nós ajuda em diversos pontos:
 - como definir o tipo do disply -> lcd.begin(16, 2);
 - Definir a linha que utilizaremos -> lcd.setCursor(15, 0);
   Se pensarmos em uma matriz 16x2, o primeiro valor (e.g 15), representa a posição na linha 0
   e o segundo valor (e.g 0), representa a linha.

Ok, agora usamos o código auto-explicativo (thanks, Arduino Team) para escrever uma simples brincadeira 
emulando um progress bar - sem utilizar array de bytes diretamente (por enquanto).

O proximo passo é substituir essa gambiarra por um array de bytes e trocar o texto hello world
por 5 minutos, o array de bytes deve remover um bloco conforme esse tempo divido por 16. Algo +- assim:

5 minutos == 300 segs - 300/16 = 18, ou seja, a cada 18 segundos, um bloco é retirado.
[continuar documento....]