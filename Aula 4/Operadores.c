#include <stdio.h>

int main()
{

    float a;
    float b;
    int operacao;

    printf("\nDigite o valor de A: ");
    scanf("%f", &a);
    printf("\nDigite o valor de B: ");
    scanf("%f", &b);
    printf("\nDigite o tipo de operacao que deseja fazer: \n 1-soma\n 2-sub\n 3-mult\n 4-div\n 5-mod\n");
    scanf("%d", &operacao);

    float resultadoSoma = a+b;
    float resultadoSub = a-b;
    float resultadoMult = a*b;
    float resultadoDiv = a/b;
    int ResultadoMod;
    int intA;
    int intB;

    switch (operacao)
    {
    case 1:
        printf("\nO resultado da soma de %f + %f e igual a: %f", a, b, resultadoSoma);
    break;
    case 2:
        printf("\nO resultado da subtracao de %f - %f e igual a: %f", a, b, resultadoSub);
    break;
    case 3:
        printf("\nO resultado da multiplicacao de %f x %f e igual a: %f", a, b, resultadoMult);
    break;
    case 4:
        printf("\nO resultado da divisao de %f / %f e igual a: %f", a, b, resultadoDiv);
    break;
    case 5:
        intA = (int) a;
        intB = (int) b;
        ResultadoMod = intA%intB;
        printf("\nO resultado do resto da divisao de %d %% %d e igual a: %d", intA, intB, ResultadoMod);
    break;
    default:
        printf("Saindo");
        break;
    }
    return 0;
}