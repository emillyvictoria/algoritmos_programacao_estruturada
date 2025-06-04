#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long gerar_timestamp_aleatorio(long inicio, long fim) {
    return inicio + rand() % (fim - inicio + 1);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Uso: %s <AAAA-MM-DD:HH:MM:SS_inicio> <AAAA-MM-DD:HH:MM:SS_fim> <arquivo_saida> <SENSORES...>\n", argv[0]);
        return 1;
    }

    struct tm t_ini = {0}, t_fim = {0};
    sscanf(argv[1], "%d-%d-%d:%d:%d:%d", &t_ini.tm_year, &t_ini.tm_mon, &t_ini.tm_mday,
           &t_ini.tm_hour, &t_ini.tm_min, &t_ini.tm_sec);
    sscanf(argv[2], "%d-%d-%d:%d:%d:%d", &t_fim.tm_year, &t_fim.tm_mon, &t_fim.tm_mday,
           &t_fim.tm_hour, &t_fim.tm_min, &t_fim.tm_sec);
    t_ini.tm_year -= 1900; t_ini.tm_mon -= 1;
    t_fim.tm_year -= 1900; t_fim.tm_mon -= 1;

    time_t ini_ts = mktime(&t_ini);
    time_t fim_ts = mktime(&t_fim);

    FILE *saida = fopen(argv[3], "w");
    if (!saida) {
        perror("Erro ao criar arquivo");
        return 1;
    }

    srand(time(NULL));
    for (int s = 4; s < argc; s++) {
        for (int i = 0; i < 2000; i++) {
            long ts = gerar_timestamp_aleatorio(ini_ts, fim_ts);
            float valor = (rand() % 10000) / 100.0;
            fprintf(saida, "%ld %s %.2f\n", ts, argv[s], valor);
        }
    }

    fclose(saida);
    printf("Arquivo gerado com sucesso.\n");
    return 0;
}