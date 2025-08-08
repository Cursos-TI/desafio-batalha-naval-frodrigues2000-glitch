#include <stdio.h>

// Definindo constantes para o tamanho do tabuleiro e dos navios.
// Isso torna o código mais flexível e fácil de ler.
// Autor: Fernando Rodrigues 
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define SIMBOLO_AGUA 0
#define SIMBOLO_NAVIO 3

// --- Função para inicializar o tabuleiro com 'água' (0) ---
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Laços aninhados para percorrer cada célula do tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = SIMBOLO_AGUA; // Atribui 0 a cada posição
        }
    }
}

// --- Função para exibir o tabuleiro no console ---
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    // Laços aninhados para percorrer e imprimir cada célula do tabuleiro
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            // Imprime o valor da célula, seguido de um espaço para formatação
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); // Pula para a próxima linha após imprimir uma linha completa
    }
}

// --- Função para validar o posicionamento de um navio ---
// Retorna 1 se o posicionamento for válido e 0 caso contrário.
int validarPosicionamento(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                          int linha, int coluna, 
                          char orientacao) {
    // Validação de limites para o navio horizontal
    if (orientacao == 'H') {
        // Verifica se o navio horizontal ultrapassa o limite direito
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Posição inválida
        }
        // Verifica sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] == SIMBOLO_NAVIO) {
                return 0; // Há sobreposição
            }
        }
    }
    // Validação de limites para o navio vertical
    else if (orientacao == 'V') {
        // Verifica se o navio vertical ultrapassa o limite inferior
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Posição inválida
        }
        // Verifica sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == SIMBOLO_NAVIO) {
                return 0; // Há sobreposição
            }
        }
    }
    // Validação de limites gerais (linha e coluna iniciais)
    if (linha >= TAMANHO_TABULEIRO || coluna >= TAMANHO_TABULEIRO) {
        return 0; // Coordenada inicial fora do tabuleiro
    }
    
    // Se todas as validações passarem, o posicionamento é válido
    return 1;
}

// --- Função para posicionar um navio no tabuleiro ---
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, 
                     char orientacao) {
    // Valida o posicionamento antes de tentar colocar o navio
    if (!validarPosicionamento(tabuleiro, linha, coluna, orientacao)) {
        printf("Erro: Não foi possível posicionar o navio na linha %d, coluna %d com orientação %c.\n", linha, coluna, orientacao);
        printf("Verifique se as coordenadas estão dentro do tabuleiro ou se há sobreposição.\n");
        return; // Sai da função se a validação falhar
    }

    // Posiciona o navio horizontalmente
    if (orientacao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = SIMBOLO_NAVIO;
        }
    }
    // Posiciona o navio verticalmente
    else if (orientacao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = SIMBOLO_NAVIO;
        }
    }
}

// --- Função principal (main) ---
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // 1. Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // 2. Define as coordenadas iniciais para os dois navios
    // Navio Horizontal: Início na linha 1, coluna 2
    int navioH_linha = 1;
    int navioH_coluna = 2;

    // Navio Vertical: Início na linha 5, coluna 5
    int navioV_linha = 5;
    int navioV_coluna = 5;

    // 3. Posiciona os navios no tabuleiro, chamando a função
    // O navio horizontal
    posicionarNavio(tabuleiro, navioH_linha, navioH_coluna, 'H');

    // O navio vertical
    posicionarNavio(tabuleiro, navioV_linha, navioV_coluna, 'V');
    
    // 4. Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa terminou com sucesso
}
