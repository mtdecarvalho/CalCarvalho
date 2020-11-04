#include "menu.h"
#include "util.h"
#include <stdio.h>


#if defined(_WIN32) || defined(_WINDOWS)
#include <conio.h>
#else
#include <termios.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
tcgetattr(0, &old); /* grab old terminal i/o settings */
current = old; /* make new settings same as old settings */
current.c_lflag &= ~ICANON; /* disable buffered i/o */
if (echo) {
   current.c_lflag |= ECHO; /* set echo mode */
} else {
   current.c_lflag &= ~ECHO; /* set no echo mode */
}
tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
char ch;
initTermios(echo);
ch = getchar();
resetTermios();
return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
return getch_(0);
}
#endif

int lerTecla()
{
   return getch();
}

int menu()
{
   char tecla;
   int i, opc=0, opcant=-1, qtd=5, tam;
   char opcoes [][15] = {"Soma", "Subtracao", "Multiplicacao", "Divisao", "Sair"};
   do
   {
      limpartela();
      printf(
      "\t      Bem vindo a CalCarvalho 2.0!\n"
      "\t  Agora com 100%% mais interatividade!\n"
      "\t+------------------------------------+\n");
      for (i = 0 ; i < qtd ; i++)
      {  
         printf("\t|");
         printf("%s %s", (opc==i)? " > ":"   ", opcoes[i]);
         tam = strlen(opcoes[i]) + 3 + 4;
         while (tam < 39)
         {   printf(" "); if (tam == 38) printf("|\n"); tam++; }
         tam = 0;
         if (i == qtd-1) printf("\t+------------------------------------+\n");
      }
      printf("\t     Use W e S para mover o cursor.\n");
      tecla = lerTecla(); opcant = opc;
      switch(tecla)
      {
         case 'w': case 'W': opc--;
                  if (opc<0) opc = qtd-1;
                  break; 
         case 's': case 'S': opc++;
                  if (opc>=qtd) opc = 0;
                  break; 
      }
   } while (tecla != 32);
   if (tecla == 27 || opc == qtd-1)
      return 0;
   else 
      return opc+1;
}