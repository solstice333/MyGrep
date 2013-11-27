/*
 * myGrep.h
 *
 *  Created on: Nov 25, 2013
 *      Author: knavero
 */

#ifndef MYGREP_H_
#define MYGREP_H_

// This struct is user defined. The idea here is to make Node (see below) flexible to
// any type of data containment
typedef struct Sentence {
   int lineNum;
   int length;
   char *line;
   int word[100];
   int appearances;
} Object, Sentence;

Sentence* createSentence(Sentence *s);
void deleteObject(Sentence *s);  // This needs to be named "deleteObject"

// basic Node of a linked list
typedef struct Node {
   Object *o;
   struct Node *prev;
   struct Node *next;
} Node;

Node* createNode(Object *o);
void deleteNode(Node *n);

// linked list data structure
typedef struct LinkedList {
   Node *head;
   Node *tail;
   int size;
} LinkedList;

LinkedList* createLinkedList(LinkedList* list);
void push_back(LinkedList *list, Node *n);
void deleteLinkedList(LinkedList *list);
void print(LinkedList *list);

#endif /* MYGREP_H_ */
