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
   int line;
   int length;
} Object, Sentence;

// basic Node of a linked list
typedef struct Node {
   Object o;
   struct Node *prev;
   struct Node *next;
} Node;

// linked list data structure
typedef struct LinkedList {
   Node *head;
   Node *tail;
} LinkedList;

LinkedList* createLinkedList(LinkedList* list);
Node* createNode(Object *o);
void push_back(LinkedList *list, Node *n);

// TODO clean up memory
//void clear(LinkedList *list);

void print(LinkedList *list);

#endif /* MYGREP_H_ */
