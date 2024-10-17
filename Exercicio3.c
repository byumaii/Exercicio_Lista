#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct {
    char matriculas[MAX_ALUNOS][20];
    int count;
} Sistema;

void cadastrar_aluno(Sistema *sistema, const char *numero_matricula) {
    for (int i = 0; i < sistema->count; i++) {
        if (strcmp(sistema->matriculas[i], numero_matricula) == 0) {
            printf("Aluno com matrícula %s já está cadastrado.\n", numero_matricula);
            return;
        }
    }
    
    if (sistema->count < MAX_ALUNOS) {
        strcpy(sistema->matriculas[sistema->count], numero_matricula);
        sistema->count++;
        printf("Aluno com matrícula %s cadastrado com sucesso!\n", numero_matricula);
    } else {
        printf("Limite de alunos atingido. Não é possível cadastrar mais alunos.\n");
    }
}

void exibir_alunos(Sistema *sistema) {
    if (sistema->count > 0) {
        printf("Lista de alunos cadastrados:\n");
        for (int i = 0; i < sistema->count; i++) {
            printf("%s\n", sistema->matriculas[i]);
        }
    } else {
        printf("Nenhum aluno cadastrado.\n");
    }
}

void buscar_aluno(Sistema *sistema, const char *numero_matricula) {
    for (int i = 0; i < sistema->count; i++) {
        if (strcmp(sistema->matriculas[i], numero_matricula) == 0) {
            printf("Aluno com matrícula %s encontrado.\n", numero_matricula);
            return;
        }
    }
    printf("Aluno com matrícula %s não encontrado.\n", numero_matricula);
}

void menu(Sistema *sistema) {
    int opcao;
    char matricula[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Buscar aluno\n");
        printf("4. Sair\n");
        
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite o número da matrícula do aluno: ");
                fgets(matricula, sizeof(matricula), stdin);
                matricula[strcspn(matricula, "\n")] = 0;
                cadastrar_aluno(sistema, matricula);
                break;
            case 2:
                exibir_alunos(sistema);
                break;
            case 3:
                printf("Digite o número da matrícula a ser buscada: ");
                fgets(matricula, sizeof(matricula), stdin);
                matricula[strcspn(matricula, "\n")] = 0;
                buscar_aluno(sistema, matricula);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int main() {
    Sistema sistema;
    sistema.count = 0;

    menu(&sistema);

    return 0;
}