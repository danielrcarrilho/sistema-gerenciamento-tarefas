#include <stdio.h>

int main() {
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

        switch (opcao) {
            case 1:
                // cadastrarTarefa();
                break;
            case 2:
                // listarTarefas();
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