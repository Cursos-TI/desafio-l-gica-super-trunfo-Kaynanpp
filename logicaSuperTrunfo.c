#include <stdio.h>

int main()
{
    unsigned int populacao1, pontos1;
    float area1, pib1;
    char estado1[50], codigo1[50], cidade1[50];

    unsigned int populacao2, pontos2;
    float area2, pib2;
    char estado2[50], codigo2[50], cidade2[50];

    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    int opcao;

    // === CARTA 1 ===
    printf("=== CADASTRO DA PRIMEIRA CARTA ===\n");

    printf("Digite o Estado: ");
    scanf("%s", estado1);

    printf("Digite o codigo da carta: ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf("%s", cidade1);

    printf("Digite o numero de habitantes da cidade: ");
    scanf("%u", &populacao1);

    printf("Digite a area da cidade (em km): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite quantos pontos turisticos tem na cidade: ");
    scanf("%u", &pontos1);

    // Cálculos
    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1; // PIB convertido para reais (bilhões -> unidades)

    // === CARTA 2 ===
    printf("\n=== CADASTRO DA SEGUNDA CARTA ===\n");

    printf("Digite o Estado: ");
    scanf("%s", estado2);

    printf("Digite o codigo da carta: ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf("%s", cidade2);

    printf("Digite o numero de habitantes da cidade: ");
    scanf("%u", &populacao2);

    printf("Digite a area da cidade (em km): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite quantos pontos turisticos tem na cidade: ");
    scanf("%u", &pontos2);

    // Cálculos
    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // === EXIBIÇÃO ===
    printf("\n\n===== CARTA 1 =====\n");
    printf("Codigo da Carta: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Estado: %s\n", estado1);
    printf("Populacao: %u habitantes\n", populacao1);
    printf("Area: %.2f km\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %u\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita1);

    printf("\n===== CARTA 2 =====\n");
    printf("Codigo da Carta: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Estado: %s\n", estado2);
    printf("Populacao: %u habitantes\n", populacao2);
    printf("Area: %.2f km\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %u\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita2);

    
    // === MENU DE COMPARAÇÃO ===
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("\nEscolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\n\n===== COMPARACAO DE CARTAS =====\n");

    switch (opcao)
    {
    case 1:
        printf("Atributo: Populacao\n");
        printf("Carta 1 - %s (%s): %u habitantes\n", cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %u habitantes\n", cidade2, estado2, populacao2);

        if (populacao1 > populacao2)
        {
            printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
        }
        else if (populacao2 > populacao1)
        {
            printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
        }
        else
        {
            printf("\nResultado: Empate!\n");
        }
        break;

    case 2:
        printf("Atributo: Area\n");
        printf("Carta 1 - %s (%s): %.2f km²\n", cidade1, estado1, area1);
        printf("Carta 2 - %s (%s): %.2f km²\n", cidade2, estado2, area2);

        if (area1 > area2)
        {
            printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
        }
        else if (area2 > area1)
        {
            printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
        }
        else
        {
            printf("\nResultado: Empate!\n");
        }
        break;

    case 3:
        printf("Atributo: PIB\n");
        printf("Carta 1 - %s (%s): %.2f bilhões\n", cidade1, estado1, pib1);
        printf("Carta 2 - %s (%s): %.2f bilhões\n", cidade2, estado2, pib2);

        if (pib1 > pib2)
        {
            printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
        }
        else if (pib2 > pib1)
        {
            printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
        }
        else
        {
            printf("\nResultado: Empate!\n");
        }
        break;

    case 4:
        printf("Atributo: Densidade Populacional\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade1, estado1, densidade1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, densidade2);

        // Menor valor vence
        if (densidade1 < densidade2)
        {
            printf("\nResultado: Carta 1 (%s) venceu (menor densidade)!\n", cidade1);
        }
        else if (densidade2 < densidade1)
        {
            printf("\nResultado: Carta 2 (%s) venceu (menor densidade)!\n", cidade2);
        }
        else
        {
            printf("\nResultado: Empate!\n");
        }
        break;

    case 5:
        printf("Atributo: PIB per capita\n");
        printf("Carta 1 - %s (%s): R$ %.2f\n", cidade1, estado1, pib_per_capita1);
        printf("Carta 2 - %s (%s): R$ %.2f\n", cidade2, estado2, pib_per_capita2);

        if (pib_per_capita1 > pib_per_capita2)
        {
            printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
        }
        else if (pib_per_capita2 > pib_per_capita1)
        {
            printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
        }
        else
        {
            printf("\nResultado: Empate!\n");
        }
        break;

    default:
        printf("Opcao invalida. Encerrando o programa.\n");
        break;
    }

    return 0;
}
   
