#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_CODIGO 10
#define TAM_NOME 100
#define TAM_INPUT 100

void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    // Variáveis da Carta 1
    char estado1;
    char codigo1[TAM_CODIGO];
    char nomeCidade1[TAM_NOME];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Variáveis da Carta 2
    char estado2;
    char codigo2[TAM_CODIGO];
    char nomeCidade2[TAM_NOME];
    int populacao2, pontosTuristicos2;
    float area2, pib2;
    char input[TAM_INPUT];

    // Entrada da Carta 1
    printf("Cadastro da Carta 1:\n");

    printf("Estado (letra de A a H): ");
    fgets(input, TAM_INPUT, stdin);
    estado1 = input[0];

    printf("Código da Carta (ex: A01): ");
    fgets(codigo1, TAM_CODIGO, stdin);
    removerNovaLinha(codigo1);

    printf("Nome da Cidade: ");
    fgets(nomeCidade1, TAM_NOME, stdin);
    removerNovaLinha(nomeCidade1);

    printf("População: ");
    fgets(input, TAM_INPUT, stdin);
    populacao1 = atoi(input);

    printf("Área (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    area1 = atof(input);

    printf("PIB (em bilhões de reais): ");
    fgets(input, TAM_INPUT, stdin);
    pib1 = atof(input);

    printf("Número de Pontos Turísticos: ");
    fgets(input, TAM_INPUT, stdin);
    pontosTuristicos1 = atoi(input);

    // Entrada da Carta 2
    printf("\nCadastro da Carta 2:\n");

    printf("Estado (letra de A a H): ");
    fgets(input, TAM_INPUT, stdin);
    estado2 = input[0];

    printf("Código da Carta (ex: B02): ");
    fgets(codigo2, TAM_CODIGO, stdin);
    removerNovaLinha(codigo2);

    printf("Nome da Cidade: ");
    fgets(nomeCidade2, TAM_NOME, stdin);
    removerNovaLinha(nomeCidade2);

    printf("População: ");
    fgets(input, TAM_INPUT, stdin);
    populacao2 = atoi(input);

    printf("Área (em km²): ");
    fgets(input, TAM_INPUT, stdin);
    area2 = atof(input);

    printf("PIB (em bilhões de reais): ");
    fgets(input, TAM_INPUT, stdin);
    pib2 = atof(input);

    printf("Número de Pontos Turísticos: ");
    fgets(input, TAM_INPUT, stdin);
    pontosTuristicos2 = atoi(input);

    // Impressão das cartas
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0;
}
