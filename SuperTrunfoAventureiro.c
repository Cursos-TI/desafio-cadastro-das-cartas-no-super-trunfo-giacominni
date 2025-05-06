#include <stdio.h>
#include <string.h>

// Estrutura para armazenar uma carta
struct Carta {
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para comparar cartas
void compararCartas(struct Carta carta1, struct Carta carta2, int opcao) {
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    printf("\nComparando cartas:\n");
    printf("Cidade 1: %s\n", carta1.nomeCidade);
    printf("Cidade 2: %s\n", carta2.nomeCidade);

    switch (opcao) {
        case 1:
            printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            printf("Área: %.2f km² vs %.2f km²\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            printf("PIB: %.2f bilhões vs %.2f bilhões\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4:
            printf("Pontos Turísticos: %d vs %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5:
            printf("Densidade Demográfica: %.2f hab/km² vs %.2f hab/km²\n", densidade1, densidade2);
            if (densidade1 < densidade2) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (densidade2 < densidade1) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}

int main() {
    // Cartas previamente cadastradas
    struct Carta carta1 = {"São Paulo", 12325000, 1521.11, 699.28, 50};
    struct Carta carta2 = {"Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    int opcao;

    // Menu
    printf("SUPER TRUNFO - COMPARADOR DE CIDADES\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões de reais)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Chama função de comparação
    compararCartas(carta1, carta2, opcao);

    return 0;
}
