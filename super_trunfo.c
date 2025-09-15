/*
  super_trunfo.c
  Versão aprimorada: Comparações Avançadas com Atributos Múltiplos em C
  Permite escolher cartas, atributos e jogar múltiplas rodadas.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;    // milhões
    int area;         // milhares de km²
    int pib;          // bilhões USD
    int densidade;    // hab/km² (menor é melhor)
} Carta;

/* Retorna nome do atributo */
const char* nomeAtributo(int cod) {
    switch (cod) {
        case 1: return "Populacao (milhoes)";
        case 2: return "Area (mil km2)";
        case 3: return "PIB (bilhoes USD)";
        case 4: return "Densidade Demografica (hab/km2)";
        default: return "??";
    }
}

/* Exibe menu com possibilidade de bloquear uma opção */
void exibirMenu(int bloqueado) {
    printf("\nEscolha um atributo:\n");
    if (bloqueado != 1) printf("  1 - Populacao\n");
    if (bloqueado != 2) printf("  2 - Area\n");
    if (bloqueado != 3) printf("  3 - PIB\n");
    if (bloqueado != 4) printf("  4 - Densidade Demografica\n");
    printf("Digite a opcao: ");
}

/* Retorna o valor do atributo */
int valorAtributo(int atr, Carta c) {
    switch (atr) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

/* Compara atributo: maior vence, exceto densidade (menor vence) */
int compararAtributo(int atr, Carta c1, Carta c2) {
    int v1 = valorAtributo(atr, c1);
    int v2 = valorAtributo(atr, c2);
    if (atr == 4) {
        if (v1 < v2) return 1;
        if (v2 < v1) return 2;
        return 0;
    } else {
        if (v1 > v2) return 1;
        if (v2 > v1) return 2;
        return 0;
    }
}

/* Leitura segura de inteiro */
int lerInteiro() {
    int x;
    while (scanf("%d", &x) != 1) {
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        printf("Entrada invalida. Digite um numero inteiro: ");
    }
    return x;
}

/* Exibe as cartas disponíveis */
void mostrarCartas(Carta cartas[], int n) {
    printf("\nCartas disponíveis:\n");
    for (int i = 0; i < n; i++) {
        printf("  %d - %s\n", i+1, cartas[i].nome);
    }
    printf("Escolha uma carta pelo número: ");
}

int main() {
    Carta cartas[4] = {
        {"Brasil",    214, 8516, 2200, 25},
        {"Argentina", 45,  2780, 500,  16},
        {"Japao",     125, 378,  5000, 347},
        {"Canada",    38,  9985, 2000, 4}
    };
    int nCartas = 4;

    printf("=== SUPER TRUNFO - Comparacao Avancada ===\n");

    int jogar = 1;
    while (jogar) {
        int idx1 = -1, idx2 = -1;

        // Escolha da primeira carta
        while (1) {
            mostrarCartas(cartas, nCartas);
            idx1 = lerInteiro() - 1;
            if (idx1 >= 0 && idx1 < nCartas) break;
            printf("Opcao invalida. Tente novamente.\n");
        }

        // Escolha da segunda carta
        while (1) {
            mostrarCartas(cartas, nCartas);
            idx2 = lerInteiro() - 1;
            if (idx2 >= 0 && idx2 < nCartas && idx2 != idx1) break;
            printf("Opcao invalida ou carta ja escolhida. Tente novamente.\n");
        }

        Carta c1 = cartas[idx1];
        Carta c2 = cartas[idx2];

        printf("\nCartas escolhidas:\n  1) %s\n  2) %s\n", c1.nome, c2.nome);

        // Escolha de atributos
        int atr1 = 0, atr2 = 0;
        while (1) {
            exibirMenu(-1);
            atr1 = lerInteiro();
            switch (atr1) {
                case 1: case 2: case 3: case 4: break;
                default: printf("Opcao invalida. Tente novamente.\n"); continue;
            }
            break;
        }
        while (1) {
            exibirMenu(atr1);
            atr2 = lerInteiro();
            if (atr2 == atr1) { printf("Voce ja escolheu esse atributo.\n"); continue; }
            switch (atr2) {
                case 1: case 2: case 3: case 4: break;
                default: printf("Opcao invalida. Tente novamente.\n"); continue;
            }
            break;
        }

        // Comparações
        int res1 = compararAtributo(atr1, c1, c2);
        int res2 = compararAtributo(atr2, c1, c2);

        int v1_atr1 = valorAtributo(atr1, c1);
        int v1_atr2 = valorAtributo(atr2, c1);
        int v2_atr1 = valorAtributo(atr1, c2);
        int v2_atr2 = valorAtributo(atr2, c2);

        int soma1 = v1_atr1 + v1_atr2;
        int soma2 = v2_atr1 + v2_atr2;

        // Exibição dos resultados
        printf("\n=== RESULTADO DA RODADA ===\n");
        printf("%-15s | %-25s | %-25s\n", "Pais", nomeAtributo(atr1), nomeAtributo(atr2));
        printf("------------------------------------------------------------\n");
        printf("%-15s | %-25d | %-25d\n", c1.nome, v1_atr1, v1_atr2);
        printf("%-15s | %-25d | %-25d\n", c2.nome, v2_atr1, v2_atr2);
        printf("------------------------------------------------------------\n");
        printf("%-15s | Soma dos atributos = %d\n", c1.nome, soma1);
        printf("%-15s | Soma dos atributos = %d\n", c2.nome, soma2);

        if (soma1 > soma2) printf("\nVencedor da rodada: %s\n", c1.nome);
        else if (soma2 > soma1) printf("\nVencedor da rodada: %s\n", c2.nome);
        else printf("\nEmpate!\n");

        printf("\nResultado por atributo:\n");
        printf("  %s: %s\n", nomeAtributo(atr1),
               (res1 == 1) ? c1.nome : (res1 == 2) ? c2.nome : "Empate");
        printf("  %s: %s\n", nomeAtributo(atr2),
               (res2 == 1) ? c1.nome : (res2 == 2) ? c2.nome : "Empate");

        // Pergunta se quer jogar novamente
        int opcao;
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        opcao = lerInteiro();
        jogar = (opcao == 1) ? 1 : 0;
        printf("\n------------------------------------------\n");
    }

    printf("Obrigado por jogar Super Trunfo!\n");
    return 0;
}
