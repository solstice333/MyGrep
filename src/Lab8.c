/*
 ============================================================================
 Name        : Lab8.c
 Author      : Casey Wu and Kevin Navero
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   printf("argc: %d\n", argc);

   int i = 0;
   for (i = 0; i < argc; i++) {
      printf("argument %d: %s\n", i, argv[i]);
   }

   return EXIT_SUCCESS;
}
