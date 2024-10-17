#include <stdio.h>
#include <stdlib.h>

typedef struct Pedido {
  int numero;
  struct Pedido *proximo;
} Pedido;

typedef struct {
  Pedido *inicio;
  Pedido *fim;
} Fila;


void inicializarFila(Fila *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}


void adicionarPedido(Fila *fila, int numero) {
  Pedido *novoPedido = (Pedido *)malloc(sizeof(Pedido));
  novoPedido->numero = numero;
  novoPedido->proximo = NULL;

  if (fila->fim == NULL) { 
    fila->inicio = novoPedido;
    fila->fim = novoPedido;
  } else {
    fila->fim->proximo = novoPedido;
    fila->fim = novoPedido;
  }

  printf("Pedido %d adicionado.\n", numero);
}


void removerPedido(Fila *fila) {
  if (fila->inicio == NULL) {
    printf("Nenhum pedido para remover.\n");
    return;
  }

  Pedido *pedidoRemovido = fila->inicio;
  fila->inicio = fila->inicio->proximo;

  if (fila->inicio == NULL) {
    fila->fim = NULL;
  }

  printf("Pedido %d atendido e removido.\n", pedidoRemovido->numero);
  free(pedidoRemovido);
}


void exibirPedidos(Fila *fila) {
  if (fila->inicio == NULL) {
    printf("Nenhum pedido na fila.\n");
    return;
  }

  Pedido *atual = fila->inicio;
  printf("Pedidos na fila: ");
  while (atual != NULL) {
    printf("%d ", atual->numero);
    atual = atual->proximo;
  }
  printf("\n");
}

int problema1() {
  Fila fila;
  inicializarFila(&fila);

  int opcao, numeroPedido;

  do {
    printf("\n--- Menu ---\n");
    printf("1. Adicionar pedido\n");
    printf("2. Exibir pedidos\n");
    printf("3. Remover pedido atendido\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o numero do pedido: ");
      scanf("%d", &numeroPedido);
      adicionarPedido(&fila, numeroPedido);
      break;
    case 2:
      exibirPedidos(&fila);
      break;
    case 3:
      removerPedido(&fila);
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