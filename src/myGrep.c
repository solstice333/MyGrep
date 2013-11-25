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
   if (argc != 4) {
      printf("Error: Wrong number of arguments.\n"
            "Try: a.out <input file> <search word>\n"
            "For example: a.out input.txt the\n");

      return 1;
   }

   else {
      printf("Argument count successful! Echo here!\n");
      printf("argc: %d\n", argc);

      int i = 0;
      for (i = 0; i < argc; i++) {
         printf("argument %d: %s\n", i, argv[i]);
      }

      return 0;

   }

}
