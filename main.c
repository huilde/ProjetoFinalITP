#include <stdio.h>
#include <time.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
#include "auxiliar.h"
char name[40];
int fator;
FILE *ponteiro;
int main(int argc, char* argv[]){
if(argc==1){
char teste[40]="arquivo.ppm";
strcpy (name,teste );
 fator = 15;}
 else if(argc>1){
   
 }
srand(time(NULL));

ponteiro = fopen(name,"w");
int linha;
int coluna;

int* cadeia;
cadeia = malloc(sizeof(int)*1001);
pixel** matriz;
int linhamatriz;

//alocando a matriz dinamicamente

matriz = malloc(sizeof(pixel)*1001);
for ( linhamatriz=0; linhamatriz < 1001; linhamatriz++)
   matriz[linhamatriz] = malloc (1001 * sizeof (pixel)) ;

cadeia[0]= rand()%500+ 250;
cadeia[1000] = rand()%500+250;
calcularray(fator,0, 1000,cadeia);
fprintf(ponteiro,"P3\n 1000\n1000\n255\n");
for(linha=0;linha<1000;linha++){
	for(coluna =0;coluna<1000;coluna++){

		if(linha>cadeia[coluna]){
      //atribuindo cores para a montanha
    matriz[linha][coluna].r = 119;
    matriz[linha][coluna].g = 130;
    matriz[linha][coluna].b = 186;
		}
		else{
    matriz[linha][coluna].r = 159;
    matriz[linha][coluna].g = 178;
    matriz[linha][coluna].b = 255;
	
		}
	}
  }
free(cadeia);
for(linha=0;linha<1000;linha++){
	for(coluna =0;coluna<1000;coluna++){
fprintf(ponteiro,"%d %d %d\n",matriz[linha][coluna].r,
matriz[linha][coluna].g,matriz[linha][coluna].b);
	}

}
free(matriz);
fclose(ponteiro);
return 0;}
