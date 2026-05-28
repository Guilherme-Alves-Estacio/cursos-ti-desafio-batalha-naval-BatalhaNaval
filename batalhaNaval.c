#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10
#define NAVIO 3
#define HABILIDADE 3

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};

    for (int n = 2; n < 5; n++)
    {
        tabuleiro[3][n] = 3;
    }

    for (int n = 3; n < 7; n++)
    {
        tabuleiro[n][9] = 3;
    }

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    printf("\n");

    char linha2[TAMANHO_TABULEIRO] = {
        'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J'};

    int tabuleiro2[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int erro = 0;

    for (int n = 2; n < 5; n++)
    {
        int lin = n;
        int col = TAMANHO_TABULEIRO - 1 - n;

        if (lin >= TAMANHO_TABULEIRO || col >= TAMANHO_TABULEIRO ||
            tabuleiro2[lin][col] != 0)
        {
            erro = 1;
        }
        else
        {
            tabuleiro2[lin][col] = NAVIO;
        }
    }

    for (int n = 0; n < 3; n++)
    {
        int lin = TAMANHO_TABULEIRO - 1 - n;
        int col = n;

        if (lin >= TAMANHO_TABULEIRO || col >= TAMANHO_TABULEIRO ||
            tabuleiro2[lin][col] != 0)
        {
            erro = 1;
        }
        else
        {
            tabuleiro2[lin][col] = NAVIO;
        }
    }

    for (int n = 3; n < 7; n++)
    {
        int lin = n;
        int col = TAMANHO_TABULEIRO - 1;

        if (lin >= TAMANHO_TABULEIRO || col >= TAMANHO_TABULEIRO ||
            tabuleiro2[lin][col] != 0)
        {
            erro = 1;
        }
        else
        {
            tabuleiro2[lin][col] = NAVIO;
        }
    }

    for (int n = 3; n < 7; n++)
    {
        int lin = TAMANHO_TABULEIRO - 4;
        int col = n;

        if (lin >= TAMANHO_TABULEIRO || col >= TAMANHO_TABULEIRO ||
            tabuleiro2[lin][col] != 0)
        {
            erro = 1;
        }
        else
        {
            tabuleiro2[lin][col] = NAVIO;
        }
    }

    if (erro)
    {
        printf("Erro ao posicionar navios!\n");
        return 1;
    }

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    printf("   ");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%c ", linha2[i]);
    }

    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro2[i][j]);
        }

        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    char linha3[TAMANHO_TABULEIRO] = {
        'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J'};

    int tabuleiro3[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    int coneLinha = 0;
    int coneColuna = 2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = -i; j <= i; j++)
        {
            tabuleiro3[coneLinha + i][coneColuna + j] = HABILIDADE;
        }
    }

    int cruzLinha = 4;
    int cruzColuna = 5;

    for (int j = -2; j <= 2; j++)
    {
        tabuleiro3[cruzLinha][cruzColuna + j] = HABILIDADE;
    }

    tabuleiro3[cruzLinha - 1][cruzColuna] = HABILIDADE;
    tabuleiro3[cruzLinha + 1][cruzColuna] = HABILIDADE;

    int octLinha = 7;
    int octColuna = 2;

    tabuleiro3[octLinha][octColuna] = HABILIDADE;

    for (int j = -1; j <= 1; j++)
    {
        tabuleiro3[octLinha + 1][octColuna + j] = HABILIDADE;
    }

    tabuleiro3[octLinha + 2][octColuna] = HABILIDADE;

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    printf("   ");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%c ", linha3[i]);
    }

    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%2d ", i + 1);

        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro3[i][j]);
        }

        printf("\n");
    }

    return 0;
}
