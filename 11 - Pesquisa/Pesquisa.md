# Algoritmos de pesquisa

Um algoritmo de pesquisa ou busca tem como objetivo procurar algum item dentro de um conjunto de dados. Dois métodos de busca bem
conhecidos são: pesquisa sequencial e pesquisa binária.

## Pesquisa sequencial

É o método de pesquisa mais simples que existe: percorre um arranjo sequencialmente a partir do primeiro registro até encontrar a 
chave buscada ou até chegar ao final do array.

O algoritmo abaixo é um exemplo de como realizar uma busca sequencial, retornando o índice onde a chave foi encontrada, ou -1 
se a chave não foi encontrada:

```c
int busca_sequencial(int v[], int n, int chave) {
  int i;
  for(i = 0; i < n; i++)
    if(v[i] == chave)
      return i;
  return -1;
}
```

### Complexidade de tempo

**Melhor caso**: para este tipo de pesquisa, o melhor caso seria quando a chave buscada está no primeiro índice do array. Nesse 
caso o custo seria **O(1)**. 

**Pior caso**: acontece quando a chave buscada está no último índice do array ou então quando ela não existe, pois o laço 
precisaria ser executado todas as vezes, levando a um custo **O(n)**.

### Complexidade de espaço

Não necessita de memória auxiliar, sendo **O(1)** em qualquer situação.

## Pesquisa binária

Aplica-se quando o array já está ordenado. Considerando um array em ordem crescente:

- A chave é comparada com o item que está no meio do array. 
- Se a chave for igual ao item, a busca termina.
- Se a chave for menor que o item, repete o processo com a metade esquerda do array.
- Se a chave for maior que o item, repete o processo com a metade direita do array.

Exemplo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/busca_binaria.png)

Exemplo de implementação iterativa em C:

```c
int busca_binaria(int v[], int n, int chave) {
  int primeiro = 0;
  int ultimo = n - 1;
  int meio;
  while(primeiro <= ultimo) {
    meio = (primeiro + ultimo) / 2;
    if(v[meio] == chave)
        return meio;
    else if(v[meio] > chave)
        ultimo = meio - 1;
    else
        primeiro = meio + 1;
  }
  return -1;
}
```

### Complexidade de tempo

**Melhor caso**: o elemento procurado está no meio do array.

**Pior caso**: acontece quando o elemento não existe no array ou o método precisa realizar até log<sub>2</sub>n divisões
para encontrar o item, como no exemplo abaixo:
```diff
Vetor:
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

Item buscado: 8

meio = (0 + 7) / 2 = 3
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
              ^
4 < 8, repete para a metade direita.

meio = (4 + 7) / 2 = 5
| 5 | 6 | 7 | 8 |
|---|---|---|---|
| 4 | 5 | 6 | 7 |
      ^
6 < 8, repete para a metade direita.

meio = (6 + 7) / 2 = 6
| 7 | 8 |
|---|---|
| 6 | 7 |
  ^
7 < 8, repete para a metade direita.

meio = (7 + 7) / 2 = 7
| 8 |
|---|
| 7 |
  ^
 8 = 8, finaliza.
```
No exemplo acima, o vetor tinha 8 elementos e precisou ser dividido ao meio 3 vezes (log<sub>2</sub>8 = 3).

Sendo assim, podemos concluir que no pior caso, a busca binária tem custo **O(log<sub>2</sub>n)**. 

### Complexidade de espaço

Na versão iterativa da busca binária a complexidade de espaço é **O(1)** em qualquer caso, pois não precisa de memória auxiliar.

## Referências

- Backes, André Ricardo, **Estruturas de dados descomplicada: em linguagem C**, 1ª ed., Rio de Janeiro: Elsevier, 2016.
- West Chester University, **Algorithm Analysis**, disponível em: https://www.cs.wcupa.edu/rkline/ds/analysis.html
