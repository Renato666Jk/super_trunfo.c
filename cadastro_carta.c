#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para uma carta de cidade
typedef struct {
    char nome_cidade[50];
    char nome_pais[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
    long long super_poder;
} Carta;

// Função para exibir as informações de uma carta
void exibirCarta(Carta carta, int indice) {
    printf("\n--- Carta %d ---\n", indice);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("Pais: %s\n", carta.nome_pais);
    printf("Populacao: %lld\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %lld milhoes de US$\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f US$\n", carta.pib_per_capita);
    printf("Super Poder: %lld\n", carta.super_poder);
    printf("-----------------\n");
}

// Função para comparar duas cartas e exibir os resultados
void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Resultado da Comparacao ---\n");
    printf("Comparando %s (Carta 1) vs %s (Carta 2)\n\n", c1.nome_cidade, c2.nome_cidade);

    // Comparacao de Populacao
    if (c1.populacao > c2.populacao) {
        printf("Populacao: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Populacao: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("Populacao: Empate!\n");
    }

    // Comparacao de Area
    if (c1.area > c2.area) {
        printf("Area: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.area > c1.area) {
        printf("Area: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("Area: Empate!\n");
    }

    // Comparacao de PIB
    if (c1.pib > c2.pib) {
        printf("PIB: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.pib > c1.pib) {
        printf("PIB: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("PIB: Empate!\n");
    }

    // Comparacao de Pontos Turisticos
    if (c1.pontos_turisticos > c2.pontos_turisticos) {
        printf("Pontos Turisticos: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.pontos_turisticos > c1.pontos_turisticos) {
        printf("Pontos Turisticos: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("Pontos Turisticos: Empate!\n");
    }

    // Comparacao de Densidade Populacional (menor valor vence)
    if (c1.densidade_populacional < c2.densidade_populacional) {
        printf("Densidade Populacional: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.densidade_populacional < c1.densidade_populacional) {
        printf("Densidade Populacional: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("Densidade Populacional: Empate!\n");
    }

    // Comparacao de PIB per capita
    if (c1.pib_per_capita > c2.pib_per_capita) {
        printf("PIB per capita: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.pib_per_capita > c1.pib_per_capita) {
        printf("PIB per capita: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("PIB per capita: Empate!\n");
    }

    // Comparacao de Super Poder
    if (c1.super_poder > c2.super_poder) {
        printf("Super Poder: Vencedor -> %s\n", c1.nome_cidade);
    } else if (c2.super_poder > c1.super_poder) {
        printf("Super Poder: Vencedor -> %s\n", c2.nome_cidade);
    } else {
        printf("Super Poder: Empate!\n");
    }

    printf("-------------------------------\n");
}

int main() {
    const int MAX_CARTAS = 8;
    Carta cartas[MAX_CARTAS];
    int num_cartas = 0;
    int i;
    char continuar;
    
    printf("Bem-vindo ao Super Trunfo - Paises!\n");
    printf("Vamos cadastrar suas cartas. Voce pode cadastrar ate %d cartas.\n\n", MAX_CARTAS);

    // Loop para cadastro de cartas
    do {
        if (num_cartas >= MAX_CARTAS) {
            printf("Limite de cartas atingido.\n");
            break;
        }

        printf("--- Cadastro da Carta %d ---\n", num_cartas + 1);
        printf("Nome da cidade: ");
        scanf(" %49[^\n]", cartas[num_cartas].nome_cidade);

        printf("Nome do pais: ");
        scanf(" %49[^\n]", cartas[num_cartas].nome_pais);

        printf("Populacao (Ex: 1000000): ");
        scanf("%lld", &cartas[num_cartas].populacao);

        printf("Area (km2): ");
        scanf("%lf", &cartas[num_cartas].area);

        printf("PIB (milhoes de US$): ");
        scanf("%lld", &cartas[num_cartas].pib);

        printf("Pontos turisticos: ");
        scanf("%d", &cartas[num_cartas].pontos_turisticos);

        // Limpa o buffer do teclado
        while (getchar() != '\n');

        // Calcula as propriedades extras
        cartas[num_cartas].densidade_populacional = cartas[num_cartas].populacao / cartas[num_cartas].area;
        cartas[num_cartas].pib_per_capita = (double)cartas[num_cartas].pib / cartas[num_cartas].populacao;
        cartas[num_cartas].super_poder = cartas[num_cartas].populacao + (long long)cartas[num_cartas].area + cartas[num_cartas].pib + cartas[num_cartas].pontos_turisticos;

        num_cartas++;

        printf("\nDeseja cadastrar outra carta? (s/n): ");
        scanf(" %c", &continuar);
        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    // Exibição de todas as cartas cadastradas
    printf("--- Cartas Cadastradas ---\n");
    for (i = 0; i < num_cartas; i++) {
        exibirCarta(cartas[i], i + 1);
    }

    // Loop de comparacao
    if (num_cartas >= 2) {
        int indice1, indice2;
        printf("\n--- Modo de Comparacao ---\n");
        printf("Escolha duas cartas para comparar (1 a %d).\n", num_cartas);

        printf("Indice da primeira carta: ");
        scanf("%d", &indice1);

        printf("Indice da segunda carta: ");
        scanf("%d", &indice2);
        
        if (indice1 >= 1 && indice1 <= num_cartas && indice2 >= 1 && indice2 <= num_cartas) {
            compararCartas(cartas[indice1 - 1], cartas[indice2 - 1]);
        } else {
            printf("\nIndices invalidos. Por favor, reinicie o programa e tente novamente.\n");
        }

    } else {
        printf("\nVoce precisa de pelo menos 2 cartas para iniciar o modo de comparacao.\n");
    }

    return 0;
}
