#include <stdio.h>

int main() {
    int a, b, operacao;
    
    printf("\nDigite o valor de A: ");
    scanf("%d", &a);
    printf("\nDigite o valor de B: ");
    scanf("%d", &b);

    printf("\nEscolha a operacao que deseja realizar:\n");
    printf("1 - AND (a & b)\n");
    printf("2 - OR (a | b)\n");
    printf("3 - XOR (a ^ b)\n");
    printf("4 - Inversao (~a)\n");
    scanf("%d", &operacao);
    
    switch (operacao) {
        case 1:
            printf("\nO resultado de %d & %d = %d\n", a, b, a & b);
            break;
        case 2:
            printf("\nO resultado de %d | %d = %d\n", a, b, a | b);
            break;
        case 3:
            printf("\nO resultado de %d ^ %d = %d\n", a, b, a ^ b);
            break;
        case 4:
            printf("\nO resultado da inversao de %d (~a) = %d\n", a, ~a);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
    }
    
    return 0;
}
