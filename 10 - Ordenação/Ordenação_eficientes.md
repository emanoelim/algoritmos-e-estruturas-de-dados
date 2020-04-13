# Algoritmos de ordenação eficientes

Esses algoritmos conseguem realizar a ordenação a um custo O(n log n), em contraste com os algoritmos simples,
que chegam em O(n²). São algoritmos bem conhecidos nesta categoria o Merge Sort e o Quick Sort.

## Merge Sort

Este algoritmo usa uma técnica conhecida como **divisão e conquista**: em vez de tratar o problema como um todo, essa técnica 
quebra o problema em problemas menores, encontrando as soluções destas partes menores e então combinando estas soluções para 
obter uma solução geral. 

O algoritmo merge sort divide o vetor de entrada em duas metades e assim sucessivamente, até chegar em subvetores de tamanho 1 
(caso base), visto que um vetor com apenas um item já está trivialmente ordenado. Considere por exemplo, o vetor formado pelos 
inteiros: {14, 7, 3, 12, 9, 11, 6, 2}. A figura abaixo mostra este processo de divisão, onde: p = primeiro item, q = item do meio
e r = último item.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/merge_divisao.png)

(Adaptado de https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort)

Uma vez divididos, os subvetores são agrupados em ordem, usando ideia de intercalação / fusão de dois vetores ordenados. 
Daí vem o nome merge sort: merge = fundir, em inglês. 

A partir de dois vetores já ordenados, é fácil criar um terceiro vetor ordenado formado pela intercalação dos dois vetores, como mostra o
passo a passo abaixo. Considere que v1 e v2 são os vetores já ordenados e v3 será o vetor resultante da fusão dos dois.

**Passo 1)**
```diff
v1:
i = 0
| 0 | 2 |
|---|---|
| 0 | 1 | 
  ^
  
v2:
j = 0
| 1 | 4 |
|---|---|
| 0 | 1 | 
  ^

v3:
Entre v1[0] (0) e v2[0] (1), o menor item é 0, então v3 guarda 0 e incrementa i:
| 0 |   |   |   |
|---|---|---|---|
| 0 | 1 | 2 | 3 | 
  ^
```

**Passo 2)**
```diff
v1:
i = 1
| 0 | 2 |
|---|---|
| 0 | 1 | 
      ^

v2:
j = 0
| 1 | 4 |
|---|---|
| 0 | 1 | 
  ^

v3:
Entre v1[1] (2) e v2[0] (1), o menor item é 1, então v3 guarda 1 e incrementa j:
| 0 | 1 |   |   |
|---|---|---|---|
| 0 | 1 | 2 | 3 | 
      ^
```

**Passo 3)**
```diff
v1:
i = 1
| 0 | 2 |
|---|---|
| 0 | 1 | 
      ^

v2:
j = 1
| 1 | 4 |
|---|---|
| 0 | 1 | 
      ^

v3:
Entre v1[1] (2) e v2[1] (4), o menor item é 2, então v3 guarda 2 e incrementa i:
| 0 | 1 | 2 |   |
|---|---|---|---|
| 0 | 1 | 2 | 3 | 
          ^
```

**Passo 4)**
```diff
v1:
Já foram utilizados todos os itens.


v2:
j = 1
| 1 | 4 |
|---|---|
| 0 | 1 | 
      ^

v3:
O(s) item(s) restantes de v2 são copiados para v3:
| 0 | 1 | 2 | 4 |
|---|---|---|---|
| 0 | 1 | 2 | 3 | 
              ^
```
Abaixo, uma impementação do método de intercalação:
```c
/* 
arr = vetor original
p = marca início do primeiro subvetor
q = marca fim do primeiro subvetor / inicio do segundo subvetor
r = marca o fim do segundo subvetor
*/
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1; // tamanho da metade esquerda
    int n2 =  r - q; // tamanho da metade direita
    // vetores temporários
    int L[n1], R[n2];
    // varíaveis para percorrer L[], R[] e arr[]
    int i, j, k;

    // valorização dos vetores temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + j + 1];

    // intercala os itens de L[] e R[] em arr[]
    i = 0; // indice inicial de L[]
    j = 0; // indice inicial de R[]
    k = p; // indice inicial do vetor final (arr[])
    while (i < n1 && j < n2) {
        // pegar o menor dos dois e colocar em arr[]
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiar os itens restantes de L[], caso tenha sobrado algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copiar os itens restantes de R[], caso tenha sobrado algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
``` 

Aplicando a ideia de intercalação no vetor {14, 7, 3, 12, 9, 11, 6, 2}, teremos:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/merge_conquista.png)

(Adaptado de https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort)

O problema vai sendo quebrado em problemas menores até chegar ao caso base, e então as soluções são agrupadas para gerar a solução geral. Isso indica uma estrutura **recursiva**, como mostra o código abaixo:
```c
void merge_sort(int arr[], int p, int r) {
  int q;
  if(p < r) {
    q = (p + r) / 2;
    merge_sort(arr, p, q); // divide metades esquerdas
    merge_sort(arr, q + 1, r); // divide metades direitas
    merge(arr, p, q, r); // intercala
  }
  return;
}
```
Este link traz um ótima visualização do funcionamento do Merge Sort: https://visualgo.net/bn/sorting

### Comlexidade de tempo

Independente de o vetor já estar ordenado de forma crescente ou de forma decrescente, o algoritmo sempre irá dividir o problema por dois até chegar ao caso base e então juntar as soluções novamente. Assim, a complexidade no pior caso e melhor caso é igual.

A função de intercalação terá custo O(n). A partir disso é possível montar a relação de recorrência do algoritmo completo. Quando o vetor tem tamanho 1, não é preciso ordenar e o algoritmo retorna, o custo é constante. Caso contrário, além do custo da intercalação tem-se o custo das duas chamadas recursivas, sendo que cada uma delas trabalha com uma metade da entrada, então temos:

T(n) = 2T(n / 2) + n

T(1) = 1

Resolvendo alguns termos é possível perceber um padrão nas fórmulas: 

T(n) = 2T(n / 2) + n

2T(n / 2) = 4T(n / 4) + n

4T(n / 4) = 8T(n / 8) + n

8T(n / 8) = 16T(n / 16) + n

...

2<sup>k</sup>T(n / 2<sup>k</sup>) = 2<sup>k + 1</sup>T(n / 2<sup>k + 1</sup>) + n

Chegaremos em T(1), o caso base, quando 2<sup>k</sup> = n. Isso quer dizer que k = log<sub>2</sub>n, ou seja, o termo n deve ser somado log<sub>2</sub>n vezes, levando a uma complexidade de tempo **O(n log<sub>2</sub>n)**. 

### Complexidade de espaço

Analisando o número de chamadas, veremos que em qualquer caso o algoritmo fará até log<sub>2</sub>n chamadas, conforme a figura:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/arvore_merge.png)

(Fonte: https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort)

Para n = 64, por exemplo, a altura da árvore será 6, lembrando que log<sub>2</sub>64 = 6.                          

Entretando, diferente do seleção, inserção e bolha, o merge sort precisa criar dois vetores auxiliares para fazer a intercalação. Por isso na hora de calcular a complexidade de espaço é necessário considerar o consumo extra de memória. 

Na última etapa, ao intercalar as duas maiores metades do vetor, são criados dois vetores de tamanho n / 2, logo o consumo de memória é **O(n)**.

## Quick Sort

Assim como o merge sort, o quick sort é um algoritmo de ordenação que usa a ideia de divisão e conquista. Sua implementação clássica também é recursiva. A diferença entre os dois algoritmos está na maneira como é feita a divisão do problema. 

O ponto de início do quick sort é escolher um pivô, que é um item qualquer do vetor. A partir do pivô, o vetor é separado em duas partes: 
- Todos os itens menores que o pivô irão formar um subvetor;
- Todos os itens maiores que o pivô irão formar outro subvetor.

Esse processo é feito repetidas vezes até encontrar subvetores com um único item (caso base).

Apesar de falarmos do conceito de subvetor, não é necessário criar vetores auxiliares para cada subvetor, como era feito no merge sort. 

A maneira mais simples de trabalhar com esse algoritmo é percorrer o vetor, movendo todos itens menores que o pivô para a sua esquerda (realizando trocas no próprio vetor, como nos métodos simples).

A seguir é apresentado um exemplo de método para particionamento. Este método é atribuído a Nico Lomuto e popularizou-se nos livros sobre algoritmos. O último item do vetor é selecionado como pivô.
```c
int separa(int v[], int primeiro, int ultimo){
   int pivo = v[ultimo];
   int esquerda = primeiro;
   int atual;
   for(atual = primeiro; atual < ultimo; atual++){ 
      if (v[atual] <= pivo) { // coloca todos os itens menores que o pivô mais para a esquerda do vetor
          troca(&v[atual], &v[esquerda]);
         esquerda++;
      }
   }
   troca(&v[esquerda], &v[ultimo]); // coloca o pivô após o último item menor que ele
   return esquerda; // retorna a posição final do pivô
}
```
Ao final deste processo, o pivô já se encontra na sua posição final, e não precisa ser analisado na próxima etapa. O valor "esquerda" retornado pela função, marca a posição final do pivô.

O método "separa" será chamado várias vezes na função "quick_sort" abaixo:
```c
void quick_sort(int v[], int p, int r) {
   if(p < r) {
      int q = separa(v, p, r); // após chamar o método separa, q recebe a posição final do pivõ, que divide o vetor em 2 partes
      quick_sort(v, p, q - 1); // chama o método novamente para a parte esquerda
      quick_sort(v, q + 1, r); // chama o método novamente para a parte direita
   }
   return;
}
```

Na figura abaixo, os itens em azul representam itens que foram pivôs nas etapas anteriores, portanto não serão examinados na etapa atual.

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/quick.png)

(Fonte: https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/overview-of-quicksort)

### Complexidade de tempo

Vamos analisar duas situações: o melhor caso e o pior caso do quick sort. 

O **melhor caso** do quick sort seria quando o pivô selecionado sempre consegue dividir o vetor em dois subvetores de tamanhos iguais, pois desta forma o problema sempre seria divido ao meio, como no merge sort. Portanto, a complexidade de tempo no melhor caso é dada pela mesma relação de recorreência do merge sort:

T(n) = 2T(n / 2) + n 

T(1) = 1

Quando n é 1, o vetor já está na ordem e a função retorna. Quando n é maior que 1, existe o custo das duas chamadas recursivas que dividem o problema em duas partes e existe também o custo do método de particionamento. Na primeira execução do método de particionamento, ele precisa percorrer o vetor inteiro, tendo um custo n. Como visto anteriormente, essa relação de recorrência irá resultar no custo **O(n log<sub>2</sub>n)**. 

O **pior caso** do quick sort acontece quando todos os elementos são maiores que o pivô ou todos os elementos são menores que o pivô, gerando um subvetor com 0 itens de um lado e um subvetor com n - 1 itens do outro, ou seja: vetores já ordenados de alguma maneira, seja crescente ou decrescente. Exemplo: um vetor já ordenado: {1, 2, 3, 4, 5}

- Na primeira etapa, p pivô é o 5. O método de particionamento percorre os n itens e nenhuma troca é feita, pois ninguém é maior que o pivô. O pivô permanece no lugar e o método retorna a posição 4.

- Na segunda etapa, o pivô é o 4. O método de particionamento percorre os n - 1 itens e nenhuma troca é feita, pois ninguém é maior que o pivô. O pivô permanece no lugar e o método retorna a posição 3.

- Na terceira etapa, o pivô é o 3. O método de particionamento percorre os n - 2 itens e nenhuma troca é feita, pois ninguém é maior que o pivô. O pivô permanece no lugar e o método retorna a posição 2.

E assim por diante.

Ou seja, a cada etapa conseguimos diminuir apenas um item do problema. O custo novamente será definido por:

T(n) = n + (n - 1) + (n - 2) + ... + 3 + 2 + 1

Que de acordo com os cálculos feitos anteriormente leva à complexidade **O(n²)**.

### Complexidade de espaço

Diferente do merge sort, este método tem a vantagem de não precisar de memória auxiliar. Então, temos que analisar a pilha de chamadas.

No melhor caso, quando o problema sempre se divide ao meio, teremos até log<sub>2</sub>n chamadas, como no merge sort.

No piror caso, teremos até n chamadas empilhadas, como mostra a ilustração:

![all text](https://github.com/emanoelim/algoritmos_e_ed/blob/master/img/arvore_pior_caso_quick.png)

(Fonte: https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/analysis-of-merge-sort)

Portanto, para aimplementação estudada, a complexidade de espaço chega a O(n).

Entretanto, o quick sort pode ser otimizado para que tenha um consumo de espaço de apenas **O(log<sub>2</sub>n)**, através da abordagem proposta por Robert Sedgewick. Nesta abordagem o menor subvetor é ordenado de maneira recursiva, mas o maior subvetor é ordenado de maneira iterativa (while), assim não adiciona chamadas na pilha. Você pode encontrar este tipo de implementação aqui: https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/.

## Referências:
- Cormen, T. H. “Desmistificando algoritmos”. 1ª ed. Rio de Janeiro, Elsevier, 2014.
- Khan Academy. "Merge Sort": https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort
- Khan Academy. "Quick Sort": https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/overview-of-quicksort

## Leitura recomendada:
- GeeksForGeeks. "Quick Sort x Merge Sort": https://www.geeksforgeeks.org/quick-sort-vs-merge-sort/

