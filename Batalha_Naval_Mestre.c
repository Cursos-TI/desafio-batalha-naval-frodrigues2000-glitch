/*
 * Autor: Fernando Rodrigues
 * Descrição: Este programa em C simula um jogo de Batalha Naval,
 * adicionando a funcionalidade de habilidades especiais com áreas de efeito distintas.
 * O programa define um tabuleiro 10x10, cria matrizes para as habilidades
 * 'Cone', 'Cruz' e 'Octaedro', e as sobrepõe ao tabuleiro para visualização.
 * A posição inicial dos navios e das habilidades é fixa no código.
 * As áreas afetadas pelas habilidades são marcadas no tabuleiro e exibidas
 * no console. A lógica para a criação das matrizes de habilidade e a
 * sua sobreposição utiliza loops aninhados e condicionais.
 */

#include <stdio.h>
#include <stdlib.h> // Para a função abs()

// Definir o tamanho do tabuleiro principal
#define TAMANHO_TABULEIRO 10
// Definir um tamanho fixo para as matrizes das habilidades
#define TAMANHO_HABILIDADE 5

// Macros para representar os elementos no tabuleiro, tornando o código mais legível
#define AGUA 0
#define NAVIO 3
#define HABILIDADE_AFETADA 5
#define HABILIDADE_NAO_AFETADA 0
#define HABILIDADE_AFETAR 1

// --- Protótipos de funções ---
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origemLinha, int origemColuna);
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // --- Demonstração da Habilidade Cone ---
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeCone(habilidadeCone);
    // O ponto de origem no tabuleiro (linha 3, coluna 4) é onde o 'topo' do cone será centralizado.
    sobreporHabilidade(tabuleiro, habilidadeCone, 3, 4);

    printf("Tabuleiro com Habilidade Cone (origem em 3,4):\n");
    exibirTabuleiro(tabuleiro);
    
    // --- Demonstração da Habilidade Cruz ---
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeCruz(habilidadeCruz);
    // O ponto de origem da cruz no tabuleiro (linha 6, coluna 6) é o seu centro.
    sobreporHabilidade(tabuleiro, habilidadeCruz, 6, 6);

    printf("\nTabuleiro com Habilidade Cruz (origem em 6,6):\n");
    exibirTabuleiro(tabuleiro);

    // --- Demonstração da Habilidade Octaedro ---
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeOctaedro(habilidadeOctaedro);
    // O ponto de origem do octaedro no tabuleiro (linha 1, coluna 1) é o seu centro.
    sobreporHabilidade(tabuleiro, habilidadeOctaedro, 1, 1);

    printf("\nTabuleiro com Habilidade Octaedro (origem em 1,1):\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

/**
 * @brief Inicializa o tabuleiro com o valor de ÁGUA (0) em todas as posições.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Posiciona navios (valor 3) em algumas posições fixas do tabuleiro
 * para simular um cenário de jogo.
 * @param tabuleiro A matriz 10x10 que representa o tabuleiro.
 */
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    tabuleiro[9][0] = NAVIO;
    tabuleiro[9][1] = NAVIO;
}

/**
 * @brief Constrói a matriz de habilidade em formato de cone.
 * O cone é desenhado apontando para baixo, com o topo na primeira linha,
 * expandindo-se a cada linha. A largura da área afetada aumenta em 2 por
 * linha, mantendo o centro na coluna do meio.
 * @param habilidade A matriz 5x5 que representará a habilidade.
 */
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A largura do cone na linha 'i' é (i * 2 + 1).
            // A condição verifica se a coluna 'j' está dentro dessa largura,
            // centralizada na coluna 'centro'.
            if (j >= centro - i && j <= centro + i) {
                habilidade[i][j] = HABILIDADE_AFETAR;
            } else {
                habilidade[i][j] = HABILIDADE_NAO_AFETADA;
            }
        }
    }
}

/**
 * @brief Constrói a matriz de habilidade em formato de cruz.
 * O ponto de origem da cruz está no centro da matriz.
 * @param habilidade A matriz 5x5 que representará a habilidade.
 */
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A posição é afetada se estiver na linha do meio OU na coluna do meio.
            if (i == centro || j == centro) {
                habilidade[i][j] = HABILIDADE_AFETAR;
            } else {
                habilidade[i][j] = HABILIDADE_NAO_AFETADA;
            }
        }
    }
}

/**
 * @brief Constrói a matriz de habilidade em formato de octaedro (losango).
 * O ponto de origem do losango está no centro da matriz.
 * @param habilidade A matriz 5x5 que representará a habilidade.
 */
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int i, j;
    int centro = TAMANHO_HABILIDADE / 2;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A lógica do octaedro usa a distância de Manhattan (abs(i1-i2) + abs(j1-j2))
            // em relação ao centro da matriz. A forma é um losango.
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = HABILIDADE_AFETAR;
            } else {
                habilidade[i][j] = HABILIDADE_NAO_AFETADA;
            }
        }
    }
}

/**
 * @brief Sobrepõe a matriz de habilidade no tabuleiro principal.
 * A matriz de habilidade é centrada no ponto de origem (origemLinha, origemColuna).
 * Verifica se a sobreposição não ultrapassa os limites do tabuleiro.
 * @param tabuleiro A matriz 10x10 onde a habilidade será aplicada.
 * @param habilidade A matriz 5x5 da habilidade a ser sobreposta.
 * @param origemLinha A coordenada da linha central no tabuleiro.
 * @param origemColuna A coordenada da coluna central no tabuleiro.
 */
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origemLinha, int origemColuna) {
    int i, j;
    int offset = TAMANHO_HABILIDADE / 2;
    int tabuleiroLinha, tabuleiroColuna;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Calcula as coordenadas correspondentes no tabuleiro,
            // centralizando a matriz de habilidade no ponto de origem.
            tabuleiroLinha = origemLinha - offset + i;
            tabuleiroColuna = origemColuna - offset + j;

            // Garante que a sobreposição esteja dentro dos limites do tabuleiro.
            if (tabuleiroLinha >= 0 && tabuleiroLinha < TAMANHO_TABULEIRO &&
                tabuleiroColuna >= 0 && tabuleiroColuna < TAMANHO_TABULEIRO) {
                // Se a posição na matriz de habilidade for 1 (afetada),
                // marca a posição no tabuleiro com 5.
                if (habilidade[i][j] == HABILIDADE_AFETAR) {
                    tabuleiro[tabuleiroLinha][tabuleiroColuna] = HABILIDADE_AFETADA;
                }
            }
        }
    }
}

/**
 * @brief Exibe o conteúdo do tabuleiro no console, utilizando caracteres
 * diferentes para cada tipo de elemento para uma visualização clara.
 * @param tabuleiro A matriz 10x10 a ser exibida.
 */
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("# "); // Navio
            } else if (tabuleiro[i][j] == HABILIDADE_AFETADA) {
                printf("@ "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}