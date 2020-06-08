# Estratégias para tratamento de colisões

Uma função de hashing está sujeita a gerar a mesma posição para chaves diferentes, situação que chamamos de colisão. Imagine que 
a função usada é a de divisão e que o tamanho da tabela é 50. Para um item com chave igual a 100, o resto será 0, então o item 
será colocado na posição 0. Mas, para um item com chave igual a 400, o resto também será zero, fazendo com que a posição 0 seja 
sobrescrita. 

Analogamente, irão acontecer problemas na busca. Considere buscar o item 900. Ele não foi inserido na tabela, mas como o 
resto de 900 por 50 é 0, será mostrado o item 400, que está na posição 0. 

Colisões podem acontecer com qualquer função de hashing escolhida, por isso elas precisam ser tratadas. Assim, além de escolher
uma boa função de hashing, precisamos definir uma estratégia para tratamento de colisões. Abaixo são apresentadas as estratégias de endereçamento aberto e endereçamento separado.

## Tratamento de colisões por endereçamento aberto

 Caso aconteça uma colisão, buscar na tabela outra posição ainda não ocupada. Existem diferente formas de fazer isso. Abaixo são
 apresentados métodos comuns desta abordagem.
 
 ### Sondagem linear
 
 Se a posição calculada está ocupada, tentar a próxima posição, e assim por diante, até achar uma posição livre. No exemplo abaixo,
 a função recebe a posição gerada inicialmente e o número da tentativa (i), a partir disso gera uma nova posição:
 ```c
 int sondagem_linear(int posicao, int i) {
    return (posicao + i) % TABLESIZE;
}
 ```
 Esta estratégia tem a vantagem de ser simples de implementar. Mas, a grande desvantagem desta estratégia é que ela tende a 
 ir agrupando itens, fenômeno chamado de “agrupamento primário”, quando tem-se longas sequências de posições ocupadas. 
 A medida que a tabela vai ficando cheia, o tempo para incluir um item aumenta. Na inserção, o pior caso vai ser O(n), 
 considerando que a posição calculada foi a primeira, mas a próxima posição livre é a última. O mesmo acontece para a busca.
 
**Custo da função:**

- **Pior caso**: se todas as chaves forem mapeadas para o mesmo índice, a complexidade será **O(n)** - para inserção, busca e remoção*.
- **Melhor caso**: **O(1)** - nenhuma colisão acontece.

*abordada após os métodos de tratamento de colisões.
 
### Sondagem quadrática
Tenta espalhar os elementos usando uma equação do segundo grau:

h(k) = (pos + c1*i + c2*i*i) % m

onde:
- k = chave
- pos = posição inicialmente calculada
- c1 e c2: coeficientes
- i = tentativa atual
- m = tamanho da tabela

A sondagem quadrática requer cuidados ao selecionar os valores de c1, c2 e m. Pois, dependendo da escolha, pode ser que a fórmula 
gere posições repetidas, enquanto algumas posições nunca são calculadas. Assim, um item pode acabar não sendo inserido mesmo se 
houverem posições vagas. Uma boa escolha é usar m como uma potência de 2, juntamente com c1 = c2 = 0,5. Isso fará com que 
valores distintos sempre sejam gerados. 

A figura abaixo mostra a diferença no cálculo das posições entre a sondagem linear e quadrática:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/linear_x_quadratica.png)

Fonte da imagem: Lucas Antiqueira, "Métodos de busca: Hashing", Slide disciplina de Introdução à Ciência da Computação II, disponível em: http://wiki.icmc.usp.br/images/4/44/SCC0601-2oSem2011-Lucas-Slides12.pdf

Esta função diminui o problema de agrupamento primário gerado pela sondagem linear, mas ainda está sujeita agrupamentos.

**Custo da função:**
- **Pior caso**: a complexidade também pode chegar a O(n).
- **Melhor caso**: a complexidade é O(1) - nenhuma colisão acontece.

### Duplo hash
Caso a posição calculada gere colisão, chama-se uma segunda função de hash:

h(k) = h1 + i * h2

onde:
- h1 = posição calculada inicialmente pela primeira função de hash;
- i = tentativa atual;
- h2 = posição calculada pela segunda função de hash.

h1 e h2 devem ser duas funções diferentes. Além disso, h2 deve ser uma função que de hash que não retorne zero, pois caso isso aconteça não haverá deslocamento nenhum.

Uma possibilidade, é definir h2 em termos de h1:

h2(k) = 1, se h1(k) = 0

h2(k) = m - h1(k), se h1(k) >  0

onde m é o tamanho da tabela. Ele deve ser preferencialmente um número primo.

Dentre as técnicas estudadas, o duplo hash é a melhor estratégia de endereçamento aberto. Introduz uma maior aleatoriedade na hora de redefinir as posições, diminuindo muito os agrupamentos. 

**Custo da função:**
- **Pior caso**: com muito azar, o custo ainda pode chegar a O(n).
- **Melhor caso**: será O(1) - sem colisões.

### Removendo um item da tabela

A operação de remoção requer cuidados. Imagine que o tamanho da tabela é 10 e  serão inseridos itens com chaves 10, 20, 30 e 40. A função de hashing usada é a de divisão e para o tratamento de colisões a abordagem é a sondagem linear. A ocupação da tabela após as inserções é mostrada abaixo:

| Posição | Chave |
|---------|-------|
| 0       | 10    |
| 1       | 20    |
| 2       | 30    |
| 3       | 40    |
| ...     | ...   |
| 9       | NULL  |

Se for removido o 30 e a posição 2 ficar como NULL, como no exemplo abaixo:

| Posição | Chave |
|---------|-------|
| 0       | 10    |
| 1       | 20    |
| 2       | NULL  |
| 3       | 40    |
| ...     | ...   |
| 9       | NULL  |

Ao tentar buscar o item de chave 40, a busca irá encontrar o NULL na posição 2 e irá encerrar, sem encontrar o item.

Uma alternativa é: em vez de remover o item, marcá-lo com uma flag que indica que ele é um item “deletado”:

- Na inserção de um novo item, se a posição calculada já tiver um item marcado como deletado, a posição pode ser sobrescrita com o novo item;
- Na busca, ao encontrar um item marcado como deletado, a busca não termina. Ela segue até achar o item procurado, ou até terminar de varrer todas as posições possíveis.

Perceba que a desvantagem dessa implementação é que ela não remove os itens de fato. A busca ainda precisa passar pelos itens marcados como deletados. Ou seja, este tipo de tratamento pode ser bom para inserção, mas não é tão bom para a busca. Uma alternativa a este problema pode ser verificada no tratamento de colisões por endereçamento separado.

## Tratamento de colisão por endereçamento separado

Em vez de procurar uma posição vaga, cada posição do vetor guarda o início de uma lista encadeada. Todas as colisões, ou seja, 
todas as chaves mapeadas para uma mesma posição, são guardadas em uma lista. Exemplo:

![all text](https://github.com/emanoelim/algoritmos_e_estruturas_de_dados/blob/master/img/hash_lista_encadeada.png)

Para a inserção, o pior caso será O(1): calcula-se a posição onde o item será inserido e, mesmo que já existam itens na lista 
encadeada daquela posição, o novo item pode ser inserido no começo da lista a um custo constante. 

Para buscar um item, o custo no pior caso será proporcional ao número de itens que existem na lista encadeada, pois será 
necessário fazer uma busca sequencial na lista. 

## Referências
- Backes, André Ricardo, **Estruturas de dados descomplicada: em linguagem C**, 1ª ed., Rio de Janeiro: Elsevier, 2016
- Notas de aula Prof. Luis Gustavo Nonato: http://www.lcad.icmc.usp.br/~nonato/ED/Hashing/node33.html
- Vitter, J. S., Flajolet, P. cap. "Average cases analysis of algorithms and data structures" em **Handbook of theoretical computer science vol. A - algorithms and complexity**, Elsevier, 1990. 
- Ziviani, N. **Projeto de algoritmos com implementações em C e Pascal**, Cengage Learning, 3ª ed., 2010.




