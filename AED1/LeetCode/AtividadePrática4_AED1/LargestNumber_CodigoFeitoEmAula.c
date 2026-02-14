/*
Essa parte do código foi feita em aula e está incompleta, o código-solução corrigido e funcional será disponibilizado em outro arquivo neste repositório. 
*/

void swap( int* a, int* b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

char convertChar( int a ) { // Incompleto
    int temp[10];
    int i = 0;
    while ( a % 9 > 0 ) {
        temp[i] = a % 10;
        a /= 10;
        i++;
    }
    temp[i] = a;

    for ( int j = 0; i < i; i++ ) {
        
    }

}

char* largestNumber(int* nums, int numsSize) {
    for ( int i = 0; i < numsSize; i++ ) {
        for ( int j = 0; j < numsSize && (j+1) < numsSize; j++ ) { // Percorrimento de vetor termina antes do que deveria
            int nums1 = nums[j] / 9;
            int nums2 = ( nums[j+1] ) / 9; // Lógica não funciona para números na casa das centenas, em diante.
            if ( nums1 > nums2 ) {
                swap( &nums[j], &nums[j+1] );
            } else {
                break; // O algoritmo do Bubble Sort não funciona corretamente com esse break
            }
        }
    }

    char* result = malloc(numsSize * sizeof(char)); // Desconsiderei errôneamente o /0 e também o comprimento que os números podem ter.
    int temp = 0;

    for ( int i = 0; i < numsSize; i++ ) {
        strcat( result, convertChar( nums[i] ) ); // Função não finalizada e não funcionaria para conversão de inteiro para carácter
    }

    return result;

}
