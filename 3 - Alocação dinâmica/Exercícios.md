# Exercícios sobre alocação dinâmica

1. Identificar os problemas dos códigos abaixo:

a)

```c
main() {
    int v[10];
    free(v);
}
```

b)

```c
main() {
    int x, *p;
    p = malloc(sizeof(int));
    p = &x;
    free(p);
}
```

c)

```c
main(){
   int *v;
   v = malloc (10 * sizeof (int));
   free(v+1);
}
```
___

2. Verifique o que faz o código abaixo. Ele executa corretamente?

```c
main() {
    char *s, a[] = "Algoritmos";
    int t;
    s = malloc(30 * sizeof(char));
    strcpy(s, a);
    t = strlen(s);
    printf("Tamanho: %d\n", t);
    s = realloc(s, t * sizeof(char));
    free(s);
}
```

E se a seguinte alteração for feita, o que acontece? 

```c
main() {
    char *s, a[] = "Algoritmos";
    int t;
    s = malloc(30 * sizeof(char));
    s = a; // mudança aqui
    t = strlen(s);
    printf("Tamanho: %d\n", t);
    s = realloc(s, t * sizeof(char));
    free(s);
}
```
___

3. Crie um vetor do tipo inteiro com 50 itens usando a função malloc. Percorra o vetor imprimindo endereço e valor de cada item.

___

4. Repetir o exercício anterior usando a função calloc em vez de malloc.

___
5. A função abaixo recebe o limite inferior e o limite superior de um intervalo
 e tem como objetivo retornar um vetor com todos os inteiros pertencentes ao 
intervalo. Qual é o problema dessa função?
```c
int * retorna_numeros_intervalo(int inf, int sup) {
    int tamanho = sup - inf;
    int vetor[tamanho];
    int i;
    int j = 0;
    for(i = inf; i < sup; i++) {
        vetor[j] = i;
        j++;
    }
    return vetor;
} 
```
