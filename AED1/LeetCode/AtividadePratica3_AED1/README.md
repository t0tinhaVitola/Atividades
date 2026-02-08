Autor: Otávio Bender Vitola
Algoritmo e Estruturas de Dados M1

Título do Problema: "Insert into a Binary Search Tree"

Descrição do Problema: "Dado o nodo raiz de uma Árvore Binária de Buscas (BST) e um valor para ser inserido na árvore. Retorne o nodo raiz da BST após a inserção. É garantido que o novo valor não existe previamente na BST."

Exemplos de entrada e saída do problema:

Entrada:

root = [4,2,7,1,3];
val = 5;
Saída: [4,2,7,1,3,5];

Entrada:

root = [40,20,60,10,30,50,70];
val = 25;
Saída: [40,20,60,10,30,50,70,null,null,25];

Entrada:

root = [4,2,7,1,3,null,null,null,null,null,null];
val = 5;
Saída: [4,2,7,1,3,5];

Complexidade do algoritmo final:

Tempo: 
- Melhor Caso / Caso Médio: O(log N)
- Pior Caso: O(n);
Espaço: O(1).

Contexto: Atividade prática realizada na plataforma do LeetCode (Problema 701) Código-fonte: Disponível no arquivo ".c" nesta pasta.
