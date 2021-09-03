
#include<stdio.h>
#include <time.h>
#include <math.h>
#include<stdlib.h>
#include "auxiliar.h"
//função para calcular um número aleatório em um intervalo de dois números, recebe um fator de aleatoriedade e o dois valores de intervalo, retorna um número aleatório que vai de -x a x, sendo x o primeiro valor da entrada, multiplicado pela diferença do intervalo.

int NumeroAleatorio(int numero,int inicial, int final){
int total = abs(inicial - final);
int numeral = (rand() % (numero*2+1) - numero)*total/50;
return numeral;}

//função recursiva para preencher o array. ela recebe o primeiro e o ultimo indice do array e o próprio array e um fator multiplicativo. Não retorna nada mais preenche o elemento do meio do array com a média das extremidades acresido de um valor aleatório, utilizando a função anterior para calcular o número aleatório.
int calcularray(int fator,int esquerda, int direita, int* lista){
  if( abs(esquerda-direita) ==1 ||esquerda==direita){
    return 0;
  }
int meio = (esquerda+direita)/2;
lista[meio]=((lista[esquerda] + lista[direita])/2)+ NumeroAleatorio(fator,esquerda, direita);

calcularray(fator,esquerda,meio,lista);
calcularray(fator,direita,meio,lista);

return 0;}
