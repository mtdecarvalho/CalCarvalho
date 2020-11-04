#! /bin/bash

gcc -c src/util.c -Iinc -o obj/util.o
gcc -c src/operacoes.c -Iinc -o obj/operacoes.o
gcc -c src/menu.c -Iinc -o obj/menu.o
gcc -c src/main.c -Iinc -o obj/main.o

gcc obj/util.o obj/operacoes.o obj/menu.o obj/main.o -o calcarvalho
