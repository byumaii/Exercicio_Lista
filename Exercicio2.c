#include <stdio.h>
#include <stdlib.h>


typedef struct Compromisso {
    int hora; 
    struct Compromisso* proximo;
} Compromisso;


Compromisso* criarCompromisso(int hora) {
    Compromisso* novo = (Compromisso*) malloc(sizeof(Compromisso));
    novo->hora = hora;
    novo->proximo = NULL;
    return novo;
}


void inserirCompromisso(Compromisso** agenda, int hora) {
    Compromisso* novo = criarCompromisso(hora);

    
    if (*agenda == NULL || (*agenda)->hora > hora) {
        novo->proximo = *agenda;
        *agenda = novo;
    } else {
        Compromisso* atual = *agenda;

       
        while (atual->proximo != NULL && atual->proximo->hora < hora) {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    printf("Compromisso %04d inserido.\n", hora);
}


void removerCompromisso(Compromisso** agenda, int hora) {
    if (*agenda == NULL) {
        printf("Nenhum compromisso para remover.\n");
        return;
    }

    Compromisso* atual = *agenda;
    Compromisso* anterior = NULL;

    
    while (atual != NULL && atual->hora != hora) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Compromisso %04d não encontrado.\n", hora);
        return;
    }

   
    if (anterior == NULL) {
        *agenda = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Compromisso %04d removido.\n", hora);
    free(atual);
}


void exibirCompromissos(Compromisso* agenda) {
    if (agenda == NULL) {
        printf("Nenhum compromisso na agenda.\n");
        return;
    }

    Compromisso* atual = agenda;
    printf("Compromissos na agenda:\n");

    while (atual != NULL) {
        printf("%04d\n", atual->hora); 
        atual = atual->proximo;
    }
}

int problema2() {
    Compromisso* agenda = NULL;
    int opcao, hora;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir compromisso\n");
        printf("2. Exibir compromissos\n");
        printf("3. Remover compromisso\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o horário do compromisso (HHMM): ");
                scanf("%d", &hora);
                inserirCompromisso(&agenda, hora);
                break;
            case 2:
                exibirCompromissos(agenda);
                break;
            case 3:
                printf("Digite o horário do compromisso a ser removido (HHMM): ");
                scanf("%d", &hora);
                removerCompromisso(&agenda, hora);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}