#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long timestamp;
    char valor[32];
} Leitura;

long diferenca(long a, long b) {
    return labs(a - b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <ID_SENSOR> <TIMESTAMP>\n", argv[0]);
        return 1;
    }

    char nome_arquivo[64];
    sprintf(nome_arquivo, "%s.txt", argv[1]);
    long alvo = atol(argv[2]);

    FILE *f = fopen(nome_arquivo, "r");
    if (!f) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    Leitura *leituras = malloc(sizeof(Leitura) * 10000);
    int total = 0;
    long ts;
    char sensor[16], valor[32];

    while (fscanf(f, "%ld %s %s", &ts, sensor, valor) == 3) {
        leituras[total].timestamp = ts;
        strcpy(leituras[total].valor, valor);
        total++;
    }
    fclose(f);

    // Busca binária
    int ini = 0, fim = total - 1, melhor = -1;
    long menor_diff = 9999999999;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        long diff = diferenca(leituras[meio].timestamp, alvo);
        if (diff < menor_diff) {
            melhor = meio;
            menor_diff = diff;
        }
        if (leituras[meio].timestamp < alvo)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    if (melhor != -1) {
        printf("Mais próximo: %ld %s %s\n", leituras[melhor].timestamp, argv[1], leituras[melhor].valor);
    } else {
        printf("Leitura não encontrada.\n");
    }

    free(leituras);
    return 0;
}