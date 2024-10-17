#include <stdio.h>
#include <stdlib.h>


typedef struct Produto {
    float preco;
    struct Produto* proximo;
} Produto;


Produto* criarProduto(float preco) {
    Produto* novo = (Produto*) malloc(sizeof(Produto));
    novo->preco = preco;
    novo->proximo = NULL;
    return novo;
}


void inserirProduto(Produto** lista, float preco) {
    Produto* novo = criarProduto(preco);

    if (*lista == NULL || (*lista)->preco > preco) {  // 
        novo->proximo = *lista;
        *lista = novo;
    } else {
        Produto* atual = *lista;

        
        while (atual->proximo != NULL && atual->proximo->preco < preco) {
            atual = atual->proximo;
        }

       
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    printf("Produto com preço %.2f inserido.\n", preco);
}


void removerProduto(Produto** lista, float preco) {
    if (*lista == NULL) {
        printf("Nenhum produto para remover.\n");
        return;
    }

    Produto* atual = *lista;
    Produto* anterior = NULL;

   
    while (atual != NULL && atual->preco != preco) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto com preço %.2f não encontrado.\n", preco);
        return;
    }

    
    if (anterior == NULL) {
        *lista = atual->proximo;  
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Produto com preço %.2f removido.\n", preco);
    free(atual);
}


void exibirProdutos(Produto* lista) {
    if (lista == NULL) {
        printf("Nenhum produto disponível.\n");
        return;
    }

    Produto* atual = lista;
    printf("Produtos disponíveis (em ordem de preço):\n");

    while (atual != NULL) {
        printf("Preço: %.2f\n", atual->preco);
        atual = atual->proximo;
    }
}

int problema6() {
    Produto* lista = NULL;
    int opcao;
    float preco;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Remover produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o preço do produto: ");
                scanf("%f", &preco);
                inserirProduto(&lista, preco);
                break;
            case 2:
                exibirProdutos(lista);
                break;
            case 3:
                printf("Digite o preço do produto a ser removido: ");
                scanf("%f", &preco);
                removerProduto(&lista, preco);
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