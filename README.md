# Estrutura-de-Dados-Final
Trabalho final da cadeira Estrutura de Dados 2020/2



1. Introdução
	Como Trabalho Final Prático da cadeira de Estrutura de Dados, foi montado um programa buscador de tweets, implementado diversas estruturas de dados vistas ao longo do semestre. Os tweets estavam organizados em um arquivo com um id para cada tweet, e as palavras a serem consultadas estavam em outro arquivo.  
	Foram montadas duas versões do programa, uma usando uma árvore ABP e outro usando uma árvore AVL, que tinham a função de armazenar em seus nodos as palavras presentes nos tweets. Também foi implementado em ambos os programas uma lista, para armazenar em qual tweet cada palavra foi encontrada.

	Para o uso da aplicação, a base de dados com os tweets deve ter o formato "id;tweet" para a correta indexação, a base de consulta deve ter uma palavra por linha. Para a chamada da aplicação, que deve ser feita por linha de comando, utilizar o formato: EXE.exe <arq_base> <arq_consulta> <arq_saída>

2. Árvores ABP e AVL
	2.1 Árvores ABP
	A árvore ABP é a forma mais simples de árvore binária, sem nenhuma forma de balanceamento. Cada nodo é inserido, baseado em sua ordem lexicográfica, ou a esquerda ou a direita do nodo anterior. Caso o nodo seja igual a um nodo já existente na árvore, ele apenas terá seu ID adicionado à lista de ocorrências. Como não há uma forma de balanceamento, não há rotações no processo de indexação.
	2.2 Árvores AVL
	A árvore AVL, diferente da ABP, é uma árvore binária balanceada, ou seja, ela tem uma organização que visa otimizar o processo de consulta e indexação. No caso da AVL, o balanceamento ocorre baseado num Fator de Balanceamento, presente em cada nodo, que evita que a árvore cresça de forma desigual para algum dos lados. Esse balanceamento garante que, em qualquer sub-árvore, não haverá uma diferença de altura maior que 1 entre cada uma de suas sub-árvores.
3. Objetivos e Parâmetros
	O objetivo do trabalho foi comparar a efetividade de duas árvores, ABP e AVL, através do número de comparações realizadas em seus nodos durante um processo de busca de tweets. 
	Foram levados em consideração 4 parâmetros para determinar a efetividade de dada árvore, foram eles: Número de comparações realizadas durante a indexação das palavras dos tweets, número de rotações realizadas durante a indexação (presente apenas na AVL), altura da árvore após o processo de indexação e, por fim, número de comparações durante a etapa de consulta das palavras.

4. Resultados
	Os programas foram testados com 3 bancos de tweets diferentes, cada um com uma quantidade maior de tweets. A seguir, os resultados de cada programa, em cada teste.


|---|Base de 100 tweets|---|
|---|------------------|---|
|---|ABP|AVL|        
|Nodos		|704|704|
|Comparações	|11441|10490|
|Rotações	|---| 511|
|Altura		|22|11|
|Comp. Consulta	|98|83|


|---|Base de 10k tweets|---|
|---|------------------|---|
|---|ABP|AVL|        
|Nodos		|15576|15576|
|Comparações	|1397994|1368140|
|Rotações	|---|11048|
|Altura		|34|17|
|Comp. Consulta	|97|83|



|---|Base de 900k tweets|---|
|---|------------------|---|
|---|ABP|AVL|        
|Nodos		|175807|175807|
|Comparações	|124034615|130041774|
|Rotações	|---|124920|
|Altura		|45|21|
|Comp. Consulta	|97|85|


5. Conclusões
Com a análise dos resultados obtidos, podemos perceber alguns padrõesentre os testes. O número de comparações durante o processo de indexação é similar entre as duas árvores,com diferenças pequenas para os dados usados. Porém, as árvores AVL tem que fazer o processo de rotação de seus nós, o que acabou tornado os testes com essa árvore mais demorados.A  altura  das árvores  éonde  conseguimos  ver  bem  a diferençaentre os  dois  modelos.  A  altura  da  árvore  AVL  foi  sempre  ao  menos metade da altura da arvore ABP, que não é balanceada.O número de comparações na fase de consulta mostrou ser um pouco  diferente  entre  as  duas árvores.  A  AVL  foi  objetivamente superior  nesse  aspecto,  com  uma diferença de mais de 15% apartir de 9 consultas, chegando em torno de 20% com 1000 consultas.Esses  dados  nos  mostram  que  as  árvores  AVLs  tem uma  clara vantagem no processo de consulta em relação as árvores ABP, apesar de  terem  um  processo  de  indexação  um  pouco  mais  lento  devido às rotações.Esse aumento da velocidade de consulta se deve as rotações e balanceamentos que ocorrem na AVL. Um problema das ABPs é que caso o dado que quer ser consultado esteja nos nodos mais baixos da 
árvore  o  processo  de  consulta  demorará  muito  mais. Esse “azar” no processo de indexação é mitigado pelo balanceamento das AVLs. Ao  decidir  qual  dos modelos  implementar  em  dado  sistema, deve-se levar em consideraçãoa quantidade de indexações e consultas que serão realizados. Em sistemas com muitos dados e que há muita consulta, o uso de uma AVL é recomendado. Caso a árvore seja menor e não haja tantas consultas,a ABP provavelmente será mais eficiente, devido à ausência de rotações.
6. Bibliografia e Recursos
MOREIRA, Viviane. Slides sobre Árvores Binárias de Pesquisa. Disponível no Moodle da disciplina
MOREIRA, Viviane. Slides sobre Árvores Balanceadas. Disponível no Moodle da disciplina