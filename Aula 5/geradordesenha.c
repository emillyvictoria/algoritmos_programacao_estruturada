#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SORTEIO_MIN ('a')
#define SORTEIO_MAX ('z')
#define SORTEIO() (rand() % (SORTEIO_MAX - SORTEIO_MIN + 1) + SORTEIO_MIN)
#define MAX_PW_SIZE 32

int main(int argc, char *argv[])
{
    int tamanho = 0;
    char check[MAX_PW_SIZE + 1];
    char pw[MAX_PW_SIZE + 1];
    int i;

    srand(time(NULL));

    if (argc > 2)
    {
        puts("Informe o tamanho da senha na linha de comando:");
        return -1;  
    }


    tamanho = atoi(argv[1]);

    if (tamanho <= 0)
    {
        puts("O tamanho da senha deve ser positivo e maior que zero");
        return -1;
    }

    if (tamanho > MAX_PW_SIZE)
    {
        puts("O tamanho maximo da senha deve ser 32");
        return -1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        pw[i] = SORTEIO();
    }
    pw[tamanho] = '\0';
    puts(pw);

    puts("Digite a senha gerada: ");

    fflush(stdin);
    fgets(check, MAX_PW_SIZE + 1, stdin);

    int len = strlen(check);
    check[len-1]= '\0';

    printf("Tamanho de check: %d\r\n", len);

    if (strncmp(pw,check,sizeof(pw))==0)
    {
       puts("Confirmado!");
    } else {
        puts("Negado!");
    }

    return 0;
}