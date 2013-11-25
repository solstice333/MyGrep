/*
 ============================================================================
 Name        : myGrep.c
 Author      : Casey Wu and Kevin Navero
 Version     :
 Copyright   : 
 Description : grep (Globally search a Regular Expression and Print) implementation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#define PRINT_ARGS 0

int main(int argc, char* argv[]) {
   // check argument count and error check
   if (argc != 3) {
      printf("Error: Wrong number of arguments.\n"
            "Try: ./a.out <input file> <search word>\n"
            "For example: ./a.out input.txt the\n"
            "Exiting...");

      return 1;
   }

   // if argument count is correct perform grep
   else {
#if PRINT_ARGS
      printf("Argument count successful! Echo here!\n");
      printf("argc: %d\n", argc);

      int i = 0;
      for (i = 0; i < argc; i++) {
         printf("argument %d: %s\n", i, argv[i]);
      }
#endif
      char *file = argv[1];
      char *search = argv[2];

      FILE *ifstream = fopen(file, "r");

      if (!ifstream) {
         printf("Error: Could not connect to file for reading. Exiting...");
         return 1;
      }

      return 0;

   }

}
