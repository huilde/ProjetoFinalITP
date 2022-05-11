# Projeto Final ITP

Projeto desenvolvido por : Huilde Viana Júnior e Jean Kalyson Pereira de Oliveira

## Implementação do algoritmo de deslocamento do ponto do meio (midpoint displacement algorithm)

### O programa desenvolvido foi uma implementação em C do algoritmo citado anteriomente.

O projeto consiste em um programa que cria imagens no formato PPM com fins de geração de terrenos em formas aleatórias. No presente projeto, foi utilizado a linguagem c, onde suas funcionalidades foram feitas com base no uso de matrizes, manipulação de arquivos, recursão, structs, gestão de memória, dentre outras implementações mais básicas. Para fins de criação dos contornos das montanhas foi utilizado o algoritmo de descolamento do ponto do meio(midpoint displacement algorithm) em forma recursiva para preenchimento de um array alocado dinamicamente. Após isso, temos o preenchimento da matriz principal também alocada dinamicamente, com condições que permitem a variação da cores selecionadas para compor a matriz, utilizando o sistema de cores RGB utilizando o tipo Pixel. Por fim, temos a impressão da matriz no arquivo previamente definido. Como implemento adicional, temos a projeção de uma outra montanha, o sombreamento nas bordas da montanha superior e a geração de estrelas.

## Imagens

Imagem gerada pelo programa desenvolvido

![Imagem do projeto](https://huilde.github.io/huilde/imagemprojeto.jpg)

## Link

#### Para acessar o repositório do projeto no github acesso o link

acesse por aqui: [Github](https://github.com/huilde/ProjetoFinalITP)

## Contribuição no projeto

### neste tópico falaremos sobre a contribuição de cada um dos integrantes no densenvolvimento do projeto

Huilde: Desenvolvimento das funções do arquivo auxiliar.c, as quais geram o array de deslocamento. alocação dinâmica da matriz , criação da struct pixele geração da montanha secundária.

Jean: Tratamento dos dados recebidos no momento da compilação, implementações adicionais como geração de estrelas e pode passar a cor da montanha principal como parâmetro, Impressão da matriz em um arquivo e geração dos primeiros e últimos valores do array.

## Como compilar

Após fazer o donwload do do arquivo .zip, você poderá <br/>

rodar o programa através do prompt do comando do seu computador.

você deverá ir até a pasta selecionada e <br/>

utilizar o seguinte comando:

`$ gcc main.c auxiliar.c -o executavel`<br/>

Dessa forma você gerará um arquivo executável na própria pasta em que os arquivos se encontram</br>

Para executar o arquivo basta selecionar o arquivo através do compilador o programa pode receber os seguintes parâmetros:

`$ /executavel -d 17 -o name.ppm -c 155 155 155 `. <br/>

Sendo respectivamente o fator de alteração do terreno, o nome do arquivo gerado e a cor da montanha principal<br>

o programa também poderá ser rodado sem a passagem de parâmetros, utilizando valores default da seguinte maneira:

`$ /executavel `.

Caso algum dos parâmetros não seja passado ele subistituirá apenas o que foram passados e utilizara os valores default para os que não foram passados.

### observação: o fator de deslocamento se dá de forma percentual ao tamanho do array, dessa forma é recomendado que não se utilize valores maiores do que 100 para a criação da imagem, e valores muito pequenos tendem a gerar imagens com pouca alteração.

## Considerações finais

O projeto teve um desenvolvimento bastante proveitoso, sendo possível utilizar os conceitos estudados ao longo da disciplina. Acreditamos que o resultado final foi bastante satisfatório e o desenvolvimento foi algo muito bom de ser feito. De maneira geral acreditamos que o projeto foi algo bom de ser desenvolvido, pois ele ensinou coisas que não podem ser aprendidas apenas com os exercícios. Por exemplo como testar o seu programa e como organizá-lo em arquivos diferentes. E ao final do trabalho ainda conseguimos criar algo "tangível", ou seja, tanto pessoas sem conhecimentos prévios podem utilizar o programa e ver o seu funcionamento, mesmo sem entender os códigos por trás da aplicação.
