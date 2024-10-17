#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    char nome[50];
    struct Aluno* proximo;
} Aluno;

Aluno* head = NULL;

void adicionarAluno(int matricula, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->matricula = matricula;
    strncpy(novoAluno->nome, nome, sizeof(novoAluno->nome));
    novoAluno->proximo = NULL;

    if (head == NULL) {
        head = novoAluno;
    } else {
        Aluno* atual = head;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoAluno;
    }
    printf("Aluno adicionado: %s (Matrícula: %d)\n", nome, matricula);
}

void exibirAlunos() {
    if (head == NULL) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("Alunos cadastrados:\n");
    Aluno* atual = head;
    while (atual != NULL) {
        printf("Matrícula: %d, Nome: %s\n", atual->matricula, atual->nome);
        atual = atual->proximo;
    }
}

void buscarAluno(int matricula) {
    Aluno* atual = head;
    while (atual != NULL) {
        if (atual->matricula == matricula) {
            printf("Aluno encontrado: %s (Matrícula: %d)\n", atual->nome, matricula);
            return;
        }
        atual = atual->proximo;
    }
    printf("Aluno com matrícula %d não encontrado.\n", matricula);
}

void liberarLista() {
    Aluno* atual = head;
    while (atual != NULL) {
        Aluno* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head = NULL;
}

int main() {
    int opcao;
    int matricula;
    char nome[50];

    do {
        printf("\n1. Adicionar aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Buscar aluno por matrícula\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &matricula);
                getchar();
                printf("Digite o nome do aluno: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;
                adicionarAluno(matricula, nome);
                break;

            case 2:
                exibirAlunos();
                break;

            case 3:
                printf("Digite a matrícula para buscar: ");
                scanf("%d", &matricula);
                buscarAluno(matricula);
                break;

            case 4:
                printf("Saindo...\n");
                liberarLista();
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}