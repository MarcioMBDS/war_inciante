#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para listar territórios
void listar(Territorio *mapa, int n) {
    printf("\n=====================================\n");
    printf("     MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=====================================\n\n");

    for (int i = 0; i < n; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função de ataque
void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- BATALHA ---\n");
    printf("Atacante (%s) tirou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) tirou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Resultado: ATACANTE VENCEU!\n");

        strcpy(defensor->cor, atacante->cor);

        int tropasTransferidas = atacante->tropas / 2;
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;

    } else {
        printf("Resultado: DEFENSOR VENCEU!\n");

        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }
}

// Liberação de memória
void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

int main() {
    int n;

    srand(time(NULL));

    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    // Alocação dinâmica
    Territorio *territorios = (Territorio*) calloc(n, sizeof(Territorio));

    printf("\n=====================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL\n");
    printf("=====================================\n\n");

    // Cadastro
    for (int i = 0; i < n; i++) {
        printf("--- Cadastrando Territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        fgets(territorios[i].nome, 30, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exercito: ");
        fgets(territorios[i].cor, 10, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar();

        printf("\n");
    }

    printf("Cadastro concluido!\n");

    // Loop de ataque
    int a, d;
    char continuar;

    do {
        listar(territorios, n);

        printf("\nEscolha o indice do atacante: ");
        scanf("%d", &a);

        printf("Escolha o indice do defensor: ");
        scanf("%d", &d);

        if (a < 0 || a >= n || d < 0 || d >= n) {
            printf("Indice invalido!\n");
        }
        else if (a == d) {
            printf("Nao pode atacar o mesmo territorio!\n");
        }
        else if (strcmp(territorios[a].cor, territorios[d].cor) == 0) {
            printf("Nao pode atacar territorio da mesma cor!\n");
        }
        else {
            atacar(&territorios[a], &territorios[d]);
        }

        printf("\nDeseja continuar atacando? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    listar(territorios, n);

    liberarMemoria(territorios);

    return 0;
}