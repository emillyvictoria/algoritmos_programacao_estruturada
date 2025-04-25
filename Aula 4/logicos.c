#include <stdio.h>

int main() {
    int a, b, operacao;
    
    printf("\nDigite o valor de A (0 ou 1): ");
    scanf("%d", &a);
    printf("\nDigite o valor de B (0 ou 1): ");
    scanf("%d", &b);
    
    printf("\nEscolha a operacao logica:\n");
    printf("1 - AND (a && b)\n");
    printf("2 - OR (a || b)\n");
    printf("3 - NEGAÇÃO (!a)\n");
    scanf("%d", &operacao);
    
    switch (operacao) {
        case 1:
            printf("\n%d && %d : %s\n", a, b, (a && b) ? "Verdadeiro" : "Falso");
            break;
        case 2:
            printf("\n%d || %d : %s\n", a, b, (a || b) ? "Verdadeiro" : "Falso");
            break;
        case 3:
            printf("\n!%d : %s\n", a, (!a) ? "Verdadeiro" : "Falso");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
    }
    
    return 0;
}
