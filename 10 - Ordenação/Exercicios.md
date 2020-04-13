## Exercícios ordenação

1. Com base nos pseudocódigos dos métodos estudados, implemente os algoritmos de ordenação por seleção, inserção e bolha.
___
2. Adapte seus algoritmos para exibir o número de trocas necessárias para ordenar um vetor. Faça testes com diferentes 
configurações de vetores: aleatório, crescente e decrescente.
___
3. Implementar uma função que recebe um vetor de palavras e as ordena em ordem alfabética. Dica: usar a função strcmp(str1, str2), verificando o retorno:
- 0: indica que str1 e str2 são iguais.
- negatvo: indica que o primeiro caractere que não corresponde tem um valor ASCII menor em str1 do que em str2.
- positivo: indica que o primeiro caractere que não corresponde tem um valor ASCII maior em str1 do que em str2.
___
5. A estrutura abaixo guarda o nome e o coeficiente de um aluno: 
```c
struct aluno {
    int ra;
    char nome[50];
    float coeficiente;
};
```
Implementar:
- Uma função que recebe um vetor de alunos e ordena o vetor em ordem alfabética.
- Uma função que recebe um vetor de alunos e ordena o vetor por coeficiente.
___
5. Implemente uma função de ordenação (seleção, inserção ou bolha) para uma lista implementada usando vetores.
___
6. Implemente uma função de ordenação (seleção, inserção ou bolha) para uma lista encadeada.
___
7. Qual será a complexidade da implementação do quick sort vista em aula se os itens do vetor forem todos iguais? Ex.: [10, 10, 10, 10, … , 10].
___
9. Reescrever o código de separação do quick sort para que o primeiro item do vetor seja usado como pivô. Isso irá mudar a complexidade do algoritmo?
___
10. Existe algum caso onde o desempenho da ordenação por inserção é melhor do que o desempenho do quicksort? 
___
11. Existe algum caso onde o desempenho da ordenação por inserção é melhor que o desempenho do merge sort?
___
12. Vimos que uma prática comum no quick sort é selecionar o primeiro ou último item do vetor como pivô. Pesquise outras formas de selecionar um pivô para o quick sort e qual seu impacto no desempenho do algoritmo.
