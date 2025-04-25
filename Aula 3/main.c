#include <stdio.h>

int main() {
    int intNumerador, intDenominador;
    float floatNumerador, floatDenominador;
    
    // Entrada e cálculo da primeira divisão (inteiro / inteiro)
    printf("\nDigite o numerador inteiro: ");
    scanf("%d", &intNumerador);
    printf("Digite o denominador inteiro: ");
    scanf("%d", &intDenominador);
    int divisaoInt1 = intNumerador / intDenominador;
    float divisaoFloat1 = (float)intNumerador / intDenominador;
    printf("\n %d/%d = %d (int) | %.2f (float)", intNumerador, intDenominador, divisaoInt1, divisaoFloat1);
    
    // Entrada e cálculo da segunda divisão (float / float)
    printf("\n\nDigite o numerador racional: ");
    scanf("%f", &floatNumerador);
    printf("Digite o denominador racional: ");
    scanf("%f", &floatDenominador);
    int divisaoInt2 = (int)(floatNumerador / floatDenominador);
    float divisaoFloat2 = floatNumerador / floatDenominador;
    printf("\n %.2f/%.2f = %d (int) | %.2f (float)", floatNumerador, floatDenominador, divisaoInt2, divisaoFloat2);
    
    // Entrada e cálculo da terceira divisão (float / int)
    printf("\n\nDigite o numerador racional: ");
    scanf("%f", &floatNumerador);
    printf("Digite o denominador inteiro: ");
    scanf("%d", &intDenominador);
    int divisaoInt3 = (int)(floatNumerador / intDenominador);
    float divisaoFloat3 = floatNumerador / intDenominador;
    printf("\n %.2f/%d = %d (int) | %.2f (float)", floatNumerador, intDenominador, divisaoInt3, divisaoFloat3);
    
    // Entrada e cálculo da quarta divisão (int / float)
    printf("\n\nDigite o numerador inteiro: ");
    scanf("%d", &intNumerador);
    printf("Digite o denominador racional: ");
    scanf("%f", &floatDenominador);
    int divisaoInt4 = (int)(intNumerador / floatDenominador);
    float divisaoFloat4 = intNumerador / floatDenominador;
    printf("\n %d/%.2f = %d (int) | %.2f (float)\n", intNumerador, floatDenominador, divisaoInt4, divisaoFloat4);
    
    return 0;
}
