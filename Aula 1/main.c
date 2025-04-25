#include <stdio.h>
#include <stdbool.h>

int main () 
{

    int varint = 0 ;
    float varfloat = 1.1;
    double vardouble = 5.6;
    char varchar = 'Emilly';
    bool varbool = true;

    printf("\n O tamanho de uma variavel do tipo int eh: %d", sizeof(int));
    printf("\n O tamanho de uma variavel do tipo float eh: %d", sizeof(float));
    printf("\n O tamanho de uma variavel do tipo double eh: %d", sizeof(double));
    printf("\n O tamanho de uma variavel do tipo char eh: %d", sizeof(char));
    printf("\n O tamanho de uma variavel do tipo bool eh: %d", sizeof(bool));
    printf("\n O tamanho de uma variavel do tipo longint eh: %d", sizeof(long));
    printf("\n O tamanho de uma variavel do tipo shortint eh: %d", sizeof(short));
    printf("\n O tamanho de uma variavel do tipo unsigned eh: %d", sizeof(unsigned));

    return 0;
}