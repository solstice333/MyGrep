/*
 * myGrep.h
 *
 *  Created on: Nov 25, 2013
 *      Author: Casey Wu and Kevin Navero
 */

#ifndef MYGREP_H_
#define MYGREP_H_

/*
 * Description: This struct is an example of a user-defined data type to be used
 * with the generic linked list below in which this Object would be wrapped within
 * Node. The idea here is to make Node (see below) flexible to any type
 * of data containment. This struct contains the following members:
 * (1) lineNum - the line number in the input file
 * (2) length - the length of the line in characters
 * (3) line - the content of that line i.e. the string
 * (4) word - an array containing the positions (as integers) within the line
 * (5) appearances - number of occurrences of the search word within the line
 */
typedef struct Sentence {
   int lineNum;
   int length;
   char *line;
   int word[100];
   int appearances;
} Object, Sentence;

/*
 * Description: createSentence is a factory function for creating a Sentence instance
 * Parameter: Sentence *s is a pointer to an uninitialized Sentence instance
 * Return: an initialized Sentence pointer
 */
Sentence* createSentence(Sentence *s);

/*
 * Description: deleteObject is the deconstruction/teardown of a Sentence instance. This
 * must be named deleteObject in order to be compatible with deleteNode()
 * Parameter: Sentence *s the Sentence instance to destroy and send back to heap
 */
void deleteObject(Sentence *s);  // This needs to be named "deleteObject"

/*
 * Description: Generic Node wrapper for a user-defined Object. This struct follows
 * the basic requirements for a node within a doubly linked list - (1) the data it contains
 * i.e. within the Object being pointed to, (2) a previous and a (3) next pointer to
 * another Node or NULL if at the head or tail respectively
 */
typedef struct Node {
   Object *o;
   struct Node *prev;
   struct Node *next;
} Node;

/*
 * Description: createNode is a factory function for creating a Node instance
 * Parameter: Object *o is the data intended to be wrapped within the Node wrapper
 * Return: initialized Node instance
 */
Node* createNode(Object *o);

/*
 * Description: deleteNode is the teardown/destruction of a Node instance
 * Parameter: Node *n is the node to destroy and send back to heap
 */
void deleteNode(Node *n);

/*
 * Description: LinkedList is a list containing a series of nodes pointing to each
 * other for a O(1) constant time push_back
 */
typedef struct LinkedList {
   Node *head;
   Node *tail;
   int size;
} LinkedList;

/*
 * Description: factory function for creating a LinkedList instance
 * Parameter: LinkedList* list is a pointer to an uninitialized LinkedList instance
 * Return: initialized instance of a LinkedList
 */
LinkedList* createLinkedList(LinkedList* list);

/*
 * Description: push_back appends a Node to the end of the list
 * Parameter: LinkedList *list is the list of choice to attach the node to the end of
 * i.e. the "this" list in an Object Oriented Programming design pattern
 * Parameter: Node *n is the node intended to be appended to the end of the list
 */
void push_back(LinkedList *list, Node *n);

/*
 * Description: deleteLinkedList destroys a LinkedList and sends it back to heap
 * Parameter: LinkedList *list is the linked list to destroy
 */
void deleteLinkedList(LinkedList *list);

/*
 * Description: print is for debugging purposes. Prints out all the items contained
 * within the LinkedList (must use with Sentence instance)
 * Parameter: LinkedList *list is the list to print out the elements of
 */
void print(LinkedList *list);

#endif /* MYGREP_H_ */
