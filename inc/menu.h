#ifndef MENU_H
#define MENU_H

#include "util.h"
#include <stdio.h>

#if defined(_WIN32) || defined(_WINDOWS)
#include <conio.h>
#else
#include <termios.h>
static struct termios old, current;
/* Initialize new terminal i/o settings */
void initTermios(int echo);
/* Restore old terminal i/o settings */
void resetTermios(void);
/* Read 1 character - echo defines echo mode */
char getch_(int echo);
/* Read 1 character without echo */
char getch(void);
#endif

int lerTecla();

int menu();

#endif