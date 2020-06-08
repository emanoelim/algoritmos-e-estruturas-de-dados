# Ponteiro para ponteiro

Se *p1 é um ponteiro, então **p2 é um ponteiro para um ponteiro. Considere o código abaixo:

```c
#include <stdio.h>

main() {
    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;
    
    printf("Endereço de x: %ld\n", &x);
    printf("Conteúdo de x: %d\n", x);

    printf("\nEndereço de p1: %ld\n", &p1);
    printf("Endereço apontado por p1: %ld\n", p1);
    printf("Conteúdo do endereço apontado por p1: %d\n", *p1);

    printf("\nEndereço de p2: %ld\n", &p2);
    printf("Endereço apontado por p2: %ld\n", p2);
    printf("Conteúdo do endereço apontado por p2: %ld\n", *p2);
    printf("p2 aponta para p1 que aponta para: %d\n", **p2);
}
```

Ilustrando, teríamos:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/ponteiro_para_ponteiro.png)

- Ao acessar p2, tenho 1000 (endereço apontado por p2);
- Ao acessar *p2, tenho 1004 (o endereço apontado por p1);
- Ao acessar **p2, tenho 10 (o valor guardado no endereço apontado por p1);

Cada * faz andar um pouquinho mais no encadeamento.

# Cuidados

Se p2 aponta para p1, p1 aponta para x e x teve o valor alterado, a mudança em x reflete em p2:

```c
#include <stdio.h>

main() {
    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;
    
    printf("%d\n", **p2);
    x = 20;
    printf("%d\n", **p2);
}
```

Se p2 aponta para p1, p1 aponta para x e x teve o valor alterado a partir do ponteiro p2, a alteração também reflete em p1 e x:

```c
#include <stdio.h>

main() {
    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;
    
    printf("%d\n", *p1);
    **p2 = 20;
    printf("%d\n", *p1);
    printf("%d\n", x);
}
```

Se p2 é ponteiro para p1 e p1 for liberado, o que acontece com p2? Ele ainda aponta para o endereço que era de p1, mas o 
conteúdo de p1 é perdido:

```c
#include <stdio.h>

main() {
    int *p1 = malloc(sizeof(int));
    *p1 = 10;
    int **p2 = &p1;

    printf("%ld\n", p2);
    printf("%d\n", **p2);
    free(p1);
    printf("%ld\n", p2);
    printf("%d\n", **p2);
}
```

Tratando-se de estruturas, o cuidado deve ser ainda maior. Imagine que temos uma estrutura chamada Ponto. 
- “ponto” é do tipo Ponto.     
- “*p1” é um ponteiro para um tipo Ponto;
- “**p2” é um ponteiro para um ponteiro para um tipo Ponto;
- “***p3” é um ponteiro para um ponteiro para um ponteiro para um tipo Ponto.

```c
#include <stdio.h>

typedef struct ponto Ponto;
struct ponto{
    int x;
    int y;
};

main(){
    Ponto ponto, *p1, **p2, ***p3;

    ponto.x = 10;
    ponto.y = 20;
    p1 = &ponto;
    p2 = &p1;
    p3 = &p2;

    printf("A partir de *p:\n");
    printf("x: %d\n", (*p1).x);
    printf("y: %d\n", (*p1).y);
    /*
    Dentro dos () é acessado o conteúdo de p1 através de uma op. de deferência.
    O conteúdo de p1 é um tipo Ponto, é possível então acessar seus campos.
     */

    printf("A partir de **p2:\n");
    printf("x: %d\n", (*(*p2)).x);
    printf("x: %d\n", (*(*p2)).y);
    /*
    Dentro dos () mais internos, é acessado o conteúdo de p2 através de uma op. de deferência.
    O conteúdo de p2 é o endereço de p1, é preciso fazer mais uma op. de deferência.
    O conteúdo de p1 é um tipo Ponto, é possível então acessar seus campos.
    */

    printf("A partir de ***p3:\n");
    printf("x: %d\n", (*(*(*p3))).x);
    printf("x: %d\n", (*(*(*p3))).y);
    /*
    Dentro dos () mais internos, é acessado o conteúdo de p3 através de uma operação de deferência.
    O conteúdo de p3 é o endereço de p2, é preciso fazer mais uma op. de deferência.
    O conteúdo de p2 é o endereço de p1, é preciso fazer mais uma op. de deferência.
    O conteúdo de p1 é um tipo Ponto, é possível então acessar seus campos.
    */
}
```
