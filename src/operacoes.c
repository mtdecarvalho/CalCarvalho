#include "operacoes.h"

#include <stdio.h>

double input (double * a, double * b)
{
    double n1, n2;
    printf("\nInsira o primeiro valor: ");
    scanf(" %lf", &n1);
    printf("Insira o segundo valor: ");
    scanf(" %lf", &n2);
    *a = n1; *b = n2;
}

void soma (double a, double b, double * x)
{
    *x = a + b;
    //*x = res;
} 

void subtracao (double a, double b, double * x)
{
    *x = a - b;
    //*x = res;
} 

void multiplicacao (double a, double b, double * x)
{
    *x = a * b;
    //*x = res;
} 

void divisao (double a, double b, double * x)
{
    *x = a / b;
}