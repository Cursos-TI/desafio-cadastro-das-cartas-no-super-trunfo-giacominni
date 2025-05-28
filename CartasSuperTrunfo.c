#include <stdio.h>
#include <string.h> // Para strcspn
#include <stdlib.h> // Para atoi e atof

// Constantes para tamanhos máximos de strings
#define TAM_CODIGO 10
#define TAM_NOME 100
#define TAM_INPUT 100 // Buffer temporário para fgets

// --- Estrutura para armazenar uma carta (cidade) ---
struct Carta {
    char estado;
    char codigo[TAM_CODIGO];
    char nomeCidade[TAM_NOME];
    int populacao;
    float area; // em km²
    float pib;  // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional; // Novo campo
    float pibPerCapita;          // Novo campo
};

// --- Função para remover a nova linha lida por fgets ---
void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// --- Função para exibir os dados de uma carta ---
void exibirCarta(struct Carta c, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
}

// --- Função para comparar cartas ---
void compararCartas(struct Carta carta1, struct Carta carta2, int opcao) {
    printf("\n--- Comparando cartas ---\n");
    printf("Cidade 1: %s\n", carta1.nomeCidade);
    printf("Cidade 2: %s\n", carta2.nomeCidade);

    switch (opcao) {
        case 1: // Comparar População
            printf("Atributo: População\n");
            printf("Valor 1: %d | Valor 2: %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Comparar Área
            printf("Atributo: Área\n");
            printf("Valor 1: %.2f km² | Valor 2: %.2f km²\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // Comparar PIB
            printf("Atributo: PIB\n");
            printf("Valor 1: %.2f bilhões | Valor 2: %.2f bilhões\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Comparar Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Valor 1: %d | Valor 2: %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Comparar Densidade Populacional (Maior vence)
            printf("Atributo: Densidade Populacional\n");
            printf("Valor 1: %.2f hab/km² | Valor 2: %.2f hab/km²\n", carta1.densidadePopulacional, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional > carta2.densidadePopulacional) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.densidadePopulacional > carta1.densidadePopulacional) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;
            
        case 6: // Comparar PIB per Capita (Maior vence) - NOVO
            printf("Atributo: PIB per Capita\n");
            printf("Valor 1: %.2f reais | Valor 2: %.2f reais\n", carta1.pibPerCapita, carta2.pibPerCapita);
            if (carta1.pibPerCapita > carta2.pibPerCapita) {
                printf("Vencedora: %s\n", carta1.nomeCidade);
            } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
                printf("Vencedora: %s\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
}

// --- Função principal do programa ---
int main() {
    struct Carta carta1;
    struct Carta carta2;
    char input[TAM_INPUT]; // Buffer para leitura de entrada

    printf("Bem-vindo ao Super Trunfo de Cidades!\n\n");

    // --- CADASTRO DA CARTA 1 ---
    printf("--- Cadastro da Carta 1 ---\n");

    printf("Estado (letra de A a H): ");
    fgets(input, TAM_INPUT, stdin);
    carta1.estado = input[0];

    printf("Codigo da Carta (ex: A01): ");
    fgets(carta1.codigo, TAM_CODIGO, stdin);
    removerNovaLinha(carta1.codigo);

    printf("Nome da Cidade: ");
    fgets(carta1.nomeCidade, TAM_NOME, stdin);
    removerNovaLinha(carta1.nomeCidade);

    printf("Populacao: ");
    fgets(input, TAM_INPUT, stdin);
    carta1.populacao = atoi(input);

    printf("Area (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    carta1.area = atof(input);

    printf("PIB (em bilhoes de reais): ");
    fgets(input, TAM_INPUT, stdin);
    carta1.pib = atof(input);

    printf("Numero de Pontos Turisticos: ");
    fgets(input, TAM_INPUT, stdin);
    carta1.pontosTuristicos = atoi(input);

    // --- CÁLCULOS PARA CARTA 1 ---
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao; // O PIB ja e float, mas o populacao e int, entao o cast para float e importante se populacao for int

    printf("\n"); // Linha em branco para separacao

    // --- CADASTRO DA CARTA 2 ---
    printf("--- Cadastro da Carta 2 ---\n");

    printf("Estado (letra de A a H): ");
    fgets(input, TAM_INPUT, stdin);
    carta2.estado = input[0];

    printf("Codigo da Carta (ex: B02): ");
    fgets(carta2.codigo, TAM_CODIGO, stdin);
    removerNovaLinha(carta2.codigo);

    printf("Nome da Cidade: ");
    fgets(carta2.nomeCidade, TAM_NOME, stdin);
    removerNovaLinha(carta2.nomeCidade);

    printf("Populacao: ");
    fgets(input, TAM_INPUT, stdin);
    carta2.populacao = atoi(input);

    printf("Area (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    carta2.area = atof(input);

    printf("PIB (em bilhoes de reais): ");
    fgets(input, TAM_INPUT, stdin);
    carta2.pib = atof(input);

    printf("Numero de Pontos Turisticos: ");
    fgets(input, TAM_INPUT, stdin);
    carta2.pontosTuristicos = atoi(input);

    // --- CÁLCULOS PARA CARTA 2 ---
    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // --- EXIBIÇÃO DAS CARTAS CADASTradas ---
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("\n"); // Linha em branco para separacao

    // --- MENU DE COMPARAÇÃO ---
    int opcao;
    printf("\nSUPER TRUNFO - COMPARADOR DE CIDADES\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Area (km²)\n");
    printf("3 - PIB (bilhoes de reais)\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n"); // Nova opção
    printf("Opcao: ");
    scanf("%d", &opcao);

    // --- Chama a função de comparação ---
    compararCartas(carta1, carta2, opcao);

    return 0;
}
