#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "operacoes.h"
#include "util.h"
#include "menu.h"

int main ()
{
    int k = 1;
    double res, n1, n2;
    do {
        
        limpartela();
        switch ( menu() )
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
            case 0: k = 0; break;
            default: printf("\n%d nao eh uma operacao valida. Tente novamente.\n\n", k); break;
        }
        if (k != 0) pausartela();
        else printf("\nEncerrando CalCarvalho...\n\n");

    } while (k != 0);

    return 0;
}