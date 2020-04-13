# Alocação dinâmica de memória
    
O compilador reserva espaço na memória para todos os dados declarados explicitamente:

```c
int x; // reserva 4 bytes na memória
char c; // reserva 1 byte na memória
int v[5]; // reserva 5 x 4 bytes na memória;
char s[10]; // reserva 10 x 1 byte na memória;
```
No caso de variáveis do tipo ponteiro, precisamos vincular o ponteiro a  um endereço de memória existente. Podemos, por exemplo, vincular um ponteiro do tipo inteiro ao endereço de  uma variável do mesmo tipo:

```c
int *p, x;
p = &x; // p aponta para o endereço de memória de x.
```

E se em vez de vincular o ponteiro p à um endereço que já existe, eu quiser vincular p a um novo endereço de memória? Ou seja, 
um endereço que não está previamente alocado? Para isso teríamos que alocar espaço em memória durante a execução do programa. 
O processo de alocar memória durante a execução é chamado de **alocação dinâmica de memória**. A biblioteca **stdlib.h** possui funções 
úteis para trabalhar com alocação dinâmica de memória.

# Função malloc
    
O nome dessa função vem de *memory allocation*. Podemos deduzir então, que esta função tem a responsabilidade de alocar uma quantidade de memória. Ela recebe como parâmetro a quantidade de memória que deverá ser alocada (em bytes) e retorna um ponteiro void (sem tipo) para o primeiro endereço alocado. Este ponteiro pode ser convertido para  um ponteiro de qualquer outro tipo.

Por exemplo: se quisermos alocar memória suficiente para alocar um dado do tipo inteiro, precisamos alocar 4 endereços de memória:

```c
int *p = malloc(4); // p aponta para um novo endereço
```

Para facilitar é possível usar o operador **sizeof**:

```c
int *p = malloc(sizeof(int)); // p aponta para um novo endereço
```

Para alocar um vetor que guarda 5 números inteiros, podemos fazer:

```c
int *p = malloc(5 * sizeof(int)); 
```
Nesse caso, 20 endereços de memória são alocados e p aponta para o primeiro desses endereços.

Considere agora uma estrutura:

```c
typedef struct ponto Ponto;

struct ponto {
    float x;
    float y;
};
```

O operador sizeof também pode ser utilizado com estruturas:

```c
Ponto *p = malloc(sizeof(Ponto));
```

Ou se fosse necessário alocar memória para um vetor com 10 itens do tipo Ponto:

```c
Ponto *p = malloc(10 * sizeof(Ponto)); 
```

O tipo Ponto ocupa 8 bytes, pois é formado por dois tipo float. Desta forma, um vetor com 10 elementos do tipo Ponto irá ocupar 80 bytes na memória. Portanto, ao chamar a função malloc, 80 endereços de memória serão alocados e o ponteiro p apontará para o primeiro desses endereços.

# Função calloc
 
A função malloc tem o objetivo de alocar endereços memória, mas não se preocupa com o conteúdo desses endereços. Pode ser que os endereços alocados contenham algum lixo de memória. Em contrapartida, a função calloc, além de alocar endereços de memória, garante que o conteúdo desses endereços é 0. Seus parâmetros são um pouco diferentes. Ela espera como parâmetro o número de elementos que precisa ser alocado e o tamanho de cada elemento:

```c
int *p = calloc(1, sizeof(int)); // aloca endereço para 1 int
int *v = calloc(10, sizeof(int)); // aloca endereço para 10 int
```

# Função free

As variáveis alocadas estaticamente são eliminadas após a execução de uma função. O mesmo não acontece com variáveis alocadas dinamicamente. Elas continuam existindo mesmo depois que a função é executada. Por isso, após usar essas variáveis é preciso liberar manualmente a memória ocupada por elas. Por exemplo:

```c
int *p = malloc(5 * sizeof(int)); 

// processamento

free(p);
```

Obs.:

- A função free() deve ser usada para liberar blocos de memória inteiros e não partes do bloco. 
- Se a função free() for usada pra tentar liberar um ponteiro que aponta para NULL, nada acontece.
- Tomar cuidado para não chamar free() duas vezes sobre o mesmo ponteiro, isso pode levar a um comportamento indefinido.

# Função realloc

Permite redimensionar o bloco de memória apontado por um ponteiro, tanto para mais, quanto para menos. Ela recebe como parâmetro um ponteiro e o novo tamanho do bloco, em bytes. Seu retorno é um ponteiro para o primeiro endereço do novo bloco de memória. Exemplo:

```c
char *pc = malloc(30 * sizeof(char));
pc = realloc(pc, 20 * sizeof(char));
```

Ao chamar a função realloc para expandir um bloco de memória, podem acontecer as seguintes situações:

a) Existe memória contígua ao bloco de memória original, suficiente para fazer a expansão: os conteúdos dos endereços que já estavam alocados não são alterados e novos endereços são alocados. O conteúdo desses novos endereços é indefinido (podem conter lixo de memória).

b) Não existe memória contígua suficiente para expandir o bloco de memória original: o compilador procura uma área de memória contígua grande o suficiente, copia os conteúdos dos endereços antigos para os novos e libera os endereços antigos. Caso o compilador não encontre memória suficiente para fazer realocação, os antigos endereços permanecem inalterados e a função retorna um ponteiro NULL.

Obs.: tanto a função realloc() quanto a função free() aplicam-se a blocos de memória que foram alocados dinamicamente!

# Exemplo de uso interessante para aloção dinâmica

Imagine que precisamos criar uma função que recebe uma string e retorna a string invertida. O que acontece no código abaixo? Ele está imprimindo a string invertida?

```c
#include <stdio.h>
#include <string.h>

char * inverte_string(char s[]) { 
    int i, j, tamanho;
    tamanho = strlen(s);
    char s_invertida[tamanho];

    j = 0;
    for(i = tamanho - 1; i >= 0; i--){
           s_invertida[j] = s[i];
           j++;
    }
    s_invertida[j] = '\0';

    // printf("%s\n", s_invertida);
    return s_invertida;
}

void main() {
    char *s = "ponteiros";
    char *i = inverte_string(s);
    printf("%s", i);
}
```

O código não faz o que é esperado, além de acontecer um warning na hora de compilar:

```diff
warning: function returns address of local variable [-Wreturn-local-addr]
```

Toda variável que é criada dentro de uma função é destruída após a finalização da execução da função. Isso quer dizer que 
a variável s_invertida (que foi criada dentro da função inverte_string), é destruída após a finalização da execução de 
inverte_string. Se a variável é destruída, **não é possível ter uma garantia de que o ponteiro retornado conterá o conteúdo 
esperado**. Assim, uma alternativa é alocar dinâmicamente a memória para a variável s_invertida. Isto garante que ela não 
será destruída após a finalização da execução da função. Não haverá mais warning e o programa terá o comportamento esperado:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * inverte_string(char s[]) { 
    int i, j, tamanho;
    tamanho = strlen(s);
    char *s_invertida = malloc(tamanho * sizeof(char));

    j = 0;
    for(i = tamanho - 1; i >= 0; i--){
           s_invertida[j] = s[i];
           j++;
    }
    s_invertida[j] = '\0';

    // printf("%s\n", s_invertida);
    return s_invertida;
}

void main() {
    char *s = "ponteiros";
    char *i = inverte_string(s);
    printf("%s", i);
}
```
