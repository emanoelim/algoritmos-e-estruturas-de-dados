# Lista structs - 1

Exercícios baseados no material do professor André Backes: http://www.facom.ufu.br/~backes/gsi002.html 

1) Implemente um programa que leia o nome, sigla do estado, cidade, rua e número da casa de uma pessoa e armazene os dados 
em uma estrutura. Depois, imprima os dados.
___
2) Crie uma estrutura para armazenar uma coordenada polar, composta por raio (r) e argumento (a). Crie também uma 
estrutura para armazenar uma coordenada do plano cartesiano, composta por x e y, sabendo que:
- x = r ∗ cos(a)
- y = r ∗ sin(a)

No programa principal, leia e salve um ponto em coordenada polar. Faça a conversão de coordenada polar para coordenada
cartesiana e salve o resultado como um ponto do plano cartesiano. Mostre o ponto resultante.
___
3) Construa uma estrutura aluno com nome, número de matrícula, curso e coeficiente. Leia do usuário a informação de 5 
alunos, armazene em vetor dessa estrutura e imprima os dados na tela.
___
4) Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, 
nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
- Permita ao usuário entrar com os dados de 5 alunos;
- Encontre o aluno com maior nota da primeira prova;
- Encontre o aluno com maior média geral;
- Encontre o aluno com menor média geral;  ́
- Percorra o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
___
5) Faça um programa que leia os dados de 10 alunos (nome, matrícula e média final), armazenando em um vetor. Uma vez 
lidos os dados, divida estes dados em 2 novos vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a 
média mínima para a aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos  dados do vetor
de reprovados.
___
6) Faça um programa que leia um vetor com os dados de 5 carros:  modelo, marca, ano e preço. Leia um valor *p* e mostre 
as informações de todos os carros com  preço menor que *p*. Repita este processo até que seja lido um valor *p* = 0.
___
7) Faça um programa que leia um vetor com dados de 5 livros: título, autor e ano. Permita ao usuário:
- Cadastrar um livro;
- Buscar livros pelo título (mostrar todos os livros com o título igual ao buscado);
- Buscar livros pelo ano (mostrar todos os livros com o ano igual ao buscado);
___
8) Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa:
- Leia e armazene os dados 5 eletrodomésticos que contém nome, potência (em kW) e tempo médio ativo por dia (em horas);
- Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodoméstico 
(consumo/consumo total) neste período de tempo. Apresente este último dado em porcentagem.
___
9) Faça um programa que gerencie o estoque de um mercado e:
- Leia e armazene um vetor de 5 produtos, com os dados: código, nome, preço e quantidade.
- Leia um pedido, composto por um código de produto e quantidade. 
- Localize este código no vetor e, se houver quantidade suficiente para atender ao pedido  integralmente, 
atualize o estoque e informe para o usuário que o pedido foi realizado com sucesso. Se não, informe que o pedido não foi 
concluído por falta de estoque.
___
10) Faça um programa que armazene em uma estrutura os dados de um funcionário de uma empresa, compostos de: Nome, 
Idade, Sexo (M/F), CPF,  Data de Nascimento, Código do Setor onde trabalha (0-99), Cargo que ocupa e Salário. 
Os dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela. Obs.: crie uma estrutura para 
armazenar a data de nascimento e use esta estrutura dentro da estrutura do cadastro.
___
11) Escreva um programa para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
- Horário: composto de hora, minutos e segundos.  ́
- Data: composto de dia, mês e ano.
- Compromisso: composto de uma data, horário e texto que descreve o compromisso.

Faça o cadastro de alguns compromissos e imprima todos os compromissos de um mês solicitado pelo usuário.
___
12) Criar uma estrutura para armazenar dados de filmes: título, diretor, gênero, duração (em minutos) e nota (1, 2, 3, 4 ou 5 estrelas). 
- Leia e armazene informações de alguns filmes;
- Crie uma função para retornar o cadastro do filme mais longo.
- Crie uma função para mostrar os dados dos filmes com 5 estrelas.
- Crie uma função para mostrar os dados dos filmes com apenas 1 estrela.
- Crie uma função para mostrar todos os filmes de um determinado diretor.
- Crie uma função para mostrar todos os filmes de um determinado gênero.
___
13) Seu objetivo neste exercício é fazer um programa para simular uma agenda de telefones. Para cada pessoa na agenda, 
devem-se ter os seguintes dados: Nome, E-mail, Endereço (contendo campos estado (sigla), cidade, rua e número da casa), Telefone (contendo campos 
para DDD e número) e Data de aniversário (contendo campos para dia, mês, ano). Etapas a serem realizadas:
- Definir a estrutura acima (considerando que Endereço, Telefone e Data de aniversário devem ser estruturas separadas que
serão utilizadas pela estrutura de agenda).
- Declarar um vetor do tipo agenda com capacidade de agendar até 10 nomes.  
- Definir uma função insere_pessoa(): Insere por ordem alfabética de nome. Dica: para inserir em ordem alfabética, você 
pode ir comparado o nome do cadastro a ser inserido com os nomes dos cadastros já existentes no vetor. Para isso, use a 
função strcmp() que serve para comparar duas strings. Veja mais sobre a função aqui: 
http://www.br-c.org/doku.php?id=strcmp. 
- Definir uma função imprime_agenda(): Imprime as informações de todos os contatos.
- Definir uma função busca_primeiro_nome(): Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa com 
o nome, imprime para todas).
- Definir uma função busca_mes(): Imprime os dados de  todas as pessoas que fazem aniversário nesse mês.
- Definir uma função busca_dia_mes(): Imprime os  dados de todas as pessoas que fazem aniversário nesse dia e mês.
- Definir uma função retira_pessoa(): Para retirar o cadastro de uma pessoa, basta sobrepor o cadastro dela com o cadastro seguinte, e assim por diante.






