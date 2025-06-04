#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 256
#define MAX_SENSORES 10

typedef struct {
    long timestamp;
    char id_sensor[16];
    char valor[32];
} Leitura;

int comparar_por_timestamp(const void *a, const void *b) {
    return ((Leitura *)a)->timestamp - ((Leitura *)b)->timestamp;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (!entrada) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    Leitura leituras[10000];
    int total = 0;

    while (fscanf(entrada, "%ld %s %s", &leituras[total].timestamp, leituras[total].id_sensor, leituras[total].valor) == 3) {
        total++;
    }
    fclose(entrada);

    // Organiza os sensores em arquivos
    for (int i = 0; i < total; i++) {
        char nome_arquivo[32];
        sprintf(nome_arquivo, "%s.txt", leituras[i].id_sensor);

        // Abrir arquivo de sensor e carregar as leituras
        FILE *sensor_file = fopen(nome_arquivo, "a+");
        if (!sensor_file) continue;

        fprintf(sensor_file, "%ld %s %s\n", leituras[i].timestamp, leituras[i].id_sensor, leituras[i].valor);
        fclose(sensor_file);
    }

    // Reordenar arquivos por timestamp
    // (sugestão: para cada tipo de sensor identificado, ler de volta, ordenar com qsort, salvar ordenado)

    return 0;
}