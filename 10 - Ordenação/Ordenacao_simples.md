# Ordenação
Ordenar é rearranjar um conjunto de itens em ordem ascendente ou descendente. Seu principal objetivo é facilitar a recuperação 
posterior dos itens do conjunto ordenado. Ex.: Uma lista telefônica: se a lista não fosse ordenada em ordem alfabética, ficaria 
bem mais difícil encontrar o contato desejado.
 
Os métodos de ordenação podem ser classificados em dois grupos: métodos simples (ou elementares) e métodos eficientes:
- Os métodos simples são adequados para arquivos pequenos, pois conseguem realizar a ordenação a um custo O(n²).
- Os métodos eficientes podem ser aplicados a arquivos maiores, pois conseguem realizar a ordenação a um custo O(n log n).

## Métodos de ordenação simples

Esses métodos produzem programas pequenos e fáceis de entender, que ilustram com simplicidade os princípios de ordenação. 
Além disso, existe um grande número de situações onde é melhor usar métodos simples em vez de métodos eficientes. Pois, 
apesar de métodos mais sofitisticados conseguirem ordenar um conjunto de dados usando menos comparações, estas comparações 
são mais complexas nos detalhes.

Alguns dos métodos simples mais conhecidos são: ordenação por seleção (*selection sort*), ordenação por inserção (*insertion sort*)
e bolha (*bubble sort*).

### Ordenação por seleção

É um dos métodos mais simples. Funciona da seguinte maneira: imagine um vetor v de tamanho N:
1. O menor item de v[0, …, N - 1] é selecionado e troca de lugar com o 1º item do vetor.
2. O menor item de v[1, …, N - 1] é selecionado e troca de lugar com o 2º item do vetor.
3. O menor item de v[2, …, N - 1] é selecionado e troca de lugar com o 3º item do vetor, e assim por diante.

Animação interativa do seleção: http://www.cs.armstrong.edu/liang/animation/web/SelectionSort.html

Pseudocódigo:
```diff
ORDENAÇÃO - SELEÇÃO:
para i ← 0 até N - 1
    min ← i
    para j ← i + 1 até N
        se vetor[j] < vetor[min], então
            min ← j
    troca(vetor, min, i)
```

Para calcular a complexidade deste método precisamos analisar os laços:
- Para a 1ª iteração do laço mais externo, as instruções do laço mais interno se repetem n vezes. 
- Para a 2ª iteração do laço mais externo, as instruções do laço mais interno se repetem n - 1 vezes.
- Para a 3ª iteração do laço mais externo, as instruções do laço mais interno se repetem n - 2 vezes.

E assim por diante, até que para a última iteração do laço mais externo, as instruções do laço mais interno são executadas 1 vez. 
Portanto o custo em relação ao tempo de execução pode ser definido por:

T(n) = n + (n - 1) + (n - 2) + … + 3 +  2 + 1 

Se T(n) é:
T(n) = n + (n - 1) + (n - 2) + … + 3 +  2 + 1

Então 2T(n) é:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/soma_1.png)

Que pode ser reescrito da seguinte forma, usando o truque de Gauss:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/soma_2.png)

Logo:

2T(n) = n(n + 1)

T(n) = n(n + 1) / 2

T(n) = (n² + n) / 2 

Isso quer dizer que o algoritmo terá uma complexidade de tempo O(n²). Essa complexidade é válida tanto no pior caso (quando o vetor estiver em ordem decrescente), quando no melhor caso (quando o vetor já estiver ordenado). Isso porque esse algoritmo não consegue identificar se o vetor já está em ordem e sempre executa todas as instruções. Por isso temos que:

- Pior caso Seleção = O(n²)
- Melhor caso Seleção = O(n²)

### Ordenação por inserção

O vetor é percorrido da esquerda para a direita selecionando um item por vez. Depois, todos os itens à esquerda do item selecionado são analisados. Sempre que um item for maior que o iitem selecionado, ele é deslocado para a direita. Feitos os deslocamentos necessários, ficará vaga a posição onde o item deve ser inserido.

Animação interativa do inserção: https://yongdanielliang.github.io/animation/web/InsertionSortNew.html

Pseudocódigo:
```diff
ORDENAÇÃO - INSERÇÃO:
para i ← 1 até N
    atual ← vetor[i]
    j ← i - 1
    enquanto j >= 0 e vetor[j] > atual:
        vetor[j + 1] = vetor[j]; 
        j ← j - 1    
    vetor[j + 1] ← atual
```

Considere um vetor em ordem decrescente: [ 5 | 4 | 3 | 2 | 1 ]:

- Quando i = 1, para que o 4 seja inserido no lugar correto, o laço interno precisa:
1. trocar o 5;

[ 4 | 5 | 3 | 2 | 1 ]

- Quando i = 2, para que o 3 seja inserido no lugar correto, o laço interno precisa:
1. trocar o 5;
2. trocar o 4;

[ 3 | 4 | 5 | 2 | 1 ]

- Quando i = 3, para que o 2 seja inserido no lugar correto, o laço interno precisa:
2. trocar o 5;
2. trocar o 4;
3. trocar o 3;

[ 2 | 3 | 4 | 5 | 1 ]

- Quando i = 4, para que o 1 seja inserido no lugar correto, o laço interno precisa:
1. trocar o 5;
2. trocar o 4;
3. trocar o 3;
4. trocar o 2;

[ 1 | 2 | 3 | 4 | 5 ]

Ou seja, o número de trocas de posições é: 1 + 2 + 3 + 4, que pode ser generalizado para:

T(n) = 1 + 2 + 3 + … + (n - 2) + (n - 1) + n

Que como foi visto no método anterior, leva a uma complexidade O(n²). 

Considere agora um vetor em ordem crescente: [ 1 | 2 | 3 | 4 | 5 ]:

- Quando i = 1, o item atual é maior que o item na posição j, o laço interno não executa;
- Quando i = 2, o item atual é maior que o item na posição j, o laço interno não executa;    
- Quando i = 3, o item atual é maior que o item na posição j, o laço interno não executa;    
- Quando i = 4, o item atual é maior que o item na posição j, o laço interno não executa;  

Ou seja, quando o vetor está ordenado, o laço interno nunca vai ser executado, então a complexidade será O(n). 

Podemos dizer então, que quando o vetor está em ordem decrescente, temos o pior caso do algoritmo, pois ele precisa fazer até n² trocas. Já quando o vetor está em ordem crescente, o algoritmo não é necessário fazer trocas, tendo apenas o custo do laço externo. Sendo assim:
- Pior caso Inserção = O(n²)
- Melhor caso Inserção = O(n)

### Bolha

O vetor vai sendo percorrido em ordem, comparando pares de elementos. Sempre que o par de elementos estiver desordenado, os elementos trocam de lugar. Ao fim de cada iteração, o último item do vetor já está na posição certa.

Além disso uma flag é usada para marcar sempre que alguma troca é feita. Se ao final do laço interno não aconteceu nenhuma troca, então o vetor já está ordenado e o algorítmo pode terminar.

Animação interativa do bolha: http://www.cs.armstrong.edu/liang/animation/web/BubbleSort.html
    
Pseudocódigo:
```diff
ORDENAÇÃO - BOLHA: 
para i ← N - 1 até 1
    flag ← 0  
    para j ← 0 até i - 1
        Se vetor[j] > vetor[j + 1], então
            troca(vetor, j, j + 1) 
            flag ← 1
    Se flag == 0, então
        termina
```

Considere um vetor em ordem crescente: [ 1 | 2 | 3 | 4 | 5 ]. 

No laço mais interno, vetor[j] sempre é menor que vetor [j + 1], nenhuma troca precisa ser feita e a flag nunca é atualizada para 1. Ao sair desse laço, a flag vale 0 e cai na validação que faz o programa terminar. Neste caso o algoritmo vai fazer apenas N comparações, portanto o custo será O(n).

Considere agora um vetor em ordem decrescente: [ 5 | 4 | 3 | 2 | 1 ]. 
- Para a 1ª iteração do laço mais externo, as instruções do laço mais interno se repetem n vezes. 
- Para a 2ª iteração do laço mais externo, as instruções do laço mais interno se repetem n - 1 vezes.
- Para a 3ª iteração do laço mais externo, as instruções do laço mais interno se repetem n - 2 vezes.

E assim por diante. Portanto o custo em relação ao tempo de execução pode ser definido por:

T(n) = n + (n - 1) + (n - 2) + … + 3 +  2 + 1 

Que já foi verificado que leva a um custo O(n²). 

Desta maneira, um vetor em ordem decrescente constitui o pior caso do algoritmo, enquanto um vetor em ordem crescente constitui o melhor caso do algoritmo. Podemos dizer então que:

- Pior caso Bolha = O(n²)
- Melhor caso Bolha = O(n)

Para os 3 algoritmos vistos, a complexidade de espaço será O(1), uma vez que não são recursivos e calculamos o custo com base na quantidade de memória usada com as variáveis. Perceba que nenhum destes métodos precisa de vetores auxiliares para fazer a ordenação. A ordenação é feita com base em trocas de posições no próprio vetor.

## Referências
- Ziviani, N. “Projeto de algoritmos: com implementações em Pascal e C”. 3ª ed, São Paulo, Cengage Learning,  2017.
- Cormen, T. H. “Desmistificando algoritmos”. 1ª ed. Rio de Janeiro, Elsevier, 2014.
- Link com visualizações dos métodos de ordenação: https://visualgo.net/bn/sorting
- Explicação do truque de Gauss para resolver o somatório dos n primeiros números: https://brilliant.org/wiki/sum-of-n-n2-or-n3/
