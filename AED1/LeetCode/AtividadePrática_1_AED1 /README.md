Autor: Otávio Bender Vitola
Algoritmo e Estruturas de Dados M1

----------------------------------------

Título do Problema:
"Lemonade Change / Troco de Limonada"

Descrição do Problema:
"Numa barraca de limonada, cada limonada custa $5. Os clientes estão numa fila para comprar de você e pedem um de cada vez (na ordem especificada pelas contas/cédulas). 
Cada cliente comprará apenas uma limonada e pagará com uma nota de $5, $10 ou $20. Você deve fornecer o troco correto a cada cliente, de modo que a transação líquida seja o cliente pagar $5.
(OBS: Você não tem troco algum no início.)
Dado um array de inteiros *bills*, onde *bills[i]* é a nota do *i*-ésimo cliente paga, retorne *true* se você puder fornecer o troco correto a todos os clientes, ou *false* caso contrário."

Exemplos de entrada e saída do problema:
- Entrada: {5, 5, 5, 10, 20};
- Saída: true;

- Entrada: {5, 5, 10, 10, 20};
- Saída: false;

- Entrada: {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5}
- Saída: true.

----------------------------------------

Solução:
O problema foi resolvido utilizando a seguinte abordagem:
- Pagamento com $5: Apenas adicionamos ao acumulador de notas de $5 (int acumulador5);
- Pagamento com $10: Verificamos se tem alguma nota de $5, se houver, então decrementa 1 do acumulador5 e incrementa no acumulador de notas de $10 (int acumulador10). Se não houver, então retorna falso e o programa encerra;
- Pagamento com $20: Verificamos se tem, pelo menos, uma nota de $5 e uma nota de $10 em seus respectivos acumuladores, se houver, então decrementa dos acumuladores verificados e incrementa o acumulador de $20(int acumulador20).
Caso não haja notas de $10 suficientes, verifica se temos 3 (ou mais) notas de $5 no acumulador, se houver, então subtrai 3 do acumulador de $5 e incrementa o acumulador de $20.
Caso este teste falhe também, então retorna false e o programa se encerra.
- Após percorrer todo o vetor com sucesso, isso significa que ele conseguir dar o troco correto pra cada cliente, logo ele retorna true.

Complexidade do algoritmo final:
- Tempo: O(n);
- Espaço: O(1).

Detalhes da Implementação:
Contexto: Atividade prática realizada na plataforma do LeetCode (Problema 860)
Código-fonte: Disponível no arquivo ".c" nesta pasta.

----------------------------------------
