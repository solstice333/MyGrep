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
#include <string.h>
#include "myGrep.h"

#define DEBUG 1

LinkedList* createLinkedList(LinkedList *list) {
   list->head = list->tail = NULL;
   return list;
}

Node* createNode(Object *o) {
   Node *n = (Node*) malloc(sizeof(Node));
   n->next = n->prev = NULL;
   n->o = *o;

   return n;
}

void push_back(LinkedList *list, Node *n) {
   if (!list->head)
      list->head = list->tail = n;

   else {
      list->tail->next = n;
      n->prev = list->tail;
      list->tail = list->tail->next;
   }
}

void print(LinkedList *list) {
   Node *n = list->head;

   while(n != NULL) {
      printf("line: %d, length: %d\n", n->o.line, n->o.length);
      n = n->next;
   }
}

int main(int argc, char* argv[]) {
   if (argc != 3) {
      printf("Error: Wrong number of arguments.\n"
            "Try: ./a.out <input file> <search word>\n"
            "For example: ./a.out input.txt the\n"
            "Exiting...");

      return EXIT_FAILURE;
   }

   else {
      char *file = argv[1];
      char *search = argv[2];
      FILE *ifs = fopen(file, "r");

      printf("%s %s %s\n", argv[0], file, search);

      if (!ifs) {
         printf("Error: Could not connect to file for reading. Exiting...\n");
         return EXIT_FAILURE;
      }

      char line[100];
      int lineCount = 0;

      while (fgets(line, 100, ifs) != NULL) {
         if (!feof(ifs))
            printf("line %d: %s and is %d characters long\n\n",
                  ++lineCount, line, strlen(line) - 1);


         else
            printf("line %d: %s\n and is %d characters long\n",
                  ++lineCount, line, strlen(line));
      }




      // TODO integrate the code below into the actual sentence parsing
      // and file i/o logic above
      Sentence *s1 = (Sentence*)malloc(sizeof(Sentence));
      s1->length = 3;
      s1->line = 1;

      Sentence *s2 = (Sentence*)malloc(sizeof(Sentence));
      s2->length = 4;
      s2->line = 5;

      Node *n1 = createNode(s1);
      Node *n2 = createNode(s2);

      LinkedList *ll = (LinkedList*)malloc(sizeof(LinkedList));
      createLinkedList(ll);

      push_back(ll, n1);
      push_back(ll, n2);

      printf("\n\nLinkedList test: \n");
      print(ll);





      return EXIT_SUCCESS;

   }

}
