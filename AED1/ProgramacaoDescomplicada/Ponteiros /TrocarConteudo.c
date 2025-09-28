
#include <stdio.h>

void TrocarConteudo(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main(){
    int valor1, valor2;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &valor1, &valor2);
    TrocarConteudo(&valor1, &valor2);

    printf("Valores trocados: \nA = %d, B = %d\n", valor1, valor2);
    return 0;
}
