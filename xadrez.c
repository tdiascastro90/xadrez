/*
 * Desafio: Movimentando as Peças do Xadrez (nível novato)
 * - Torre (for): 5 casas para a Direita
 * - Bispo (while): 5 casas na diagonal Cima Direita
 * - Rainha (do-while): 8 casas para a Esquerda
 *
 * Requisitos:
 *  - Entradas definidas em variáveis/constantes do código
 *  - Imprimir a direção a cada passo (printf com textos fixos)
 *  - Usar apenas int e strings (char*)
 *  - Código claro, comentado e organizado
 */

#include <stdio.h>

int main(void) {
    /* ===== Configuração das “entradas” (quantidade de casas) ===== */
    const int casasTorre  = 5;  /* Torre: Direita */
    const int casasBispo  = 5;  /* Bispo: Cima Direita */
    const int casasRainha = 8;  /* Rainha: Esquerda */

    /* ===== Torre com for: move em linha reta (Direita) ===== */
    printf("Torre (for) — movendo %d casas para a Direita:\n", casasTorre);
    for (int passo = 1; passo <= casasTorre; passo++) {
        /* Cada iteração representa uma casa percorrida */
        printf("Direita\n");
    }
    printf("\n");

    /* ===== Bispo com while: move na diagonal (Cima Direita) ===== */
    printf("Bispo (while) — movendo %d casas na diagonal Cima Direita:\n", casasBispo);
    int passosBispo = 0;
    while (passosBispo < casasBispo) {
        /* Em diagonal, imprimimos a combinação de duas direções */
        printf("Cima Direita\n");
        passosBispo++;
    }
    printf("\n");

    /* ===== Rainha com do-while: move em qualquer direção (Esquerda) ===== */
    printf("Rainha (do-while) — movendo %d casas para a Esquerda:\n", casasRainha);
    int passosRainha = 0;
    do {
        printf("Esquerda\n");
        passosRainha++;
    } while (passosRainha < casasRainha);

    /* Fim da simulação */
    return 0;
}
