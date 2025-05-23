#include <stdio.h>

typedef struct {
    char estado[30];
    int codigo;
    char nome[30];
    unsigned long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
    float densidadePopulacional;
    double pibPerCapita;
    float superPoder;
} Carta;

void lerCarta(Carta *c) {
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Codigo: ");
    scanf("%d", &c->codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c->nome);
    printf("Populacao: ");
    scanf("%lu", &c->populacao);
    printf("Area (km2): ");
    scanf("%f", &c->area);
    printf("PIB: ");
    scanf("%lf", &c->pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &c->pontosTuristicos);
}

void calcularAtributos(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    c->superPoder = (float)c->populacao + c->area + (float)c->pib +
                    c->pontosTuristicos + (float)c->pibPerCapita +
                    (1.0f / c->densidadePopulacional);
}

void compararEAvaliar(char *atributo, float v1, float v2, int menorVence) {
    int resultado;
    if (menorVence)
        resultado = (v1 < v2) ? 1 : 0;
    else
        resultado = (v1 > v2) ? 1 : 0;

    printf("%s: Carta 1 venceu (%d)\n", atributo, resultado);
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);
    calcularAtributos(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);
    calcularAtributos(&carta2);

    printf("\nComparacao de Cartas:\n\n");

    compararEAvaliar("Populacao", (float)carta1.populacao, (float)carta2.populacao, 0);
    compararEAvaliar("Area", carta1.area, carta2.area, 0);
    compararEAvaliar("PIB", (float)carta1.pib, (float)carta2.pib, 0);
    compararEAvaliar("Pontos Turisticos", (float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos, 0);
    compararEAvaliar("Densidade Populacional", carta1.densidadePopulacional, carta2.densidadePopulacional, 1);
    compararEAvaliar("PIB per Capita", (float)carta1.pibPerCapita, (float)carta2.pibPerCapita, 0);
    compararEAvaliar("Super Poder", carta1.superPoder, carta2.superPoder, 0);

    return 0;
}