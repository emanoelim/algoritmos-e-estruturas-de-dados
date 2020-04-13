# Exercicios com ponteiros

1. O código abaixo imprime os valores e endereços de um vetor e de uma string. Por que os endereços do vetor v aumentam de 4 em 4 
e os endereços da string c aumentam de 1 em 1?

```c
#include <stdio.h>
#include <string.h>

void main(void) {
   int v[] = {1, 2, 3, 4, 5};
   char s[] = "ola";
   int i = 0;

   for(i = 0; i < 5; i++) {
       printf("valor: %d, end.: %ld\n", v[i], &v[i]);
   }

   printf("\n");
   for(i = 0; i < strlen(s); i++) {
       printf("valor: %c, end.: %ld\n", s[i], &s[i]);
   }
}
```
___

2. Suponha que os elementos do vetor (v) são do tipo int e cada int ocupa 8 bytes no seu computador. Se o endereço de v[0] é 10000, qual o valor da expressão v + 5?
___

3. (Exercício extraído do livro SCHILDT, Herbert, C Completo e Total, 3ª edição). Identifique qual é o problema do código:

```c
void main(void) {
    int x, *p;
    x = 10;
    *p = x;
}
```
___

4. (Exercício extraído do material do prof. Paulo Feofiloff - https://www.ime.usp.br/~pf/algoritmos/).  Execute o programa abaixo 
e verifique sua saída:

```c
#include <stdio.h>

void func1(int x) {
   x = 9 * x;
}

void func2(int v[]) {
   v[0] = 9 * v[0];
}

void main(void){
   int x, v[2];

   x = 111;
   v[0] = 111;

   func1(x);
   printf("x: %d\n", x);

   func2(v);
   printf("v[0]: %d\n", v[0]);
}
```

x e v[0] possuem valores iguais? Por que isso acontece?
___

5. Qual será a saída do programa?

```c
#include <stdio.h>

int main(void){
   int v[] = {10, 20, 30};
   int *p;
   p = v;
   p++;
   printf("%d\n", *p);
   return 0;
}
```

Se em vez de:

```c
p++;
```

fosse:

```c
(*p)++;
```

Qual seria a saída?
___

6. (Exercício extraído do material do prof. Paulo Feofiloff - https://www.ime.usp.br/~pf/algoritmos/). O que está acontecendo no 
código abaixo?

```c
#include <stdio.h>
#include <string.h>

void imprime(char *s, int n) {
   char *c;
   for (c = s; c < s + n; c++)
      printf ("%c", *c);
}

void main(void){
    char s[] = "bom dia";
    imprime(s, strlen(s));
}
```
___

7. O que o código abaixo vai imprimir? (Tente descobrir manualmente e depois execute o código para conferir).

```c
#include <stdio.h>

void main(void){
    int v[3], *p, *a;

    p = v; 
    *p = 10;
    *(p + 1) = 20;
    *(p + 2) = 30;

    a = &v[1];
    *a = 40;
    *(a - 1) = 50;

    printf("%d\n", v[0]);
    printf("%d\n", v[1]);
    printf("%d\n", v[2]);
}
```
___

8. Corrija o problema do código abaixo:

```c
#include <stdio.h>

void troca(int *a, int *b) {
    int *t;
    *t = *a;
    *a = *b;
    *b = *t;
}

void main(void){
   int a = 10;
   int b = 20;
   printf("a: %d, b: %d\n", a, b);
   troca(&a, &b);
   printf("a: %d, b: %d\n", a, b);
}
```
___

9. Escreva um programa para somar dois valores usando ponteiros.
___

10. Escreva um programa que imprime um vetor. Percorra os itens do vetor através de aritmética de ponteiros.
___

11. Escreva uma função que imprime uma string. Percorra os itens da string através de aritmética de ponteiros.
___

12. Escrever uma função para contar a quantidade de caracteres de uma string, usando ponteiros para percorre-la. 
___

13. Implemente uma função que copia o conteúdo de uma string de origem em uma string de destino. O protótipo da função deve ser
void copia_string(char *destino, char *origem). Utilize ponteiros.
___

14. Implemente uma função que concatena uma string "b" no final de uma string "a". O protótipo da função deve ser void concatena_strings(char *sa, char *sb). Utilize ponteiros.
___

15 . Implemente uma função que compara duas strings. O protótipo da função deve ser: int compara_string(char *sa, char *sb), retornando um número inteiro para indicar se são iguais ou não. Utilize ponteiros.


