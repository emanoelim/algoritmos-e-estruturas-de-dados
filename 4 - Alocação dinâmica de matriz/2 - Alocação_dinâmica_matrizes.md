# Alocação dinâmica de matrizes

Considerando vetores, vimos que a instrução:

```c
int *p = malloc(n * sizeof(int)); 
```

aloca memória para um vetor de inteiros. Ou seja, *p aponta para o primeiro elemento de um vetor de int:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/vetor_dinamico.png)

E o que dizer se tivermos a declaração abaixo?

```c
int **p;
```

Significa que temos um ponteiro para ponteiro. Pensando em um vetor, teremos um vetor onde cada elemento do vetor aponta para um 
endereço:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/vetor_de_ponteiros.png)

Sabemos que uma matriz é um vetor de vetores. Se fizermos cada ponteiro do vetor int* acima apontar para um vetor de inteiros 
em vez de apontar para uma única variável, o resultado será uma matriz:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/matriz_dinamica.png)

# Alocando uma matriz dinamicamente em C

```c
// matriz de inteiros alocada dinamicamente
#include <stdio.h>

main() {
    int **m, l, c, n_linhas, n_colunas;

    // matriz 4 x 5
    n_linhas = 4;
    n_colunas = 5;

    // 1 - alocamos um vetor com um ponteiro para cada linha:
    m = malloc(n_linhas * sizeof(int*));
    // 2 - fazemos cada ponteiro apontar para uma linha:
    for(l = 0; l < n_linhas; l++)
            m[l] = malloc(n_colunas * sizeof(int));

    // exibindo os endereços que foram alocados:
    for(l = 0; l < n_linhas; l++) {
            for(c = 0; c < n_colunas; c++)
              printf("%ld\t", &m[l][c]);
            printf("\n");
    }
}
```

Obs.: Para garantir que a matriz estaria toda preenchida com 0s, poderia ser usada a função calloc.

Analisando os endereços alocados, é possível ver que os itens de uma linha sempre são alocados em espaços contíguos de memória. Já as linhas nem sempre estarão ocupando blocos contíguos de memória. Cada linha pode estar alocada em um bloco bem distante um do outro, diferente de uma matriz alocada estaticamente.

# Liberando uma matriz alocada dinamicamente

Relembrando o que fizemos para alocar a matriz:

1. Alocamos um vetor de ponteiros, contendo um ponteiro para cada linha da matriz;
2. Fazemos cada um desses ponteiros apontar para um vetor (linha da matriz).
    
O processo de liberar memória deve então ser o inverso:
1. Liberar cada linha;
2. Liberar os ponteiros que apontam para essas linhas.    

Podemos fazer uma analogia com uma caixa de livros. Imagine que você quer guardar seus livros em uma caixa:

1. Você pega uma caixa;
2. Você coloca os livros dentro da caixa;

Imagine agora que você instalou uma prateleira e quer jogar a caixa fora:

1. Você remove todos os livros de dentro da caixa;
2. Agora que a caixa está vazia, você se livra dela.

Implementado isto em C, temos:

```c

for(l = 0; l < n_linhas; l++) {
    free(m[l]); // tirar os livros da caixa
}
free(m); // livrar-se da caixa
```

# Matrizes dinâmicas e funções

```c
// matriz de inteiros alocada dinamicamente
#include <stdio.h>
#include <stdlib.h>

int ** aloca_matriz(n_linhas, n_colunas);
void imprime(int **m, int n_linhas, int n_colunas);
void libera_matriz(int **m, int n_linhas);


main() {
    int l, c, n_linhas, n_colunas, **m;

    n_linhas = 4;
    n_colunas = 5;
    m = aloca_matriz(n_linhas, n_colunas);
    imprime(m, n_linhas, n_colunas);
    libera_matriz(m, n_linhas);
}


int ** aloca_matriz(n_linhas, n_colunas) {
    int **m, l, c;

    // 1 - alocamos um vetor com um ponteiro para cada linha:
    m = malloc(n_linhas * sizeof(int*));
    // 2 - fazemos cada um ponteiro apontar para uma linha:
    for(l = 0; l < n_linhas; l++)
        m[l] = calloc(n_colunas, sizeof(int)); // matriz de 0s

    return m;
}

void imprime(int **m, int n_linhas, int n_colunas) {
    int l, c;
    for(l = 0; l < n_linhas; l++) {
        for(c = 0; c < n_colunas; c++)
            printf("%d\t", m[l][c]); // o elemento também poderia ser acessado através de: *(*(m+l)+c)) - a op. *(m+l) retorna um ponteiro!
        printf("\n");
    }
}

void libera_matriz(int **m, int n_linhas) {
    int l, c;
    for(l = 0; l < n_linhas; l++) {
        free(m[l]);
    }
    free(m);
}
```

# Vantagens de usar matriz alocada dinamicamente
- Se o código for extenso e a matriz for usada somente no começo, assim que se termina de usá-la, a memória ocupada por ela pode ser liberada.
- Se cada linha é alocada dinamicamente, é possível até mesmo ter uma “matriz” onde cada linha possui um tamanho diferente, otimizando espaço.

# Referências

- Vídeo aula sobre alocação dinâmica de matriz do prof. André Backes: https://youtu.be/W4vbwEJn11U
