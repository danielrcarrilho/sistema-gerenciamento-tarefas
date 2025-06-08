#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAM_CAMPOS 50

#define TITULO 0
#define DESCRICAO 1
#define PRIORIDADE 2
#define STATUS 3

void cadastrarTarefa(char tarefas[][4][TAM_CAMPOS], int *quantidade);
void listarTarefas(char tarefas[][4][TAM_CAMPOS], int quantidade);

int main() {
    char tarefas[MAX_TAREFAS][4][TAM_CAMPOS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Gerenciamento de Tarefas ===\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Editar Tarefa\n");
        printf("4. Excluir Tarefa\n");
        printf("5. Salvar Tarefas em Arquivo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &quantidade);
                break;
            case 2:
                listarTarefas(tarefas, quantidade);
                break;
            case 3:
                // editarTarefa();
                break;
            case 4:
                // excluirTarefa();
                break;
            case 5:
                // salvarTarefasEmArquivo();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}

void cadastrarTarefa(char tarefas[][4][TAM_CAMPOS], int *quantidade) {
    printf("Titulo: ");
    fgets(tarefas[*quantidade][TITULO], TAM_CAMPOS, stdin);
    tarefas[*quantidade][TITULO][strcspn(tarefas[*quantidade][TITULO], "\n")] = 0;

    printf("Descricao: ");
    fgets(tarefas[*quantidade][DESCRICAO], TAM_CAMPOS, stdin);
    tarefas[*quantidade][DESCRICAO][strcspn(tarefas[*quantidade][DESCRICAO], "\n")] = 0;

    printf("Prioridade: ");
    fgets(tarefas[*quantidade][PRIORIDADE], TAM_CAMPOS, stdin);
    tarefas[*quantidade][PRIORIDADE][strcspn(tarefas[*quantidade][PRIORIDADE], "\n")] = 0;

    printf("Status: ");
    fgets(tarefas[*quantidade][STATUS], TAM_CAMPOS, stdin);
    tarefas[*quantidade][STATUS][strcspn(tarefas[*quantidade][STATUS], "\n")] = 0;

    (*quantidade)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

void listarTarefas(char tarefas[][4][TAM_CAMPOS], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nTarefa %d:\n", i);
        printf("Titulo: %s\n", tarefas[i][TITULO]);
        printf("Descricao: %s\n", tarefas[i][DESCRICAO]);
        printf("Prioridade: %s\n", tarefas[i][PRIORIDADE]);
        printf("Status: %s\n", tarefas[i][STATUS]);
    }
}