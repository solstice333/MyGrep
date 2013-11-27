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

void clear(LinkedList *list) {
   delete(list->head);
}

void delete(Node *n) {
   if (n) {
      delete(n->next);
      free(n->o.line);
      free(n);
   }
}

void print(LinkedList *list) {
   Node *n = list->head;

   while (n != NULL) {
      printf("lineNum: %d, length: %d, line: %s\n", n->o.lineNum, n->o.length,
            n->o.line);
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

   char *file = argv[1];
   char *search = argv[2];
   FILE *ifs = fopen(file, "r");

   // print header - executable filepath, input file, search word
   printf("%s %s %s\n", argv[0], file, search);

   // exit if bad file connection
   if (!ifs) {
      printf("Error: Could not connect to file for reading. Exiting...\n");
      return EXIT_FAILURE;
   }

   // store lines into linked list
   Sentence *s;
   Node *n;

   LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
   createLinkedList(ll);

   char *line = (char*) malloc(100 * sizeof(char));
   int lineCount = 0;
   int max = 0;

   while (fgets(line, 100, ifs) != NULL) {
      s = (Sentence*) malloc(sizeof(Sentence));

      // if not the last line
      if (!feof(ifs)) {
         s->length = strlen(line) - 1;
         s->line = line;
         line = (char*) malloc(100 * sizeof(char));
      }

      // if last line
      else {
         s->length = strlen(line);
         s->line = line;
      }

      // track the longest line
      if (s->length > max)
         max = s->length;

      s->lineNum = ++lineCount;
      n = createNode(s);
      push_back(ll, n);
   }

   // look for the longest line and print - O(n^2) solution easiest to implement
   // could go for priority queue at O(1 + n*log(n)). BST would be O((n + 1)*log(n))
   // which is a bit slower than priority queue. Can also use rewind() for this
   n = ll->head;
   while (n) {
      if (n->o.length == max) {
         printf("longest line: %s", n->o.line);

         if (n->o.lineNum == lineCount)
            printf("\n");

         printf("num chars: %d\n", n->o.length);
         printf("num lines: %d\n", lineCount);
         break;
      }

      n = n->next;
   }

   return EXIT_SUCCESS;

}
