#include <stdio.h>

int main() {
    int a, b, operacao;
    

    printf("\nDigite o valor de A: ");
    scanf("%d", &a);
    printf("\nDigite o valor de B: ");
    scanf("%d", &b);

    printf("\nEscolha a operacao de comparacao:\n");
    printf("1 - IGUAL (a == b)\n");
    printf("2 - MAIOR (a > b)\n");
    printf("3 - MAIOR OU IGUAL (a >= b)\n");
    printf("4 - MENOR (a < b)\n");
    printf("5 - MENOR OU IGUAL (a <= b)\n");
    printf("6 - DIFERENTE (a != b)\n");
    scanf("%d", &operacao);
    
    switch (operacao) {
        case 1:
            printf("\n%d == %d : %s\n", a, b, (a == b) ? "Verdadeiro" : "Falso");
            break;
        case 2:
            printf("\n%d > %d : %s\n", a, b, (a > b) ? "Verdadeiro" : "Falso");
            break;
        case 3:
            printf("\n%d >= %d : %s\n", a, b, (a >= b) ? "Verdadeiro" : "Falso");
            break;
        case 4:
            printf("\n%d < %d : %s\n", a, b, (a < b) ? "Verdadeiro" : "Falso");
            break;
        case 5:
            printf("\n%d <= %d : %s\n", a, b, (a <= b) ? "Verdadeiro" : "Falso");
            break;
        case 6:
            printf("\n%d != %d : %s\n", a, b, (a != b) ? "Verdadeiro" : "Falso");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
    }
    
    return 0;
}
