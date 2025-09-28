#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maiorRiqueza = 0;

    for(int i = 0; i < accountsSize; i++){
        int temp = 0;
        for(int j = 0; j < *accountsColSize; j++){
            temp += accounts[i][j];
        }
        if(temp > maiorRiqueza)
            maiorRiqueza = temp;
    }
    return maiorRiqueza;
}
int main(){ //Caso queira executar o programa no terminal ou no Visual Studio
    int** contas;
    int accountsSize = 2;
    int accountsColSize = 3;

    contas = (int**) malloc(accountsSize * sizeof(int*));
    for(int i = 0; i < accountsSize; i++){
        contas[i] = (int*) malloc(accountsColSize * sizeof(int));
    }

    // Preencha os valores de cada conta por aqui, accountsSize = número de clientes e accountsColSize = número de contas por cliente
    contas[0][0] = 1; contas[0][1] = 2; contas[0][2] = 3;
    contas[1][0] = 3; contas[1][1] = 2; contas[1][2] = 1;

    printf("A maior riqueza entre os clientes é: %d\n", maximumWealth(contas, accountsSize, &accountsColSize));

    for(int i = 0; i < accountsSize; i++){
        free(contas[i]);
    }
    free(contas);

    return 0;
}
