#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
// variavél com o nome do arquivo
char nameFile[40];
//fator de multiplicação e cor da montanha principal
int fator = 15, a, color1[3] = {119, 130, 186};
// ponteiro para o arquivo
FILE *ponteiro;
int main(int argc, char *argv[])
{
    // tratamento dos dados passados na compilação.
    if (argc > 1)
    {
        int i;
        for (i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "-d") == 0)
            {
                fator = atoi(argv[i + 1]);
            }

            if (strcmp(argv[i], "-c") == 0)
            {
                int j;
                for (j = 0; j < 3; j++)
                {
                color1[j] = atoi(argv[i + 1]);
            }
        }

        if (strcmp(argv[i], "-o") == 0)
        {
            strcpy(nameFile, argv[i + 1]);
            a++;
        }
    }
}
if (a == 0)
{

  //variavél default para o nome do arquivo
    char teste[40] = "arquivo.ppm";
    strcpy(nameFile, teste);
}
//adicionando aleatoriedade a função rand
srand(time(NULL));

// ponteiro contendo o arquivo
ponteiro = fopen(nameFile, "w");
int linha;
int coluna;
//alocando o vetor dinamicamente
int *cadeia;
cadeia = malloc(sizeof(int) * 1001);
pixel **matriz;
int linhamatriz;

//alocando a matriz dinamicamente

matriz = malloc(sizeof(pixel) * 1001);
for (linhamatriz = 0; linhamatriz < 1001; linhamatriz++)
    matriz[linhamatriz] = malloc(1001 * sizeof(pixel));
// gerando aleatoriamente o primeiro e o último valor do vetor
cadeia[0] = rand() % 500 + 250;
cadeia[1000] = rand() % 500 + 250;
calcularray(fator, 0, 1000, cadeia);

//inicializando o documento no formato correto.
fprintf(ponteiro, "P3\n1000 1000\n255\n");

//atribuindo cores para a montanha
for (linha = 0; linha < 1000; linha++)
{
    for (coluna = 0; coluna < 1000; coluna++)
    {

        if (linha > cadeia[coluna])
        {
            //atribuindo cores para a montanha
            matriz[linha][coluna].r = color1[0];
            matriz[linha][coluna].g = color1[1];
            matriz[linha][coluna].b = color1[2];
            //adicionando contraste
            if (linha < cadeia[coluna] + 10 && linha > cadeia[coluna])
            {
                matriz[linha][coluna].r = color1[0] - 10;
                matriz[linha][coluna].g = color1[1] - 10;
                matriz[linha][coluna].b = color1[2] - 10;
            }
        }
        else
        {
            matriz[linha][coluna].r = 159;
            matriz[linha][coluna].g = 178;
            matriz[linha][coluna].b = 255;
        }
    }
}
//liberando a memória
free(cadeia);
// criando montanha menor.
int *cadeiaMenor;
cadeiaMenor = calloc(1000, sizeof(int));
// gerando aleatoriamente o primeiro e o último valor do vetorMenor.
cadeiaMenor[0] = 800 + rand() % 100;
cadeiaMenor[1000] = 800 + rand() % 100;
int fatorMenor = fator / 3;
calcularray(fator, 0, 1000, cadeiaMenor);
//colocando a montaha menor na matriz.
for (linha = 0; linha < 1000; linha++)
{
    for (coluna = 0; coluna < 1000; coluna++)
    {

        if (linha > cadeiaMenor[coluna])
        {

            matriz[linha][coluna].r = 40;
            matriz[linha][coluna].g = 40;
            matriz[linha][coluna].b = 40;

            if (linha < cadeiaMenor[coluna] + 10 && linha > cadeiaMenor[coluna])
            {
                matriz[linha][coluna].r = 30;
                matriz[linha][coluna].g = 30;
                matriz[linha][coluna].b = 30;
            }
        }
    }
}
//criando estrelas
int lin, col, i, j, aum = 1, dec, estrela, tam;
for (estrela = 0; estrela < 500; estrela++)
{
    tam = rand() % 10;
    lin = rand() % 700;
    col = rand() % 950;

    //verifica se a ponta máxima da estrela toca o terreno
    if (matriz[lin + tam][col].r != color1[0] && matriz[lin + tam][col].r != 30 && matriz[lin + tam][col].r != color1[0] - 10 && matriz[lin + tam][col].r != 40)
    {
        for (i = 0; i < tam; i++)
        {
            if (aum < tam)
            {
                for (j = 0; j < aum; j++)
                {
                    matriz[lin + i][col + j].r = 255;
                    matriz[lin + i][col + j].g = 255;
                    matriz[lin + i][col + j].b = 255;
                }
                aum = aum + 2;
                col--;
                dec = aum;
            }
            else
            {
                for (j = 0; j < dec; j++)
                {
                    matriz[lin + i][col + j].r = 255;
                    matriz[lin + i][col + j].g = 255;
                    matriz[lin + i][col + j].b = 255;
                }
                dec = dec - 2;
                col++;
            }
        }
        aum = 1;
    }
}

// imprimindo matriz no arquivo
for (linha = 0; linha < 1000; linha++)
{
    for (coluna = 0; coluna < 1000; coluna++)
    {
        fprintf(ponteiro, "%d %d %d\n", matriz[linha][coluna].r,
                matriz[linha][coluna].g, matriz[linha][coluna].b);
    }
}
free(cadeiaMenor);
free(matriz);
fclose(ponteiro);
return 0;
}
