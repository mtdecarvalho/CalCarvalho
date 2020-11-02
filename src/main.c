#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "operacoes.h"
#include "util.h"

int main ()
{
    int k;
    double res, n1, n2;
    do {
        
        limpartela();
        printf(
            "\t############################\n"
            "\t# Bem vindo a CalCarvalho! #\n"
            "\t############################\n"
            "\t# 1 #          Soma        #\n"
            "\t# 2 #       Subtracao      #\n"
            "\t# 3 #      Multiplicacao   #\n"
            "\t# 4 #        Divisao       #\n"
            "\t# 0 #          Sair        #\n"
            "\t############################\n");
        scanf(" %d", &k);
        switch (k)
        {
            case 1: input(&n1, &n2); soma(n1, n2, &res);
                    printf("\n%.2lf + %.2lf = %.2lf\n\n", n1, n2, res); limpa(); break;
            case 2: input(&n1, &n2); subtracao(n1, n2, &res);
                    printf("\n%.2lf - %.2lf = %.2lf\n\n", n1, n2, res); limpa(); break;
            case 3: input(&n1, &n2); multiplicacao(n1, n2, &res);
                    printf("\n%.2lf * %.2lf = %.2lf\n\n", n1, n2, res); limpa(); break;
            case 4: 
                do { input(&n1, &n2); if (n2 == 0) printf("\nO divisor nao pode ser igual a 0.\n"); } while (n2 == 0);
                divisao(n1, n2, &res); printf("\n%.2lf / %.2lf = %.2lf\n\n", n1, n2, res); limpa(); break;
            case 0: break;
            default: printf("\n%d nao eh uma operacao valida. Tente novamente.\n\n", k); break;
        }
        if (k != 0) pausartela();
        else printf("Encerrando CalCarvalho...\n\n");

    } while (k != 0);

    return 0;
}