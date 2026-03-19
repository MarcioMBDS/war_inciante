#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 5
#define MAX_MISSAO 100

// ---------------- STRUCT ----------------
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ---------------- FUNÇÕES ----------------

// Sorteia e atribui missão
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Exibe missão
void exibirMissao(char* missao) {
    printf("\n🎯 Sua missão é: %s\n", missao);
}

// Exibe mapa
void exibirMapa(Territorio* mapa, int tamanho) {
    printf("\n===== MAPA =====\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d - %s | Cor: %s | Tropas: %d\n",
            i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Ataque
void atacar(Territorio* atacante, Territorio* defensor) {
    if(strcmp(atacante->cor, defensor->cor) == 0) {
        printf("⚠️ Não pode atacar seu próprio território!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque! %s (%d) vs %s (%d)\n",
        atacante->nome, dadoAtacante,
        defensor->nome, dadoDefensor);

    if(dadoAtacante > dadoDefensor) {
        printf("✅ Ataque venceu!\n");

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas /= 2;
    } else {
        printf("❌ Ataque perdeu!\n");
        atacante->tropas--;
    }
}

// Verifica missão (lógica simples)
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    
    // Exemplo 1: conquistar 3 territórios da mesma cor
    int contador = 0;
    for(int i = 0; i < tamanho; i++) {
        if(strcmp(mapa[i].cor, "Azul") == 0) {
            contador++;
        }
    }
    if(contador >= 3) return 1;

    // Pode expandir com mais regras depois
    return 0;
}

// Libera memória
void liberarMemoria(Territorio* mapa, char* missao) {
    free(mapa);
    free(missao);
}

// ---------------- MAIN ----------------
int main() {

    srand(time(NULL));

    // Alocação dinâmica do mapa
    Territorio* mapa = (Territorio*) malloc(MAX_TERRITORIOS * sizeof(Territorio));

    // Missões
    char* listaMissoes[] = {
        "Conquistar 3 territorios",
        "Eliminar tropas inimigas",
        "Dominar metade do mapa",
        "Conquistar territorio especifico",
        "Sobreviver com pelo menos 5 tropas"
    };

    // Missão do jogador
    char* missaoJogador = (char*) malloc(MAX_MISSAO * sizeof(char));

    atribuirMissao(missaoJogador, listaMissoes, 5);
    exibirMissao(missaoJogador);

    // Cadastro de territórios
    for(int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor: ");
        scanf("%s", mapa[i].cor);

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    int jogoAtivo = 1;

    while(jogoAtivo) {

        exibirMapa(mapa, MAX_TERRITORIOS);

        int atk, def;

        printf("\nEscolha território atacante: ");
        scanf("%d", &atk);

        printf("Escolha território defensor: ");
        scanf("%d", &def);

        atacar(&mapa[atk], &mapa[def]);

        // Verifica missão
        if(verificarMissao(missaoJogador, mapa, MAX_TERRITORIOS)) {
            printf("\n🏆 MISSÃO CUMPRIDA! VOCÊ VENCEU!\n");
            jogoAtivo = 0;
        }
    }

    liberarMemoria(mapa, missaoJogador);

    return 0;
}