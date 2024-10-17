#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Paciente {
    char nome[100];
    struct Paciente* proximo;
} Paciente;


Paciente* criarPaciente(char nome[]) {
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    return novo;
}


void adicionarPaciente(Paciente** fila, char nome[]) {
    Paciente* novo = criarPaciente(nome);

    if (*fila == NULL) { 
        *fila = novo;
    } else {
        Paciente* atual = *fila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    printf("Paciente %s adicionado à fila.\n", nome);
}


void removerPaciente(Paciente** fila) {
    if (*fila == NULL) {
        printf("Nenhum paciente na fila.\n");
        return;
    }

    Paciente* removido = *fila;
    *fila = (*fila)->proximo;

    printf("Paciente %s foi atendido e removido da fila.\n", removido->nome);
    free(removido);
}


void exibirPacientes(Paciente* fila) {
    if (fila == NULL) {
        printf("Nenhum paciente na fila.\n");
        return;
    }

    Paciente* atual = fila;
    printf("Pacientes aguardando atendimento:\n");
    while (atual != NULL) {
        printf("Paciente: %s\n", atual->nome);
        atual = atual->proximo;
    }
}

int problema5() {
    Paciente* fila = NULL;
    int opcao;
    char nome[100];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar paciente à fila\n");
        printf("2. Remover paciente atendido\n");
        printf("3. Exibir fila de pacientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                adicionarPaciente(&fila, nome);
                break;
            case 2:
                removerPaciente(&fila);
                break;
            case 3:
                exibirPacientes(fila);
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