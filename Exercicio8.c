#include <stdio.h>
#include <stdlib.h>


typedef struct Jogador {
    int pontuacao;
    struct Jogador* proximo;
} Jogador;


Jogador* criarJogador(int pontuacao) {
    Jogador* novo = (Jogador*) malloc(sizeof(Jogador));
    novo->pontuacao = pontuacao;
    novo->proximo = NULL;
    return novo;
}


void inserirPontuacao(Jogador** lista, int pontuacao) {
    Jogador* novo = criarJogador(pontuacao);

    if (*lista == NULL || (*lista)->pontuacao > pontuacao) {  
        novo->proximo = *lista;
        *lista = novo;
    } else {
        Jogador* atual = *lista;

        
        while (atual->proximo != NULL && atual->proximo->pontuacao < pontuacao) {
            atual = atual->proximo;
        }

        
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    printf("Pontuação %d inserida.\n", pontuacao);
}


void removerPontuacao(Jogador** lista, int pontuacao) {
    if (*lista == NULL) {
        printf("Nenhuma pontuação para remover.\n");
        return;
    }

    Jogador* atual = *lista;
    Jogador* anterior = NULL;

   
    while (atual != NULL && atual->pontuacao != pontuacao) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Jogador com pontuação %d não encontrado.\n", pontuacao);
        return;
    }

   
    if (anterior == NULL) {
        *lista = atual->proximo;  
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Jogador com pontuação %d removido.\n", pontuacao);
    free(atual);
}


void exibirPontuacoes(Jogador* lista) {
    if (lista == NULL) {
        printf("Nenhuma pontuação registrada.\n");
        return;
    }

    Jogador* atual = lista;
    printf("Pontuações dos jogadores (do menor para o maior):\n");

    while (atual != NULL) {
        printf("Pontuação: %d\n", atual->pontuacao);
        atual = atual->proximo;
    }
}

int problema8() {
    Jogador* lista = NULL;
    int opcao, pontuacao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir nova pontuação\n");
        printf("2. Exibir pontuações\n");
        printf("3. Remover pontuação de jogador desqualificado\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a pontuação do jogador: ");
                scanf("%d", &pontuacao);
                inserirPontuacao(&lista, pontuacao);
                break;
            case 2:
                exibirPontuacoes(lista);
                break;
            case 3:
                printf("Digite a pontuação do jogador a ser removido: ");
                scanf("%d", &pontuacao);
                removerPontuacao(&lista, pontuacao);
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