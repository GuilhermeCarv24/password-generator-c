#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static const char caracteres[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789"
"!@#$%^&*()-_=+[]{};:,.<>?";

static const int totalcaracteres = sizeof(caracteres) - 1;

void gerarsenha(char senha[], int tamanho);
void salvarsenha(const char nome[], const char senha[]);
void mostrarsenhas();

int main() {

    int opcao;
    int tamanho;

    char senha[100];
    char nome[50];

    srand((unsigned int)time(NULL));

    do {

        printf("\n=====================================\n");
        printf("         GERADOR DE SENHAS\n");
        printf("=====================================\n");
        printf("1 - Gerar senha\n");
        printf("2 - Mostrar senhas salvas\n");
        printf("3 - Sair\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");

        if(scanf("%d", &opcao) != 1) {

            printf("\nEntrada invalida.\n");

            while(getchar() != '\n');

            continue;
        }

        switch(opcao) {

            case 1:

                printf("\nDigite o nome da conta/site: ");
                scanf("%49s", nome);

                printf("Digite o tamanho da senha: ");

                if(scanf("%d", &tamanho) != 1) {

                    printf("\nTamanho invalido.\n");

                    while(getchar() != '\n');

                    break;
                }

                if(tamanho < 1 || tamanho >= (int)sizeof(senha)) {

                    printf("\nTamanho invalido. Use entre 1 e %zu.\n",
                           sizeof(senha) - 1);

                    break;
                }

                gerarsenha(senha, tamanho);

                printf("\nSenha gerada: %s\n", senha);

                salvarsenha(nome, senha);

                printf("Senha salva com sucesso.\n");

                break;

            case 2:

                mostrarsenhas();

                break;

            case 3:

                printf("\nEncerrando programa...\n");

                break;

            default:

                printf("\nOpcao invalida.\n");

                break;
        }

    } while(opcao != 3);

    return 0;
}

void gerarsenha(char senha[], int tamanho) {

    for(int i = 0; i < tamanho; i++) {

        int indice = rand() % totalcaracteres;

        senha[i] = caracteres[indice];
    }

    senha[tamanho] = '\0';
}

void salvarsenha(const char nome[], const char senha[]) {

    FILE *arquivo = fopen("senhas.txt", "a");

    if(arquivo == NULL) {

        printf("\nErro ao abrir arquivo.\n");

        return;
    }

    fprintf(arquivo, "Conta: %s | Senha: %s\n", nome, senha);

    fclose(arquivo);
}

void mostrarsenhas() {

    FILE *arquivo = fopen("senhas.txt", "r");

    char linha[256];

    if(arquivo == NULL) {

        printf("\nNenhuma senha salva ainda.\n");

        return;
    }

    printf("\n========== SENHAS SALVAS ==========\n");

    while(fgets(linha, sizeof(linha), arquivo) != NULL) {

        printf("%s", linha);
    }

    fclose(arquivo);
}