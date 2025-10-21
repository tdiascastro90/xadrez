/*
 * Desafio (nível novato + aventureiro): Movimentando Peças de Xadrez
 *
 * Peças já implementadas:
 *  - Torre (for): 5 casas para a Direita
 *  - Bispo (while): 5 casas na diagonal Cima Direita
 *  - Rainha (do-while): 8 casas para a Esquerda
 *
 * Evolução (nível aventureiro):
 *  - Cavalo: move em "L" usando loops aninhados (for + while)
 *    -> Duas casas para BAIXO e uma para a ESQUERDA
 *    -> Imprimir a cada casa percorrida: "Baixo", "Baixo", "Esquerda"
 *
 * Observações:
 *  - Entradas são definidas via constantes/variáveis no código.
 *  - Apenas int e strings (char*) são usados.
 *  - Código comentado e organizado para legibilidade.
 */

#include <stdio.h>

int main(void) {
    /* ===== Configuração das “entradas” (quantidade de casas) ===== */
    const int casasTorre  = 5;  /* Torre: Direita */
    const int casasBispo  = 5;  /* Bispo: Cima Direita */
    const int casasRainha = 8;  /* Rainha: Esquerda */

    /* ===== Torre com for ===== */
    printf("Torre (for) — movendo %d casas para a Direita:\n", casasTorre);
    for (int passo = 1; passo <= casasTorre; passo++) {
        printf("Direita\n");
    }
    printf("\n");

    /* ===== Bispo com while ===== */
    printf("Bispo (while) — movendo %d casas na diagonal Cima Direita:\n", casasBispo);
    int passosBispo = 0;
    while (passosBispo < casasBispo) {
        printf("Cima Direita\n");
        passosBispo++;
    }
    printf("\n");

    /* ===== Rainha com do-while ===== */
    printf("Rainha (do-while) — movendo %d casas para a Esquerda:\n", casasRainha);
    int passosRainha = 0;
    do {
        printf("Esquerda\n");
        passosRainha++;
    } while (passosRainha < casasRainha);

    /* ===== Linha em branco para separar do Cavalo, como solicitado ===== */
    printf("\n");

    /* ===============================================================
     * Cavalo (nível aventureiro) — LOOPS ANINHADOS (for + while)
     * Movimento solicitado: DUAS casas para BAIXO e UMA para ESQUERDA.
     * Estratégia:
     *   - Usamos um laço externo 'for' para iterar pelos "segmentos" do L:
     *       segmento 0 -> vertical (Baixo) com 2 passos
     *       segmento 1 -> horizontal (Esquerda) com 1 passo
     *   - Dentro do for, um laço 'while' executa o número de passos do segmento,
     *     imprimindo a direção a cada casa percorrida.
     * Isso cumpre o requisito de loops aninhados com um 'for' obrigatório.
     * =============================================================== */
    const int cavaloPassosBaixo    = 2;
    const int cavaloPassosEsquerda = 1;

    /* Vetores auxiliares para direções e passos por segmento do "L" */
    const char* direcoes[2] = { "Baixo", "Esquerda" };
    const int passosPorSegmento[2] = { cavaloPassosBaixo, cavaloPassosEsquerda };

    printf("Cavalo (for + while) — movendo em 'L': %d para Baixo e %d para Esquerda:\n",
           cavaloPassosBaixo, cavaloPassosEsquerda);

    /* Laço externo FOR: percorre os dois segmentos do L (vertical e horizontal) */
    for (int segmento = 0; segmento < 2; segmento++) {
        int passosRestantes = passosPorSegmento[segmento];

        /* Laço interno WHILE: imprime cada casa do segmento atual */
        while (passosRestantes > 0) {
            printf("%s\n", direcoes[segmento]);
            passosRestantes--;
        }
    }

    /* Fim da simulação */
    return 0;
}
