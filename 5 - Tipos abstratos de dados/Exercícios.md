# Exercícios TAD

1) Criar um TAD para representar frações, utilizando a seguinte estrutura:

```c
struct fracao {
  int numerador;
  int denominador;
};

```
Escreva funções para:
- Criar uma fração;
- Liberar uma fração;
- Somar duas frações;
- Subtrair duas frações;
- Multiplicar duas frações;
- Dividir duas frações;
- Imprimir fração (formato numerador/denominador).

___
2) Criar um TAD para representar um vetor no R3, utilizando a seguinte estrutura:
```c
struct r3 {
    int x;
    int y;
    int z;
};
```
Escreva funções para:
- Criar um vetor no R3;
- Liberar um vetor no R3;
- Somar dois vetores no R3;
- Calcular o produto escalar entre dois vetores no R3;
- Calcular o produto vetorial entre dois vetores no R3;
- Imprimir um vetor no R3.

**Formulário:**

Considere que:
```diff
v = (v1, v2, v3) 
w = (w1, w2, w3)
```

Soma:
```diff
v + w = (v1+w1, v2+w2, v3+w3)
```

Produto escalar:
```diff
v.w = v1w1+v2w2+v3w3
```

Produto vetorial:
```diff
v x w = (v2w3-v3w2, v3w1-v1w3, v1w2-v2w1)
```
___
3) Um número complexo é um número z que pode ser escrito na forma:
```diff
z = x + yi
```

onde x representa a parte real de z e y representa a parte imaginária de z. 

Dentre as operações elementares com números complexos, encontra-se a operação de soma. Considere dois números complexos, z e w:
```diff
z = a + bi
w = c + di
```

Para somar dois números complexos deve-se somar a parte real do primeiro número com a parte real do segundo número, e a parte imaginária do primeiro número com a parte imaginária do segundo número. O resultado é um terceiro número complexo:
```diff
z + w
(a + bi) + (c + di)
(a + c) + (b + d)i
```

    Abaixo, alguns exemplos de soma de números complexos:
```diff
(6 + 5i) + (2 + i) = 8 + 6i
(1 + 7i) + (3 + 2i) = 4 + 9i
(5 + 8i) + (2 - 3i) = 7 + 5i
```

Criar um TAD (Tipo Abstrato de Dados) para representar números complexos. Use a seguinte estrutura:
```c
struct complexo {
    int parte_real;
    int parte_imaginaria;
};
```

Escrever funções para:
- Criar número complexo (receber parte real e parte imaginária e retornar um número complexo);
- Imprimir um número complexo no formato: “x + yi”;
- Somar dois números complexos (receber dois números complexos e retornar um terceiro número complexo formado pelo - resultado da soma);
- Liberar um número complexo;

___

4) Criar um TAD livro, sendo que a estrutura deve conter os campos:
- Título;
- Autor;
- Gênero;
- Número de páginas;
- Ano de lançamento;

Em seguida:
- Criar funções para alocar/liberar memória para um vetor de livros;
- Criar uma função para cadastrar um livro;
- Criar uma função que recebe um vetor de livros e imprime os dados do livro com mais páginas;
- Criar uma função que recebe um vetor de livros e um ano, e imprime todos os livros lançados naquele ano;
- Criar uma função que recebe um vetor de livros e um gênero, e imprime todos os livros daquele gênero;
- Na função main criar um vetor de 5 livros para testar as funções criadas.
- Após a utilização do vetor, liberar a memória.


