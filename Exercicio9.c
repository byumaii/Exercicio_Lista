#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Produto {
    char nome[100];
    int quantidade;
    struct Produto* proximo;
} Produto;


Produto* criarProduto(char nome[], int quantidade) {
    Produto* novo = (Produto*) malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->quantidade = quantidade;
    novo->proximo = NULL;
    return novo;
}


void adicionarProduto(Produto** estoque, char nome[], int quantidade) {
    Produto* novo = criarProduto(nome, quantidade);
    novo->proximo = *estoque; 
    *estoque = novo;
    printf("Produto %s com %d unidades adicionado ao estoque.\n", nome, quantidade);
}


void removerProduto(Produto** estoque, char nome[]) {
    if (*estoque == NULL) {
        printf("Nenhum produto no estoque.\n");
        return;
    }

    Produto* atual = *estoque;
    Produto* anterior = NULL;

   
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto %s não encontrado no estoque.\n", nome);
        return;
    }

   
    if (anterior == NULL) {
        *estoque = atual->proximo;  
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Produto %s removido do estoque.\n", nome);
    free(atual);
}


void exibirEstoque(Produto* estoque) {
    if (estoque == NULL) {
        printf("Nenhum produto no estoque.\n");
        return;
    }

    Produto* atual = estoque;
    printf("Produtos disponíveis no estoque:\n");

    while (atual != NULL) {
        printf("Produto: %s, Quantidade: %d\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

int problema9() {
    Produto* estoque = NULL;
    int opcao, quantidade;
    char nome[100];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar produto ao estoque\n");
        printf("2. Remover produto do estoque\n");
        printf("3. Exibir produtos do estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Digite o nome do produto: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';  
                printf("Digite a quantidade do produto: ");
                scanf("%d", &quantidade);
                adicionarProduto(&estoque, nome, quantidade);
                break;
            case 2:
                printf("Digite o nome do produto a ser removido: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';  
                removerProduto(&estoque, nome);
                break;
            case 3:
                exibirEstoque(estoque);
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