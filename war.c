#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {

    // Vetor para armazenar 5 territórios
    struct Territorio territorios[5];

    printf("=====================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL\n");
    printf("=====================================\n\n");

    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");

    // Cadastro dos territórios
    for (int i = 0; i < 5; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        fgets(territorios[i].nome, 30, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(territorios[i].cor, 10, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o ENTER do buffer

        printf("\n");
    }

    printf("Cadastro inicial concluido com sucesso!\n\n");

    printf("=====================================\n");
    printf("     MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=====================================\n\n");

    // Exibição dos territórios
    for (int i = 0; i < 5; i++) {
        printf("TERRITORIO %d:\n", i + 1);
        printf(" - Nome: %s\n", territorios[i].nome);
        printf(" - Dominado por: Exercito %s\n", territorios[i].cor);
        printf(" - Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}