#include <stdio.h>
#include <string.h> // Para strcspn
#include <stdlib.h> // Para atoi, atof, e strtoul

// Constantes para tamanhos máximos de strings
#define TAM_CODIGO 10
#define TAM_NOME 100
#define TAM_INPUT 100 // Buffer temporário para fgets

// --- Estrutura para armazenar uma carta (cidade) ---
struct Carta {
    char estado;
    char codigo[TAM_CODIGO];
    char nomeCidade[TAM_NOME];
    unsigned long int populacao; // ALTERADO PARA unsigned long int
    float area; // em km²
    float pib;  // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder; // NOVO CAMPO
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
    printf("Populacao: %lu\n", c.populacao); // %lu para unsigned long int
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Numero de Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder); // NOVO CAMPO
}

// --- Nova função para comparar um atributo genérico e imprimir o resultado ---
// regraMenorVence: 1 se o menor valor vence, 0 se o maior valor vence
void compararAtributo(const char *nomeAtributo, float valor1, float valor2, int regraMenorVence) {
    int carta1Venceu = 0; // Default: Carta 2 vence ou é empate (0)

    if (regraMenorVence) { // Lógica para atributos onde o MENOR valor vence (ex: Densidade Populacional)
        if (valor1 < valor2) {
            carta1Venceu = 1; // Carta 1 vence
        } else if (valor2 < valor1) {
            carta1Venceu = 0; // Carta 2 vence
        } else {
            // Empate
            carta1Venceu = 0; // Conforme o exemplo de saída (0 para Carta 2 vence, o que inclui empate)
        }
    } else { // Lógica para atributos onde o MAIOR valor vence (todos os outros)
        if (valor1 > valor2) {
            carta1Venceu = 1; // Carta 1 vence
        } else if (valor2 > valor1) {
            carta1Venceu = 0; // Carta 2 vence
        } else {
            // Empate
            carta1Venceu = 0; // Conforme o exemplo de saída
        }
    }

    // Imprime o resultado formatado
    if (carta1Venceu == 1) {
        printf("%s: Carta 1 venceu (%d)\n", nomeAtributo, carta1Venceu);
    } else {
        printf("%s: Carta 2 venceu (%d)\n", nomeAtributo, carta1Venceu); // Mostrará 0 em caso de C2 vencer ou empate
    }
}


// --- Função principal do programa ---
int main() {
    struct Carta carta1;
    struct Carta carta2;
    char input[TAM_INPUT]; // Buffer para leitura de entrada

    printf("Bem-vindo ao Super Trunfo de Cidades - Nível Mestre!\n\n");

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

    printf("Populacao: "); // Indicação para o usuário
    fgets(input, TAM_INPUT, stdin);
    carta1.populacao = strtoul(input, NULL, 10); // Uso de strtoul

    printf("Area (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    carta1.area = atof(input);

    printf("PIB (em bilhoes de reais): ");
    fgets(input, TAM_INPUT, stdin);
    carta1.pib = atof(input);

    printf("Numero de Pontos Turisticos: ");
    fgets(input, TAM_INPUT, stdin);
    carta1.pontosTuristicos = atoi(input);

    // --- CÁLCULOS PARA CARTA 1 (Densidade e PIB per Capita) ---
    // Garantir que a area nao seja zero para evitar divisao por zero
    if (carta1.area > 0) {
        carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidadePopulacional = 0.0f; // Ou outro valor que indique erro/indefinido
    }
    // Garantir que a populacao nao seja zero para evitar divisao por zero
    if (carta1.populacao > 0) {
        carta1.pibPerCapita = carta1.pib / carta1.populacao;
    } else {
        carta1.pibPerCapita = 0.0f; // Ou outro valor
    }

    // --- CÁLCULO DO SUPER PODER PARA CARTA 1 ---
    // Conversões explícitas para float são cruciais aqui
    carta1.superPoder = (float)carta1.populacao + carta1.area + carta1.pib +
                        (float)carta1.pontosTuristicos + carta1.pibPerCapita;
    // Adiciona o inverso da densidade populacional, verificando divisao por zero
    if (carta1.densidadePopulacional > 0) {
        carta1.superPoder += (1.0f / carta1.densidadePopulacional);
    }


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
    carta2.populacao = strtoul(input, NULL, 10);

    printf("Area (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    carta2.area = atof(input);

    printf("PIB (em bilhoes de reais): ");
    fgets(input, TAM_INPUT, stdin);
    carta2.pib = atof(input);

    printf("Numero de Pontos Turisticos: ");
    fgets(input, TAM_INPUT, stdin);
    carta2.pontosTuristicos = atoi(input);

    // --- CÁLCULOS PARA CARTA 2 (Densidade e PIB per Capita) ---
    if (carta2.area > 0) {
        carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidadePopulacional = 0.0f;
    }
    if (carta2.populacao > 0) {
        carta2.pibPerCapita = carta2.pib / carta2.populacao;
    } else {
        carta2.pibPerCapita = 0.0f;
    }

    // --- CÁLCULO DO SUPER PODER PARA CARTA 2 ---
    carta2.superPoder = (float)carta2.populacao + carta2.area + carta2.pib +
                        (float)carta2.pontosTuristicos + carta2.pibPerCapita;
    if (carta2.densidadePopulacional > 0) {
        carta2.superPoder += (1.0f / carta2.densidadePopulacional);
    }

    // --- EXIBIÇÃO DAS CARTAS CADASTRADAS ---
    printf("\n--- Informacoes Completas das Cartas ---\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // --- COMPARAÇÃO DE CARTAS ---
    printf("\n--- Comparacao de Cartas ---\n");

    // Lembre-se: '0' para maior vence, '1' para menor vence
    compararAtributo("Populacao", (float)carta1.populacao, (float)carta2.populacao, 0);
    compararAtributo("Area", carta1.area, carta2.area, 0);
    compararAtributo("PIB", carta1.pib, carta2.pib, 0);
    compararAtributo("Pontos Turisticos", (float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos, 0);
    compararAtributo("Densidade Populacional", carta1.densidadePopulacional, carta2.densidadePopulacional, 1); // Menor vence!
    compararAtributo("PIB per Capita", carta1.pibPerCapita, carta2.pibPerCapita, 0);
    compararAtributo("Super Poder", carta1.superPoder, carta2.superPoder, 0);

    printf("\nDesafio Nivel Mestre Concluido! Parabens!\n");

    return 0;
}
