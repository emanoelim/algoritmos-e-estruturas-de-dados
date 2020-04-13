# Exercícios com listas encadeadas

1) Cite as vantagens e desvantagens das listas encadeadas em relação às listas implementadas por meio de arranjos.
___
2) Escreva uma função que recebe duas listas encadeadas e concatena as duas (liga a segunda lista no final da primeira lista).
___
3) Escreva uma função que recebe 3 listas, sendo que a primeira guarda n números inteiros e a segunda e a terceira estão vazias. A função deve preencher a segunda lista com todos os números pares encontrados na primeira lista, e deve preencher a terceira lista com todos os números ímpares encontrados na primeira lista.
___
4) Escreva uma função que recebe duas listas. A primeira guarda n números inteiros e a segunda está vazia. A função deve inserir os elementos da primeira lista na segunda lista, de maneira ordenada.
___
5) Escreva uma função que recebe uma lista que guarda n números inteiros e verifica se a lista está ordenada (ordem crescente).
___
6) Considerando uma lista duplamente encadeada, escreva uma função que recebe uma lista e duas chaves. A função deve ser capaz de encontrar as células que correspondem às chaves (se existirem) e então trocá-las de lugar.
___
7) Escreva uma função para inserir itens em uma lista duplamente encadeada de forma ordenada.
___
8) Escreva uma função para inverter os itens de uma lista duplamente encadeada (sem utilizar lista auxiliar). Ex.:
- Lista original: 15, 20, 30, 40, 80
- Lista invertida: 80, 40, 30, 20, 15
___
9) Escreva uma função para remoção de nós duplicados (com mesma chave) em uma pilha encadeada, manipulando apenas o topo. Uma pilha auxiliar pode ser utilizada. Exemplo: 
- Pilha inicial: 0, 1, 2, 2, 3, 4, 8, 9, 9
- Pilha sem duplicados: 0, 1, 2, 3, 4, 8, 9
___
10) Em uma certa universidade tecnológica, existem 8 alunos homens para cada 2 mulheres. Sendo assim, o dono da cantina resolveu estabelecer uma “função maluca” para o preço do café no intervalo (horário de maior consumo). O café inicia pelo preço de R$ 0,50, mas aumenta R$ 0,10 sempre que a pessoa a ser atendida é homem. Quando uma mulher pede um café, seu preço volta a ser R$ 0,50.

Barney Gumble, sendo homem, quer saber quanto irá pagar por seu café sendo a N-ésima pessoa da fila. 
Dada a posição de Barney na fila, adicione pessoas na fila aleatoriamente para preenchê-la até a posição de Barney. Você pode gerar números aleatórios de 1 até 10. Sempre que o número for 5 ou 10, adicione uma mulher a fila. Para os outros números, adicione um homem na fila. Mostre qual será o preço do café.

Para gerar números aleatórios:
```c
srand(time(NULL));
x = rand() % 10 + 1;
```
(lembre de adicionar as bibliotecas time.h e stdlib.h).
___
11) Você está trabalhando em uma grande companhia que atua na área de recursos naturais. Usando imagens de satélite, a companhia deseja fazer um inventário de todas as árvores em uma determinada região. 

Você terá como entrada para o problema o número de árvores na região mapeada e o código da espécie de cada árvore detectada. Com base nisso, você deverá calcular e apresentar a porcentagem  em que cada espécie de árvore aparece na região. Mostre também qual é o código da espécie mais frequente.

Você NÃO deve utilizar um vetor para armazenar os dados das árvores, utilize alguma das estruturas estudadas.

Dica: ao percorrer os códigos de entrada, quando encontrar o código de uma espécie que já está  armazenada na estrutura, em vez de armazená-la novamente, incremente um campo de quantidade no item.
___
12) Uma agenda telefônica é armazenada como uma lista encadeada (simples ou dupla). Um item desta agenda é apresentado abaixo:
```c
struct item {
        char nome[30];
        char endereco[50];
        int telefone;
};
```
Adapte o seu TAD lista para trabalhar com o item acima, e também faça o que é pedido:
1. A função insere() deve inserir elementos de forma que estes permaneçam ordenados em ordem crescente de telefone;
2. A função remove(char nome[]) deve apagar elementos baseado no nome do contato;
3. Crie uma função imprime_contato(char nome[]) que encontra um contato com um certo nome e imprime seus dados na tela, ou então mostra uma mensagem informando que o contato não foi encontrado.


