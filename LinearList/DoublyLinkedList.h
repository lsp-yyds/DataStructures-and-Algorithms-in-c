//
// Created by bruce on 8/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H

#include <stdbool.h>

typedef int ElementType;
typedef struct Node {
    ElementType element;
    struct Node *next, *prior;
};
typedef struct Node *PtrToNode;
typedef PtrToNode DLinkedList;
typedef PtrToNode Position;

DLinkedList makeEmpty( DLinkedList L );
bool isEmpty( DLinkedList L );
bool isLast( DLinkedList L, Position P );
Position find( DLinkedList L, ElementType value );
void delete ( DLinkedList L, ElementType value );
Position findPrevious( DLinkedList L, ElementType value );
void insert( DLinkedList L, Position P, ElementType value );
void deleteList( DLinkedList L );
Position header( DLinkedList L );
Position first( DLinkedList L );
Position advance( Position P );
ElementType retrieve( Position P );
int length( DLinkedList L );
void printList( DLinkedList L );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H
