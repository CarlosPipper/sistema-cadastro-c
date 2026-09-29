#include <stdio.h>
#include <string.h>

#define MAX 50

struct Pessoa {
    char nome[100];
    int idade;
    char email[100];
};

int main() {
    struct Pessoa pessoas[MAX];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE CADASTRO ===\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar pessoas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1:
                if (quantidade >= MAX) {
                    printf("Limite de cadastros atingido.\n");
                    break;
                }

                printf("\nNome: ");
                fgets(pessoas[quantidade].nome, 100, stdin);
                pessoas[quantidade].nome[
                    strcspn(pessoas[quantidade].nome, "\n")
                ] = '\0';

                printf("Idade: ");
                scanf("%d", &pessoas[quantidade].idade);
                getchar();

                printf("E-mail: ");
                fgets(pessoas[quantidade].email, 100, stdin);
                pessoas[quantidade].email[
                    strcspn(pessoas[quantidade].email, "\n")
                ] = '\0';

                quantidade++;

                printf("Pessoa cadastrada com sucesso!\n");
                break;

            case 2:
                if (quantidade == 0) {
                    printf("Nenhuma pessoa cadastrada.\n");
                    break;
                }

                printf("\n=== PESSOAS CADASTRADAS ===\n");

                for (int i = 0; i < quantidade; i++) {
                    printf("\nPessoa %d\n", i + 1);
                    printf("Nome: %s\n", pessoas[i].nome);
                    printf("Idade: %d\n", pessoas[i].idade);
                    printf("E-mail: %s\n", pessoas[i].email);
                }

                break;

            case 3:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
