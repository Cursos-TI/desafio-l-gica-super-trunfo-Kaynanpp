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

    int opcao1, opcao2;

    // === CADASTRO CARTA 1 ===
    printf("=== CADASTRO DA PRIMEIRA CARTA ===\n");

    printf("Digite o Estado: ");
    scanf("%49s", estado1);

    printf("Digite o codigo da carta: ");
    scanf("%49s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf("%49s", cidade1);

    printf("Digite o numero de habitantes da cidade: ");
    scanf("%u", &populacao1);

    printf("Digite a area da cidade (em km): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite quantos pontos turisticos tem na cidade: ");
    scanf("%u", &pontos1);

    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;

    // === CADASTRO CARTA 2 ===
    printf("\n=== CADASTRO DA SEGUNDA CARTA ===\n");

    printf("Digite o Estado: ");
    scanf("%49s", estado2);

    printf("Digite o codigo da carta: ");
    scanf("%49s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf("%49s", cidade2);

    printf("Digite o numero de habitantes da cidade: ");
    scanf("%u", &populacao2);

    printf("Digite a area da cidade (em km): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite quantos pontos turisticos tem na cidade: ");
    scanf("%u", &pontos2);

    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // === MENU DE ESCOLHA DOS ATRIBUTOS ===
    printf("\n===== MENU DE ATRIBUTOS =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");

    printf("\nEscolha o primeiro atributo para comparar: ");
    scanf("%d", &opcao1);

    printf("Escolha o segundo atributo para comparar: ");
    scanf("%d", &opcao2);

    printf("\n===== COMPARACAO DE CARTAS =====\n");

    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    const char *nomeAttr1, *nomeAttr2;

    // === MAPEAMENTO DOS ATRIBUTOS SELECIONADOS ===
    switch (opcao1)
    {
    case 1: nomeAttr1 = "Populacao"; valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
    case 2: nomeAttr1 = "Area"; valor1_carta1 = area1; valor1_carta2 = area2; break;
    case 3: nomeAttr1 = "PIB"; valor1_carta1 = pib1; valor1_carta2 = pib2; break;
    case 4: nomeAttr1 = "Densidade Populacional"; valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
    case 5: nomeAttr1 = "PIB per capita"; valor1_carta1 = pib_per_capita1; valor1_carta2 = pib_per_capita2; break;
    default: nomeAttr1 = "Invalido"; break;
    }

    switch (opcao2)
    {
    case 1: nomeAttr2 = "Populacao"; valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
    case 2: nomeAttr2 = "Area"; valor2_carta1 = area1; valor2_carta2 = area2; break;
    case 3: nomeAttr2 = "PIB"; valor2_carta1 = pib1; valor2_carta2 = pib2; break;
    case 4: nomeAttr2 = "Densidade Populacional"; valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
    case 5: nomeAttr2 = "PIB per capita"; valor2_carta1 = pib_per_capita1; valor2_carta2 = pib_per_capita2; break;
    default: nomeAttr2 = "Invalido"; break;
    }

    // === EXIBIÇÃO DOS VALORES ===
    printf("\nAtributo 1 - %s\n", nomeAttr1);
    printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor1_carta1);
    printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor1_carta2);

    printf("\nAtributo 2 - %s\n", nomeAttr2);
    printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor2_carta1);
    printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor2_carta2);

    // === COMPARAÇÃO AVANÇADA ===
    int venceu1_attr1 = (opcao1 == 4) ? (valor1_carta1 < valor1_carta2) : (valor1_carta1 > valor1_carta2);
    int venceu1_attr2 = (opcao2 == 4) ? (valor2_carta1 < valor2_carta2) : (valor2_carta1 > valor2_carta2);
    int venceu2_attr1 = (opcao1 == 4) ? (valor1_carta2 < valor1_carta1) : (valor1_carta2 > valor1_carta1);
    int venceu2_attr2 = (opcao2 == 4) ? (valor2_carta2 < valor2_carta1) : (valor2_carta2 > valor2_carta1);

    printf("\n===== RESULTADO FINAL =====\n");

    if (venceu1_attr1 && venceu1_attr2)
    {
        printf("Carta 1 (%s) venceu em ambos os atributos!\n", cidade1);
    }
    else if (venceu2_attr1 && venceu2_attr2)
    {
        printf("Carta 2 (%s) venceu em ambos os atributos!\n", cidade2);
    }
    else if ((venceu1_attr1 && venceu2_attr2) || (venceu1_attr2 && venceu2_attr1))
    {
        printf("Empate tecnico! Cada carta venceu em um atributo.\n");
    }
    else
    {
        // Casos mais complexos ou iguais
        (valor1_carta1 == valor1_carta2 && valor2_carta1 == valor2_carta2)
            ? printf("Empate absoluto! Ambas as cartas tem os mesmos valores.\n")
            : printf("Nenhuma carta venceu claramente.\n");
    }

    printf("\nComparacao encerrada. Obrigado por jogar o Super Trunfo!\n");
    return 0;
}
