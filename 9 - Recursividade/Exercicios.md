### Exercícios com funções recursivas

1) Elabore uma função que recebe como parâmetro um número n e imprime um asterisco n vezes. Essa função deve ser recursiva. Exemplo:
```diff
Entrada:
5
Saída:
*****
```
___
2) Escreva uma função recursiva para imprimir um vetor:
1. Na mesma ordem em que foi criado;
2. Ao contrário.
___
3) Elabore uma função recursiva para imprimir uma string ao contrário. Exemplo:
```diff
Entrada: 
bom dia
Saída:
aid mob
```
___
4) Escreva uma função recursiva que retorne a quantidade de dígitos em um número inteiro. Exemplo:
```diff
Entrada:
95230
Saída:
5
```
___
5) Neste exercício você deve encontrar o MDC (máximo divisor comum) entre dois números, usando o algoritmo de Euclides. Para calcular o mdc(m, n) para 0 ≤ n < m, o algoritmo de Euclides usa a seguinte recorrência:
- mdc(m, 0)  =  m; 
- mdc(m, n)  =  mdc(n, m % n),  para n > 0
    
Seguindo esta ideia, elabore uma função recursiva para encontrar o MDC entre dois números. Exemplo:
```diff
Entrada:
90 25
Saída:
5
```
___
6) Escreva uma função recursiva para verificar se uma string é palíndromo. Ideia: verificar se:
- 1º == último
- 2º == penúltimo
- 3º == antepenúltimo



