/*
 * Desafio: Xadrez — Nível Mestre
 * - Torre, Bispo e Rainha: recursividade (uma direção por casa)
 * - Cavalo: loops aninhados com múltiplas variáveis/condições, usando continue/break
 * - Bispo: além de recursivo, cada passo diagonal é composto por loops aninhados
 *
 * Saídas exigidas (UMA direção por linha):
 *   "Cima", "Baixo", "Esquerda", "Direita"
 *
 * Obs.:
 *  - Entradas definidas em constantes.
 *  - Sem validação de usuário.
 *  - Apenas int e strings (char*).
 *  - Comentários detalhando recursão e controle de fluxo.
 */

#include <stdio.h>

/* ===================== Assinaturas (recursivas) ===================== */
void mover_torre_direita_rec(int passos);
void mover_bispo_cima_direita_rec(int passos);
void mover_rainha_esquerda_rec(int passos);

/* ===================== Torre (recursivo) =====================
 * Caso base: passos <= 0 → fim.
 * Passo recursivo: imprime "Direita", chama a si mesmo com (passos - 1).
 */
void mover_torre_direita_rec(int passos) {
    if (passos <= 0) return;          /* caso base */
    printf("Direita\n");              /* uma casa para a Direita */
    mover_torre_direita_rec(passos - 1);
}

/* ===================== Bispo (recursivo + loops aninhados) =====================
 * Cada CHAMADA recursiva representa "1 casa diagonal" (cima + direita).
 * Para atender ao requisito de loops aninhados:
 *  - loop externo (vertical): executa 1 passo de "Cima"
 *  - loop interno (horizontal): executa 1 passo de "Direita"
 * Isso gera duas linhas de saída por casa diagonal: "Cima" e depois "Direita".
 */
void mover_bispo_cima_direita_rec(int passos) {
    if (passos <= 0) return; /* caso base */

    /* loops aninhados: externo = vertical (Cima), interno = horizontal (Direita) */
    for (int v = 0; v < 1; v++) {          /* vertical: 1 passo por casa diagonal */
        printf("Cima\n");
        for (int h = 0; h < 1; h++) {      /* horizontal: 1 passo por casa diagonal */
            printf("Direita\n");
        }
    }

    mover_bispo_cima_direita_rec(passos - 1);  /* recursão: restante das casas diagonais */
}

/* ===================== Rainha (recursivo) =====================
 * Caso base: passos <= 0 → fim.
 * Passo recursivo: imprime "Esquerda", chama a si mesmo com (passos - 1).
 */
void mover_rainha_esquerda_rec(int passos) {
    if (passos <= 0) return;          /* caso base */
    printf("Esquerda\n");             /* uma casa para a Esquerda */
    mover_rainha_esquerda_rec(passos - 1);
}

/* ===================== Cavalo (loops aninhados + múltiplas variáveis) =====================
 * Movimento solicitado: "L" para CIMA e DIREITA → 2 para CIMA, 1 para DIREITA.
 *
 * Requisitos atendidos:
 *  - Loops ANINHADOS com múltiplas variáveis/condições no cabeçalho.
 *  - Uso de continue/break para controle fino do fluxo.
 *  - Impressão de UMA direção por casa ("Cima", "Direita").
 *
 * Estratégia:
 *  - 'segmento' 0 = vertical (Cima), 1 = horizontal (Direita).
 *  - Contadores independentes 'cimaFeitos' e 'direitaFeitos' controlam os limites.
 *  - O loop interno usa uma condição composta que varia conforme o segmento.
 *  - Usamos 'continue' para pular lógica desnecessária e 'break' para encerrar o segmento.
 */
void mover_cavalo_cima_direita_loops(void) {
    const int alvoCima = 2;
    const int alvoDireita = 1;

    /* loop externo controla o segmento do L (0 = vertical, 1 = horizontal) */
    for (int segmento = 0, cimaFeitos = 0, direitaFeitos = 0;
         segmento < 2;
         segmento++) {

        /* loop interno com condição composta e variável 'tentativa' */
        for (int tentativa = 0;
             (segmento == 0 && cimaFeitos < alvoCima) ||
             (segmento == 1 && direitaFeitos < alvoDireita);
             tentativa++) {

            /* Se estamos no segmento vertical */
            if (segmento == 0) {
                /* Se já fiz os 2 passos pra cima, encerra este segmento */
                if (cimaFeitos >= alvoCima) break;

                /* Exemplo de 'continue': se a tentativa for par, apenas pula (simulando checagem) */
                if ((tentativa % 2) == 0) {
                    /* Pular ciclos "de verificação" sem imprimir movimento */
                    continue;
                }

                /* Movimento efetivo para cima */
                printf("Cima\n");
                cimaFeitos++;

                /* Se completou os 2 passos, quebra o segmento vertical */
                if (cimaFeitos == alvoCima) break;

                /* Próximo ciclo do interno */
                continue;
            }

            /* Se estamos no segmento horizontal (Direita) */
            if (segmento == 1) {
                if (direitaFeitos >= alvoDireita) break;

                /* Aqui, por exemplo, só efetivo se a tentativa for >= 1 (outra checagem artificial) */
                if (tentativa < 1) {
                    continue; /* ainda “checando” condições, sem mover */
                }

                printf("Direita\n");
                direitaFeitos++;

                /* Como é apenas 1 passo, podemos encerrar o segmento */
                break;
            }
        } /* fim loop interno */
    } /* fim loop externo */
}

int main(void) {
    /* ======== Entradas (definidas no código) ======== */
    const int passosTorreDireita  = 5;  /* Torre: Direita (recursivo) */
    const int passosBispoDiag     = 5;  /* Bispo: Cima + Direita por casa diagonal (recursivo + loops) */
    const int passosRainhaEsquerda= 8;  /* Rainha: Esquerda (recursivo) */

    /* ======== Torre (recursivo) ======== */
    printf("Torre (recursivo) — %d casas para a Direita:\n", passosTorreDireita);
    mover_torre_direita_rec(passosTorreDireita);
    printf("\n");

    /* ======== Bispo (recursivo + loops aninhados por casa) ======== */
    printf("Bispo (recursivo + loops aninhados) — %d casas na diagonal Cima/Direita:\n", passosBispoDiag);
    mover_bispo_cima_direita_rec(passosBispoDiag);
    printf("\n");

    /* ======== Rainha (recursivo) ======== */
    printf("Rainha (recursivo) — %d casas para a Esquerda:\n", passosRainhaEsquerda);
    mover_rainha_esquerda_rec(passosRainhaEsquerda);
    printf("\n");

    /* ======== Cavalo (loops aninhados complexos) ======== */
    printf("Cavalo (loops aninhados + continue/break) — 2 para Cima e 1 para Direita:\n");
    mover_cavalo_cima_direita_loops();
    printf("\n");

    return 0;
}
