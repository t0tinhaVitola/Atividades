#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESERVADO (sizeof(int) * 5)
#define BUFFER ( ( char* ) pBuffer)
#define OPCAO  ( ( int * ) pBuffer)[0]
#define TAMANHO_TOTAL ( ( int * ) pBuffer)[1]
#define NPESSOAS ( ( int * ) pBuffer)[2] 
#define CONTADOR ( ( int * ) pBuffer)[3]
#define PESSOA_INICIAL ( ( char* ) pBuffer + RESERVADO )
#define TAMANHO_REMOVER ( ( int *) pBuffer)[4]


void *pBuffer = NULL;

void AdicionarPessoa(){
    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 100 + 1 );

    if ( pBuffer == NULL ) {
        printf("Não foi possível alocar mais memória!\n");
        return;
    }
    BUFFER[ TAMANHO_TOTAL ] = '/';
    printf("Digite o nome da pessoa: ");
    scanf(" %30[^\n]", &BUFFER[ TAMANHO_TOTAL + 1 ] );
    TAMANHO_TOTAL += strlen( &BUFFER[ TAMANHO_TOTAL ] );
    BUFFER[ TAMANHO_TOTAL++ ] = '_';
    BUFFER[ TAMANHO_TOTAL ] = '\0';

    printf("Digite a idade da pessoa: ");
    scanf(" %5s", &BUFFER[ TAMANHO_TOTAL ]);
    TAMANHO_TOTAL += strlen( &BUFFER[ TAMANHO_TOTAL ] );
    BUFFER[ TAMANHO_TOTAL++ ] = '_';
    BUFFER[ TAMANHO_TOTAL ] = '\0';

    printf("Digite o email da pessoa: ");
    scanf(" %58s", &BUFFER[ TAMANHO_TOTAL ]);
    TAMANHO_TOTAL += strlen( &BUFFER[ TAMANHO_TOTAL ] );
    BUFFER[ TAMANHO_TOTAL++ ] = '/';
    BUFFER[ TAMANHO_TOTAL ] = '\0';
    NPESSOAS++;

    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 1 );
    return;

}

void ListarNomes() {
    if ( NPESSOAS == 0 ) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }
    for ( CONTADOR = RESERVADO ; BUFFER[ CONTADOR ] != '\0' ; CONTADOR++ ) {
        if ( BUFFER[ CONTADOR ] == '/'  ) {
            printf("\n");
            continue;
        }
        printf("%c", BUFFER[ CONTADOR ] );
    }
    printf("\n\n");
    return;
}

void RemoverPessoa(){
    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 30 + 1 );
    if( pBuffer == NULL ){
        printf("Não foi possível alocar mais memória!\n");
        return;
    }
    printf("Digite o nome da pessoa que será removida: ");
    char *nomeProcurado = &BUFFER[ TAMANHO_TOTAL ];
    scanf(" %30[^\n]", nomeProcurado);

    for ( CONTADOR = RESERVADO ; CONTADOR < TAMANHO_TOTAL ; CONTADOR++ ) {
        if ( strncmp( nomeProcurado, &BUFFER[ CONTADOR ], strlen( nomeProcurado ) ) == 0) {
            if ( ( CONTADOR != RESERVADO && BUFFER[ CONTADOR - 1 ] != '/' ) || ( BUFFER[ CONTADOR + strlen( nomeProcurado )  ] != '_' ) ) {
                continue;
            }
            TAMANHO_REMOVER = strcspn( &BUFFER[ CONTADOR ], "/" ) + 1;
            memmove( &BUFFER[ CONTADOR ], &BUFFER[ CONTADOR + TAMANHO_REMOVER ], TAMANHO_TOTAL - ( CONTADOR + TAMANHO_REMOVER ) );
            TAMANHO_TOTAL -= TAMANHO_REMOVER;
            NPESSOAS--;
            pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 1);
            BUFFER[ TAMANHO_TOTAL ] = '\0';
            printf("Pessoa removida com sucesso!\n");
            return;
        }
    }
    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 1);
    BUFFER[ TAMANHO_TOTAL ] = '\0';
    printf("Pessoa não encontrada!\n");
    return;
}

void ProcurarPessoa(){
    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 30 + 1 );
    if(pBuffer == NULL){
        printf("Não foi possível alocar mais memória!\n");
        return;
    }
    printf("Digite o nome da pessoa que será procurada: ");
    char *nomeProcurado = &BUFFER[ TAMANHO_TOTAL ];
    scanf(" %30[^\n]", nomeProcurado);

    for ( CONTADOR = RESERVADO ; CONTADOR < TAMANHO_TOTAL ; CONTADOR++ ) {
        if ( strncmp( nomeProcurado, &BUFFER[ CONTADOR ], strlen( nomeProcurado ) ) == 0) {
            if ( ( CONTADOR != RESERVADO && BUFFER[ CONTADOR - 1 ] != '/' ) || ( BUFFER[ CONTADOR + strlen( nomeProcurado )  ] != '_' ) ) {
                continue;
            }
            printf("Informações da pessoa: \n");
            while ( BUFFER[ CONTADOR ] != '/' ) {
                printf("%c", BUFFER[ CONTADOR ] );
                CONTADOR++;
            }
            printf("\n\n");
            pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 1);
            BUFFER[ TAMANHO_TOTAL ] = '\0';
            return;
        }
    }
    pBuffer = realloc( pBuffer, TAMANHO_TOTAL + 1);
    BUFFER[ TAMANHO_TOTAL ] = '\0';
    printf("Pessoa não encontrada!\n");
    return;
}

int main(){
    pBuffer = malloc( RESERVADO );

    if( pBuffer == NULL ){
        printf("Não foi possível alocar mais memória!\n");
        return 1;
    }

    OPCAO = 0;
    TAMANHO_TOTAL = RESERVADO;
    NPESSOAS = 0;

    while(OPCAO != 5){
        printf("Escolha uma opção:\n1 - Adicionar Pessoa\n2 - Remover Pessoa\n3 - Listar Pessoas\n4 - Procurar Pessoa\n5 - Sair\n");
        scanf( "%d", &OPCAO );
        switch( OPCAO ){
            case 1:
                AdicionarPessoa();
                break;
            case 2:
                RemoverPessoa();
                break;
            case 3:
                ListarNomes();
                break;
            case 4:
                ProcurarPessoa();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Esta opção não está disponível. Escolha outra!\n");
                break;
        }
    }
    free( pBuffer );
    return 0;
}
