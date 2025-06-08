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
void editarTarefa(char tarefas[][4][TAM_CAMPOS], int indice);
void excluirTarefa(char tarefas[][4][TAM_CAMPOS], int *quantidade, int indice);
void salvarTarefasEmArquivo(char tarefas[][4][TAM_CAMPOS], int quantidade);

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
            case 3: {
                int i;
                printf("Digite o índice da tarefa a editar: ");
                scanf("%d", &i);
                getchar();
                if (i >= 0 && i < quantidade)
                    editarTarefa(tarefas, i);
                else
                    printf("Índice inválido.\n");
                break;
            }
            case 4: {
                int i;
                printf("Digite o índice da tarefa a excluir: ");
                scanf("%d", &i);
                getchar();
                if (i >= 0 && i < quantidade)
                    excluirTarefa(tarefas, &quantidade, i);
                else
                    printf("Índice inválido.\n");
                break;
            }
            case 5:
                salvarTarefasEmArquivo(tarefas, quantidade);
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
void editarTarefa(char tarefas[][4][TAM_CAMPOS], int indice) {
    printf("Novo titulo: ");
    fgets(tarefas[indice][TITULO], TAM_CAMPOS, stdin);
    tarefas[indice][TITULO][strcspn(tarefas[indice][TITULO], "\n")] = 0;

    printf("Nova descricao: ");
    fgets(tarefas[indice][DESCRICAO], TAM_CAMPOS, stdin);
    tarefas[indice][DESCRICAO][strcspn(tarefas[indice][DESCRICAO], "\n")] = 0;

    printf("Nova prioridade: ");
    fgets(tarefas[indice][PRIORIDADE], TAM_CAMPOS, stdin);
    tarefas[indice][PRIORIDADE][strcspn(tarefas[indice][PRIORIDADE], "\n")] = 0;

    printf("Novo status: ");
    fgets(tarefas[indice][STATUS], TAM_CAMPOS, stdin);
    tarefas[indice][STATUS][strcspn(tarefas[indice][STATUS], "\n")] = 0;

    printf("Tarefa editada com sucesso!\n");
}

void excluirTarefa(char tarefas[][4][TAM_CAMPOS], int *quantidade, int indice) {
    for (int i = indice; i < *quantidade - 1; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(tarefas[i][j], tarefas[i + 1][j]);
        }
    }
    (*quantidade)--;
    printf("Tarefa excluída com sucesso!\n");
}

void salvarTarefasEmArquivo(char tarefas[][4][TAM_CAMPOS], int quantidade) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (!arquivo) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Tarefa %d:\nTitulo: %s\nDescricao: %s\nPrioridade: %s\nStatus: %s\n\n",
                i + 1,
                tarefas[i][TITULO],
                tarefas[i][DESCRICAO],
                tarefas[i][PRIORIDADE],
                tarefas[i][STATUS]);
    }

    fclose(arquivo);
    printf("Tarefas salvas no arquivo 'tarefas.txt'.\n");
}