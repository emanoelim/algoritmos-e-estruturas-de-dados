### Exercícios sobre complexidade

1) Escrever na notação Big-O:

1. f(n) = 5
2. f(n) = 3n + n + 2
3. f(n) = 200 + n
4. f(n) = n² + n
5. f(n) = 5n³ + n² + n + 20
6. f(n) = 2<sup>n</sup>n + n³ + 30
7. f(n) = n/5 + n
___
2) Quais seriam o melhor caso e o pior caso para uma função com objetivo de remover um item de uma lista implementada por meio de 
vetores? Qual a complexidade de tempo no melhor caso? Qual a complexidade de tempo no pior caso?
___
3) Qual a complexidade de tempo de uma função que realiza a remoção do primeiro item de uma lista encadeada como foi vista na aula?
___
4) Qual a complexidade de tempo de uma função que realiza a remoção do último item de uma lista encadeada (usando ponteiro para a última
célula e sem usar ponteiro para a última célula)?
___
5) Qual é a complexidade de tempo de uma função que busca uma determinada chave dentro de uma lista (não ordenada) no pior caso? 
Considere a implementação por vetores.
___
6) Dois algoritmos (A e B) possuem complexidade de tempo n<sup>5</sup> e 2<sup>n</sup>, respectivamente. Você utilizaria o algoritmo B 
ao invés do A em algum caso? Por quê? 
___
7) Calcular a complexidade de tempo dos trechos de código abaixo:
1.
```c
...
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            mat[i][j] = i*j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
...
```

2.
```c
...
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            mat[i][j] = i*j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
...
```

3.
```c
...
    for(i = 0; i < n; i++)
        vet1[i] = i*i;
    for(i = 0; i < m; i++)
        vet2[i] = i+i;
...
```
___
8) Neste exercício você irá encontrar a função de complexidade de tempo de forma experimental. Crie dois programas:

1. Um programa para gerar vetores de números inteiros. O primeiro vetor deve ter 100 elementos. Para os demais vetores, incremente o tamanho com intervalos regulares até atingir um total de 5000 elementos. Para cada vetor gerado você deve medir aproxidamente quanto tempo foi necessário. Para isso, crie duas variáveis do tipo clock_t e uma variável do tipo double, no início do programa:
```c
clock_t ini, fim;
double tempo_gasto;
```
Antes de iniciar a geração do vetor, guarde o tempo inicial. Após gerar o vetor, guarde o tempo final e então encontre a diferença de tempo:
```c
ini = clock();
// lógica para geração do vetor
fim = clock();
tempo_gasto = (double)(fim - ini) / CLOCKS_PER_SEC;
```
Mostre na tela o tamanho de cada vetor e o tempo para gera-lo. A partir desses valores gere um gráfico Tamanho x Tempo e verifique o crescimento da função (use algum programa de planilhas ou alguma ferramenta online). Dependendo do hardware usado, pode ser necessário ir além de 5000 elementos para visualizar a função de crescimento.

2. Faça o mesmo procedimento descrito anteriormente para gerar matrizes quadradas. 

Responda: teoricamente, quais seriam as complexidades de tempo dos dois programas acima? As funções de crescimento exibidas nos gráficos condizem com as complexidades teóricas?
