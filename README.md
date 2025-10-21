# README — Movimentando Peças de Xadrez (Nível Novato → Aventureiro → Mestre)

Projeto em C que simula movimentos de peças de xadrez com foco em estruturas de repetição, **recursividade** e **loops aninhados**.  
Evolui em três etapas: **Novato** (loops simples), **Aventureiro** (cavalo com loops aninhados) e **Mestre** (recursão + loops complexos).

---

## 🎯 Objetivo

Implementar a lógica de movimento para **Torre**, **Bispo**, **Rainha** e **Cavalo**, imprimindo **uma direção por linha** a cada casa percorrida, conforme o enunciado:

```
Cima
Baixo
Esquerda
Direita
```

No nível mestre:

- **Torre, Bispo e Rainha** → **funções recursivas** substituem os loops simples.  
- **Bispo** → além da recursão, **loops aninhados** (externo vertical, interno horizontal) por **cada** casa diagonal.  
- **Cavalo** → **loops aninhados com múltiplas variáveis/condições**, usando `continue` e `break`, no movimento em “L” **(2 para Cima, 1 para Direita)**.

---

## 🧱 Estrutura sugerida dos arquivos

```
.
├── xadrez_nivel_mestre.c   # Código-fonte principal com todas as peças e requisitos
└── README.md               # Este documento
```

> Se você já tem versões anteriores (novato/aventureiro), pode mantê-las, mas o arquivo **`xadrez_nivel_mestre.c`** contém tudo integrado.

---

## ⚙️ Requisitos

- Compilador C (GCC/Clang ou equivalente)
- Apenas tipos **int** e **string** (via `char*`) são utilizados
- Sem entrada do usuário; valores (nº de casas) definidos em constantes no código

---

## 🧩 O que está implementado

### Nível Novato
- **Torre**: `for` → 5 casas **Direita**
- **Bispo**: `while` → 5 casas na diagonal **Cima + Direita** (impresso como “Cima Direita” no básico)
- **Rainha**: `do-while` → 8 casas **Esquerda**

### Nível Aventureiro
- **Cavalo**: **loops aninhados** (`for` + `while`) → **2 Baixo, 1 Esquerda**, imprimindo:
  ```
  Baixo
  Baixo
  Esquerda
  ```

### Nível Mestre (este repositório)
- **Torre (recursivo)**: uma chamada por casa, imprime “Direita”.
- **Bispo (recursivo + loops aninhados)**: por **cada** casa diagonal, executa:
  - loop externo: 1 passo **Cima** (imprime “Cima”)
  - loop interno: 1 passo **Direita** (imprime “Direita”)
- **Rainha (recursivo)**: uma chamada por casa, imprime “Esquerda”.
- **Cavalo (loops complexos)**: “L” **2 Cima, 1 Direita** com **múltiplas variáveis/condições** no cabeçalho do loop, uso explícito de `continue`/`break`.

---

## 🏗️ Como compilar e executar

### Linux / macOS
```bash
gcc -Wall -Wextra -O2 xadrez_nivel_mestre.c -o xadrez_nivel_mestre
./xadrez_nivel_mestre
```

### Windows (MinGW)
```bat
gcc -Wall -Wextra -O2 xadrez_nivel_mestre.c -o xadrez_nivel_mestre.exe
xadrez_nivel_mestre.exe
```

---

## 🔧 Configuração (no código)

No topo do `main` você encontrará constantes que definem a quantidade de casas:

```c
const int passosTorreDireita   = 5;  // Torre
const int passosBispoDiag      = 5;  // Bispo (cada casa imprime "Cima" e "Direita")
const int passosRainhaEsquerda = 8;  // Rainha
```

> Ajuste esses valores conforme necessário para seus testes.  
> O Cavalo (nível mestre) é sempre **2 para Cima** e **1 para Direita**, conforme o enunciado.

---

## 🧠 Recursividade — Como foi aplicada

- **Torre** (`mover_torre_direita_rec`):  
  Caso base `passos <= 0`; caso recursivo: imprime “Direita” e chama com `passos - 1`.
- **Bispo** (`mover_bispo_cima_direita_rec`):  
  A **cada** chamada recursiva (uma casa diagonal), executa **loops aninhados**:
  - `for (v=0; v<1; v++) printf("Cima\n");`
  - `for (h=0; h<1; h++) printf("Direita\n");`
  Em seguida, chama a si mesmo com `passos - 1`.
- **Rainha** (`mover_rainha_esquerda_rec`):  
  Igual à Torre, imprimindo “Esquerda” por chamada.

> As profundidades são pequenas (5–8), portanto **sem risco de stack overflow**.

---

## 🐴 Cavalo — Loops aninhados complexos

A função do Cavalo usa:

- **Loop externo** para os segmentos do “L” (vertical e horizontal).
- **Loop interno** com **condições compostas** e **múltiplas variáveis** (contadores por direção, tentativa, etc.).
- **`continue`** para pular ciclos de “checagem” e **`break`** para encerrar segmentos quando atinge o número alvo de passos.

Movimento resultante:
```
Cima
Cima
Direita
```

---

## 🧪 Exemplo (trecho) de saída

```
Torre (recursivo) — 5 casas para a Direita:
Direita
Direita
Direita
Direita
Direita

Bispo (recursivo + loops aninhados) — 5 casas na diagonal Cima/Direita:
Cima
Direita
Cima
Direita
...

Rainha (recursivo) — 8 casas para a Esquerda:
Esquerda
Esquerda
...

Cavalo (loops aninhados + continue/break) — 2 para Cima e 1 para Direita:
Cima
Cima
Direita
```

---

## 📐 Complexidade

- Torre e Rainha (recursivos lineares): **O(n)**.
- Bispo (por casa: dois prints via loops unitários) ao longo de `n` casas: **O(n)**.
- Cavalo: número fixo de passos (3) → **O(1)**, com overhead de controle de fluxo.

---

## ✅ Conformidade com o enunciado

- **Entrada**: valores definidos no código (constantes).
- **Saída**: uma direção por linha; linhas em branco separam as peças.
- **Recursividade**: aplicada a Torre, Bispo e Rainha.
- **Loops aninhados (Bispo)**: externo vertical, interno horizontal, por **casa** diagonal.
- **Loops complexos (Cavalo)**: múltiplas variáveis/condições e uso de `continue`/`break`.
- **Legibilidade**: variáveis descritivas, comentários explicativos e indentação consistente.

---

## 🚀 Extensões sugeridas (opcional)

- Parametrizar direção/quantidade via `#define`.
- Adicionar “modo demonstração” para imprimir também coordenadas (mantendo as direções puras nas linhas exigidas).
- Menu simples para acionar peça por peça.

---

## 📝 Licença

Uso acadêmico/educacional. Sinta-se à vontade para adaptar para sua disciplina.
