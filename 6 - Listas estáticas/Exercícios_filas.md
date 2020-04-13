# Exercícios com filas estáticas

1) Mostre como fica a fila f, inicialmente vazia, após a execução das operações a seguir:
```diff
Enfila(f ,'a');
Enfila(f ,'a'); 
Enfila(f ,'b'); 
Enfila(f ,'c'); 
Enfila(f , Espia(f));
Enfila(f , Desenfila(f) );
Desenfila(f);
Enfila(f, 'e');
Desenfila(f); 
Enfila (f, Espia(f)); 
Enfila(f , Enfila(f ,'g') + 'a');
```

- A função Espia() retorna o item que seria desenfilado, mas não desenfila o item; 
- A função Desenfila() retorna o item desenfilado; 
- A função Enfila() retorna 1 quando consegue enfilar e 0 quando não consegue. 
___

2) Escreva uma nova função para o TAD Fila: a função remove_duplicados(). A função recebe uma fila e remove os itens duplicados (com mesma chave). Você pode utilizar uma fila auxiliar. Exemplo:
- Fila inicial: 1, 10, 10, 10, 3, 24, 4, 1, 24
- Fila com duplicados removidos: 1, 10, 3, 24, 4
___

3) Escreva uma função que inverte os itens de uma fila utilizando uma pilha auxiliar.
___

4) https://www.hackerrank.com/contests/exercicios-pilhas-e-filas/challenges/fila-02-jogando-cartas-fora
___

5) https://www.hackerrank.com/contests/exercicios-pilhas-e-filas/challenges/fila-05-velhinhos-no-banco
___

6) Você possui um TAD Pilha que possui as principais funções de uma pilha: cria_pilha_vazia(), libera(), empilha() e desempilha(), mas você precisa resolver um exercício que usa filas. Em vez de usar um TAD Fila, crie duas funções, enfila() e desenfila(), sendo que estas funções simulam o comportamento de uma fila utilizando apenas pilhas e suas funções. 
