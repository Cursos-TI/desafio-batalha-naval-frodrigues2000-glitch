#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definições de constantes para melhorar a legibilidade do código.
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3

// Protótipos das funções utilizadas no programa.
// A utilização de protótipos permite que as funções sejam definidas em qualquer ordem no arquivo.
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int tipoNavio);
int verificarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao);

// A função principal do programa.
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o gerador de números aleatórios com base no tempo atual.
    // Isso garante que os navios sejam posicionados em locais diferentes a cada execução.
    srand(time(NULL));

    // Inicializa todas as posições do tabuleiro com o valor de água (0).
    inicializarTabuleiro(tabuleiro);

    // Variáveis de controle para posicionar os navios.
    int naviosHorizontaisVerticais = 0;
    int naviosDiagonais = 0;

    // Loop para posicionar os dois navios horizontais ou verticais.
    while (naviosHorizontaisVerticais < 2) {
        // Gera coordenadas e direções aleatórias para o navio.
        int linhaInicial = rand() % TAMANHO_TABULEIRO;
        int colunaInicial = rand() % TAMANHO_TABULEIRO;
        int direcao = rand() % 2; // 0 para horizontal, 1 para vertical

        // Tenta posicionar o navio. Se for bem-sucedido, incrementa o contador.
        if (posicionarNavio(tabuleiro, linhaInicial, colunaInicial, direcao, 0)) {
            naviosHorizontaisVerticais++;
        }
    }

    // Loop para posicionar os dois navios diagonais.
    while (naviosDiagonais < 2) {
        // Gera coordenadas e direções aleatórias para o navio.
        int linhaInicial = rand() % TAMANHO_TABULEIRO;
        int colunaInicial = rand() % TAMANHO_TABULEIRO;
        int direcao = (rand() % 2) + 2; // 2 para diagonal crescente, 3 para diagonal decrescente

        // Tenta posicionar o navio. Se for bem-sucedido, incrementa o contador.
        if (posicionarNavio(tabuleiro, linhaInicial, colunaInicial, direcao, 1)) {
            naviosDiagonais++;
        }
    }

    // Exibe o tabuleiro completo com os navios posicionados.
    exibirTabuleiro(tabuleiro);

    return 0;
}

/**
 * @brief Inicializa todas as posições do tabuleiro com o valor de água.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o tabuleiro 10x10 no console.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime o cabeçalho das colunas para facilitar a leitura.
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Imprime as linhas do tabuleiro.
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Imprime o número da linha.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro, validando a posição.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 * @param linha A linha inicial do navio.
 * @param coluna A coluna inicial do navio.
 * @param direcao A direção do navio (0: horizontal, 1: vertical, 2: diagonal crescente, 3: diagonal decrescente).
 * @param tipoNavio Indica se é um navio horizontal/vertical (0) ou diagonal (1).
 * @return Retorna 1 se o navio foi posicionado com sucesso, 0 caso contrário.
 */
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int tipoNavio) {
    // Primeiro, verifica se a posição é válida.
    if (verificarPosicao(tabuleiro, linha, coluna, direcao)) {
        // Se a posição for válida, preenche as posições com o valor do navio.
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            switch (direcao) {
                case 0: // Horizontal: a coluna muda, a linha permanece.
                    tabuleiro[linha][coluna + i] = NAVIO;
                    break;
                case 1: // Vertical: a linha muda, a coluna permanece.
                    tabuleiro[linha + i][coluna] = NAVIO;
                    break;
                case 2: // Diagonal crescente: linha e coluna aumentam.
                    tabuleiro[linha + i][coluna + i] = NAVIO;
                    break;
                case 3: // Diagonal decrescente: linha aumenta e coluna diminui.
                    tabuleiro[linha + i][coluna - i] = NAVIO;
                    break;
            }
        }
        return 1; // Retorna 1 para indicar sucesso.
    }
    return 0; // Retorna 0 para indicar falha.
}

/**
 * @brief Verifica se a posição e a direção de um navio são válidas.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 * @param linha A linha inicial do navio.
 * @param coluna A coluna inicial do navio.
 * @param direcao A direção do navio.
 * @return Retorna 1 se a posição é válida (dentro dos limites e sem sobreposição), 0 caso contrário.
 */
int verificarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual, colunaAtual;
        
        switch (direcao) {
            case 0: // Horizontal
                linhaAtual = linha;
                colunaAtual = coluna + i;
                break;
            case 1: // Vertical
                linhaAtual = linha + i;
                colunaAtual = coluna;
                break;
            case 2: // Diagonal crescente
                linhaAtual = linha + i;
                colunaAtual = coluna + i;
                break;
            case 3: // Diagonal decrescente
                linhaAtual = linha + i;
                colunaAtual = coluna - i;
                break;
            default:
                return 0; // Direção inválida.
        }

        // Verifica se a posição calculada está fora dos limites do tabuleiro.
        if (linhaAtual >= TAMANHO_TABULEIRO || linhaAtual < 0 || colunaAtual >= TAMANHO_TABULEIRO || colunaAtual < 0) {
            return 0;
        }

        // Verifica se a posição já está ocupada por outro navio.
        if (tabuleiro[linhaAtual][colunaAtual] == NAVIO) {
            return 0;
        }
    }
    return 1; // Se todas as verificações passarem, a posição é válida.
}