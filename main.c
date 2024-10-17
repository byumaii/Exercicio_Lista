#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Encomenda {
    char destinatario[100];
    float distancia;
    struct Encomenda* prox;
} Encomenda;

Encomenda* inserirEncomenda(Encomenda* lista, char destinatario[], float distancia) {
    Encomenda* nova = (Encomenda*) malloc(sizeof(Encomenda));
    strcpy(nova->destinatario, destinatario);
    nova->distancia = distancia;
    nova->prox = NULL;

    if (lista == NULL || lista->distancia > distancia) {
        nova->prox = lista;
        return nova;
    }

    Encomenda* atual = lista;
    while (atual->prox != NULL && atual->prox->distancia < distancia) {
        atual = atual->prox;
    }

    nova->prox = atual->prox;
    atual->prox = nova;

    return lista;
}

void exibirEncomendas(Encomenda* lista) {
    if (lista == NULL) {
        printf("Nenhuma encomenda para exibir.\n");
        return;
    }

    Encomenda* atual = lista;
    while (atual != NULL) {
        printf("Destinatário: %s, Distância: %.2f km\n", atual->destinatario, atual->distancia);
        atual = atual->prox;
    }
}

Encomenda* removerPrimeiraEncomenda(Encomenda* lista) {
    if (lista == NULL) {
        printf("Nenhuma encomenda a ser removida.\n");
        return NULL;
    }

    Encomenda* encomendaRemovida = lista;
    lista = lista->prox;
    printf("Encomenda de %s removida.\n", encomendaRemovida->destinatario);
    free(encomendaRemovida);

    return lista;
}

int main() {
    Encomenda* lista = NULL;
    int opcao;
    char destinatario[100];
    float distancia;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir nova encomenda\n");
        printf("2. Exibir todas as encomendas\n");
        printf("3. Remover a encomenda mais próxima\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Nome do destinatário: ");
                fgets(destinatario, 100, stdin);
                destinatario[strcspn(destinatario, "\n")] = '\0';
                printf("Distância para o destinatário (em km): ");
                scanf("%f", &distancia);
                lista = inserirEncomenda(lista, destinatario, distancia);
                printf("Encomenda inserida com sucesso.\n");
                break;

            case 2:
                printf("\nLista de encomendas:\n");
                exibirEncomendas(lista);
                break;

            case 3:
                lista = removerPrimeiraEncomenda(lista);
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
