# Lista structs - 2

1) Um número complexo **z** é representado da seguinte forma:

z = a + bi

Onde **a** representa a parte real do número e **b** representa a parte imaginária do número. Exemplos:
- 2 + 5i
- 3 - 2i

Dois números complexos podem ser somados através da adição dos termos semelhantes, ou seja, somamos as partes reais de 
cada número e depois as partes imaginárias. Para os exemplos acima temos:

(2 + 3) + (5 - 2)i = 5 + i

a) Crie uma estrutura para representar um número complexo, ou seja, ela deve guardar a parte real do número e a parte imaginária
do número. 

b) Crie uma função soma_complexa() que recebe dois números complexos e retorna um novo número complexo que representa a soma.

c) Na função main, faça a leitura de dois números complexos e imprima a sua soma.
___
2) Crie uma struct para armazenar as coordenadas x e y de um ponto do plano cartesiano. Crie também uma função chamada distancia_euclidiana() 
que recebe dois pontos e retorna a distância euclidiana entre eles. A fórmula para o cálculo da distância entre um ponto A e
um ponto B é:

d = raiz_quadrada( (x<sub>b</sub> - x<sub>a</sub>)² + (y<sub>b</sub> - y<sub>a</sub>)² )

Na função main, ler dois pontos e imprimir a distância entre eles.
___
3) Utilize o tipo Ponto do exercício anterior para criar um vetor de 10 pontos na função main. Solicite que o usuário informe
as coordenadas dos 10 pontos e salve no vetor. Encontre o par de pontos mais afastado desse vetor. Dica: use a função de 
distância implementada no exercício anterior para encontrar a distância entre cada par de pontos.
___
4) Neste exercício você deverá computar a área de um retângulo:

a) Crie uma estrutura Ponto, como foi feito no exercício 2;

b) Crie a estrutura Retangulo que deve conter um vetor de 4 pontos. Considere que a posição 0 irá guardar o canto superior
esquerdo do retângulo, a posição 1 irá guardar o canto superior direito, a posição 2 irá guardar o canto inferior direito e a
posição 3 irá guardar o canto inferior esquerdo.

c) Crie uma função chamada calcula_area(), que recebe um tipo Retangulo e retorna a sua área. A área de um retângulo é dada
pela fórmula:

area = base * altura

d) Na função main, leia os 4 pontos de um retângulo e imprima a sua área.
___
5) Usando os tipos Ponto e Retangulo do exercício anterior, crie uma função que recebe um ponto e um retângulo e verifica se 
o ponto se encontra dentro do retângulo. Retorne 1 em caso positivo ou 0 em caso negativo.
___

Exercícios baseados em: https://www.cs.princeton.edu/courses/archive/fall02/cos126/exercises/structs.html
