# Introdução à complexidade de algoritmos

Ao longo dos estudos de programação, vimos que existem diferentes maneiras de resolver o mesmo problema, ou seja, diferentes 
algoritmos podem ser utilizados. Diante de várias possibilidades é importante analisar qual algoritmo é mais eficiente na 
resolução de um determinado problema. É aí que entra a análise da complexidade de algoritmos.

A análise da complexidade de algoritmos estuda o comportamento dos algoritmos para definir sua eficiência. Os dois aspectos mais 
analisados são o tempo de execução, ou a **complexidade de tempo** e a memória utilizada, ou a **complexidade de espaço**. 

## Complexidade de tempo

Primeiramente vamos analisar um algoritmo quanto ao tempo de execução.

### Formas de analisar a complexidade de tempo de um algoritmo
**Análise experimental/empírica**: executar o algoritmo mediante diversos tamanhos de entrada e tomar nota do tempo gasto para 
executar cada entrada, analisando os resultados posteriormente (montando gráficos, por exemplo):

Medidas de tempo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/medidas_tempo.png)

Gráfico gerado:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/grafico.png)

A partir da montagem do gráfico, pode-se perceber que o algoritmo apresenta um crescimento de tempo exponencial.

A desvantagem desse tipo de análise vai variar conforme as configurações do computador utilizado, conforme a linguagem de 
programação utilizada, etc.

**Análise matemática**: esta forma é mais genérica. Conseguimos ter uma análise invariante às configurações do hardware ou 
linguagem utilizada. Depende somente da forma como a algoritmo foi construído.

### Análise matemática
Primeiramente vamos estabelecer um custo para cada tipo de instrução de um programa. 

Vamos considerar que instruções simples terão custo de uma unidade de tempo. Por exemplo:
- Atribuição de valores;
- Acesso a um elemento de um vetor via índice;
- Comparações;
- Operações matemáticas básicas: soma, subtração, multiplicação, etc.

Vamos considerar que um comando do tipo if não terá custo. Portanto, podemos dizer que a linha abaixo tem custo 1 (devido ao teste que é feito dentro dos parênteses):
```c
if(x > 0)
```
Obs.: estamos considerando apenas o custo do comando if, e não das instruções que vem dentro do bloco do if. Cada uma dessas instruções deve ser contabilizada separadamente. 

Em um comando do tipo for, vamos usar a mesma ideia do if, ou seja, analisaremos as instruções de inicialização, condição de parada e atualização do contador.
```c
for(i = 0; i < n; i++) {
    ...
}
```
Mesmo que n seja 0, duas instruções serão executadas, a instrução i = 0 e a comparação i < n, gerando um custo de 2 unidades de tempo.

Se n não for igual o zero:
- A instrução i = 0 será executada uma vez. 
- A instrução de incremento i++ será executada n vezes. 
- A instrução de comparação i < n será executada n + 1 vezes. 

Para exemplificar considere n = 4:
```diff
i é inicializado com 0
para i = 0: i < n? -> sim -> i++
para i = 1: i < n? -> sim -> i++
para i = 2: i < n? -> sim -> i++
para i = 3: i < n? -> sim -> i++
para i = 4: i < n? -> não -> sai do laço

```
Então, um for até n (sem contar as instruções que possam estar dentro dele) terá um custo de:
```diff
f(n) = 1 + n + (n + 1)
f(n) = 2 + 2n
```
### Exemplo de análise matemática
Considere um trecho de código onde é preciso encontrar o maior valor de um vetor:
```c
1. maior = vetor[0];
2. for(i = 1; i < n; i++) 
3.     if(vetor[i] > maior)
4.         maior = vetor[i];
```
Analisando o custo de cada linha:
- Inicialização do maior na linha 1: custo 1
- Inicialização do i, condição de parada e incremento do i, na linha 2: 2 + 2n
- A comparação da linha 3, se fosse executada uma só vez, teria custo 1. Entretanto, ela está dentro de um for, e será executada n vezes. Logo, seu custo será de n.
- A atribuição da linha 4, se fosse executada uma só vez, teria custo 1. Entretanto, devemos considerar que ela está dentro de um for e dentro de um if também. Se o vetor estiver ordenado de maneira decrescente (por ex.: {4, 3, 2, 1}), o teste feito no if sempre terá resultado falso, e ela nunca chegará a ser executada. Se o vetor estiver ordenado de maneira crescente (por ex.: {1, 2, 3, 4}), o teste no if sempre terá resultado verdadeiro, e ela será executada n vezes. Na análise de um algoritmo geralmente consideramos o caso que terá maor custo computacional, ou seja o **pior caso**. Por isso vamos considerar que a linha 4 pode ser executada até n vezes, gerando um custo de n.

Sendo assim o custo total para encontrar o maior elemento de um vetor é de: 
```diff
f(n) = 1 + (2 + 2n) + n + n
f(n) = 3 + 4n
``` 

### Comportamento assintótico 
Ainda pensando no exemplo anterior, independente do tamanho de n, algumas instruções sempres irão acontecer:
- A inicialização da variável maior com o primeiro valor do vetor;
- A inicialização do i;
- A primeira comparação do for;
- O acesso a um item do vetor a partir do índice...

Sendo assim, podemos considerar que independente do tamanho de n, as instruções acima irão representar um custo constante para o algoritmo. O que vai fazer com que o tempo de execução do algoritmo cresça é o valor de n, ele é quem irá determinar quantas vezes as instruções detro do laço precisam ser repetidas.

Desta maneira, podemos descartar todos os termos da função que não estão relacionados a n:
```diff
f(n) = 3 + 4n
```
pode ser simplificada para:
```diff
f(n) = 4n
```
O 4 que acompanha o n, também não muda conforme n aumenta, ou seja, ele é uma constante e também pode ser ignorado. Assim, a função final fica:
```diff
f(n) = n
```

Se a função de crescimento tiver vários termos associados a n, por exemplo:
```diff
f(n) = n² + n
```
Podemos considerar apenas o termo com o maior expoente, pois sempre será ele o responsável pelo maior crescimento da função. Assim, no exemplo acima, teríamos:
```diff
f(n) = n²
```
Isso fica mais fácil de ser compreendido através de um exemplo. Considere que um certo algoritmo tem uma função de crescimento f(n) igual a:
```diff
f(n) = 100n + 50
```
Enquanto outro algoritmo tem uma função de crescimento g(n) igual a:
```diff
g(n) = n²
```
Apesar de inicialmente f(n) gerar valores maiores, existe um valor de n, a partir do qual g(n) passa a gerar resultados sempre maiores, como mostra o gráfico:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/comportamento_assintotico.png)

(Gráfico gerado em: https://www.wolframalpha.com/examples/mathematics/plotting-and-graphics/)

Assim fica claro ver, que a função ou termo com o maior expoente, a partir de um certo ponto, sempre irá ser o responsável pelo maior crescimento. Ou seja, a função com termo de maior expoente **domina assintoticamente** a outra função.

Sabendo que os termos relacionados a n é que determinam o crescimento da função de complexidade, podemos simplificar a análise dando enfoque para partes do código que contém laços (considerando funções não recursivas). Exemplo:
```c
int busca_valor(int vetor[], int n, int valor) {
    int i; // 1 
    for(i = 0; i < n; i++) // n (as instruções passarão pelo laço n vezes)
        if(vetor[i] == valor) // 1
            return i; // 1
    return -1; // 1
}
```
f(n) = n + 4, ou seja f(n) = n

Obs.: tratando-se de algoritmos recursivos, dará um pouco mais de trabalho para calcular a complexidade de tempo.

### Comparação assintótica de funções
Até agora vimos que uma função com termo n² domina assintóticamente uma funão cujo maior termo é n. E quanto aos outros tipos de funções? A hierarquia de funções do ponto de vista assintótico é mostrada abaixo (c = constante):

**c < log(n) < n < n log(n) < n² < 2<sup>n</sup> < n!**

Pois se estas funções forem plotadas em um gráfico, teremos o seguinte comportamento:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/bigO.png)

Fonte da imagem: https://www.bigocheatsheet.com/

### Notação Big-O

A notação mais usada para medir a complexidade de algoritmos é a Big-O. Ela define qual é o limite superior de uma função, ou seja, qual será seu custo no pior caso. A função abaixo, por exemplo:
```diff
f(n) = n² + n + 1
```
Será denotada por:  O(n) = n² 

Isso quer dizer que em seu pior caso, o algoritmo terá um custo de n², nunca maior que isso.

Alguns valores comuns da notação Big-O são apresentados abaixo:
- **O(1) - complexidade constante**: as instruções são executadas um número fixo de vezes, independente do tamanho da entrada. Exemplos: determinar se um número é par ou ímpar, calcular as raízes da fórmula de Bhaskara...

- **O(log n) - complexidade logarítmica**: tipicamente são algoritmos que resolvem um problema dividindo-o em problemas menores. Exemplos: um algoritmo de busca binária (busca em uma lista ordenada)...

- **O(n) - complexidade linear**: em geral, uma quantidade definida de operações (n) é realizada sobre cada item da entrada. Exemplos: buscar um item em um vetor desordenado, encontrar o último item de uma lista encadeada (implementada sem um ponteiro para a última célula), converter uma string binária para um número decimal...

- **O(n log n) - complexidade logarítmica**: tipicamente são algoritmos que resolvem um problema dividindo-o em problemas menores, resolvendo cada um independentemente e depois juntando as soluções, como algoritmos de divisão e conquista.

- **O(n²) - complexidade quadrática**: caracterizam-se pelo processamento dos dados em pares, geralmente contém um aninhamento com dois comandos de repetição. Exemplo: mostrar todas as combinações possíveis ao lançar dois dados - para cada lado do primeiro dado, existem 6 possibilidades de lançameto no segundo dado, totalizando 6 x 6 combinações, ou 6².
 
- **O(n³) - complexidade cúbica**: caracterizam-se pela presença de 3 comandos de repetição aninhados. Já começa a se tornar pouco eficiente para problemas grandes.

- **O(2<sup>n</sup>) - complexidade exponencial**: geralmente usado em soluções que usam força bruta, ex.: quebrar uma senha tentando todas as combinações possíveis. Não são úteis do ponto de vista prático.

- **O(n!) - complexidade fatorial**: geralmente soluções que usam força bruta, tendo um comportamento bem pior que o exeponencial. Também não são úteis do ponto de vista prático.

## Complexidade de espaço

A complexidade de espaço refere-se à quantidade de memória usada por um algoritmo. Enquanto está executando, um algoritmo precisa de memória para: variáveis, instruções e pilha de chamadas de funções. Para simplificar, na hora de analisar um algoritmo, geralmente consideramos apenas a memória usada com as variáveis (no caso de algoritmos não recursivos).

A complexidade de espaço também geralmente é repressentada pela notação Big-O.

Exemplos:

1.
```c
int soma() {
    int a = 1, b = 2, c = 3, soma;
    soma = a + b + c;
    return soma;
}
```
Na função acima foi necessário declarar 4 variáveis tipo int. Na linguagem C, um tipo int geralmente ocupa 4 bytes, logo serão necessários 16 unidades de memória. Independente dos valores de a, b ou c, sempre serão 16 unidades de memória, portanto podemos dizer que a complexidade é constante, O(1).

2.
```c
int soma_vet(int vet[], int n) {
    int i,  soma = 0;
    for(i = 0; i < n; i++)
        soma = soma + vet[i];
    return soma;
}
```
Esta função continua sendo O(1), por mais que use um vetor. O vetor não é criado pela função, a função recebe um ponteiro para o vetor, que já foi alocado por outra função. É feita apenas a alocação das demais variáveis: i, soma e n.

3.
```c
int * vetor_quadrado(int vet[], int n) {
    int *vet_q = (int*)malloc(sizeof(int));
    int i;
    for(i = 0; i < n; i++)
        vet_q[i] = vet[i] * vet[i];
    return vet_q;
}
```
Aqui um novo vetor de n elementos é alocado dentro da função, portanto a complexidade será O(n).

Obs.: nem sempre a complexidade de tempo e de espaço será a mesma para um algoritmo. No exemplo 2, a complexidade de espaço é O(1), enqunato a complexidade de tempo é O(n).

## Referências:
- Backes, André Ricardo, **Estruturas de dados descomplicada: em linguagem C**, 1ª ed., Rio de Janeiro: Elsevier, 2016.
- Slides professor Bruno César Ribas: www.brunoribas.com.br/aed1/2018-2/slides/ribas-complexidade-assintotica.pdf
- Wengrow, Jay, **A Common-Sense Guide to Data Structures and Algorithms: Level Up Your Core Programming Skills**, 1ª ed., Pragmatic Bookshelf, 2017.
