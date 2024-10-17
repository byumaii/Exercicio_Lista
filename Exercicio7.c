#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Visitante {
    char nome[100];
    struct Visitante* proximo;
} Visitante;


Visitante* criarVisitante(char nome[]) {
    Visitante* novo = (Visitante*) malloc(sizeof(Visitante));
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    return novo;
}


void adicionarVisitante(Visitante** inicio, Visitante** fim, char nome[]) {
    Visitante* novo = criarVisitante(nome);

    if (*fim == NULL) {  
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->proximo = novo;
        *fim = novo;
    }

    printf("Visitante %s adicionado à fila de espera.\n", nome);
}


void removerVisitante(Visitante** inicio, Visitante** fim) {
    if (*inicio == NULL) {
        printf("Nenhum visitante na fila de espera.\n");
        return;
    }

    Visitante* temp = *inicio;
    printf("Visitante %s usou o brinquedo e foi removido da fila.\n", temp->nome);

    *inicio = (*inicio)->proximo;
    if (*inicio == NULL) {  
        *fim = NULL;
    }

    free(temp);
}


void exibirFila(Visitante* inicio) {
    if (inicio == NULL) {
        printf("Nenhum visitante aguardando na fila.\n");
        return;
    }

    Visitante* atual = inicio;
    printf("Visitantes aguardando na fila:\n");

    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

int main() {
    Visitante* inicio = NULL;
    Visitante* fim = NULL;
    int opcao;
    char nome[100];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar visitante à fila\n");
        printf("2. Remover visitante que usou o brinquedo\n");
        printf("3. Exibir fila de espera\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  

        switch (opcao) {
            case 1:
                printf("Digite o nome do visitante: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';  
                adicionarVisitante(&inicio, &fim, nome);
                break;
            case 2:
                removerVisitante(&inicio, &fim);
                break;
            case 3:
                exibirFila(inicio);
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