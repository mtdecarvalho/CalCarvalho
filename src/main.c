#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "operacoes.h"
#include "util.h"

int main ()
{
    int k;
    double res, *a, *b, n1, n2;
    do {
        
        limpartela();
        printf("\t--------------------------\n"
            "\t|Bem vindo a CalCarvalho!|\n"
            "\t--------------------------\n"
            "\t| 1 |        Soma        |\n"
            "\t| 2 |     Subtracao      |\n"
            "\t| 3 |    Multiplicacao   |\n"
            "\t| 4 |      Divisao       |\n"
            "\t| 0 |        Sair        |\n"
            "\t--------------------------\n");
        scanf(" %d", &k);
        switch (k)
        {
            case 1: input(&n1, &n2); soma(n1, n2, &res); printf("\nResultado: %.2lf\n\n", res); limpa(); break;
            case 2: input(&n1, &n2); subtracao(n1, n2, &res); printf("\nResultado: %.2lf\n\n", res); limpa(); break;
            case 3: input(&n1, &n2); multiplicacao(n1, n2, &res); printf("\nResultado: %.2lf\n\n", res); limpa(); break;
            case 4: input(&n1, &n2); divisao(n1, n2, &res); printf("\nResultado: %.2lf\n\n", res); limpa(); break;
            case 0: break;
            default: printf("%d nao eh uma operacao valida. Tente novamente.\n", k); break;
        }
        if (k != 0) pausartela();
        else printf("Encerrando CalCarvalho...\n");

    } while (k != 0);

    return 0;
}