//
// Created by bruce on 8/22/22.
//
#include "DoublyLinkedList.h"
#include "../Fatal.h"
#include <stdlib.h>

DLinkedList makeEmpty( DLinkedList L ) {
    L->prior = NULL;
    L->next = NULL;
}

bool isEmpty( DLinkedList L ) {
    return L->next == NULL;
}

bool isLast( DLinkedList L, Position P ) {
    return P->next == NULL;
}

Position find( DLinkedList L, ElementType value ) {
    Position P;

    P = L->next;

    while ( P != NULL && P->element != value )
        P = P->next;

    return P;
}
void delete ( DLinkedList L, ElementType value );
Position findPrevious( DLinkedList L, ElementType value );
void insert( DLinkedList L, Position P, ElementType value ) {
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->element = value;
    TmpCell->next = P->next;
    P->next->prior = TmpCell;
    P->next = TmpCell;
    TmpCell->prior = P;
}
void deleteList( DLinkedList L );
Position header( DLinkedList L ) {
    return L;
}
Position first( DLinkedList L ) {
    return L->next;
}
Position advance( Position P ) {
    return P->next;
}

Position retreat( Position P ) {
    return P->prior;
}

ElementType retrieve( Position P ) {
    return P->element;
}
int length( DLinkedList L ) {
    int count;
    Position P;

    count = 0;
    P = L->next;
    while ( P != NULL ) {
        P = P->next;
        count++;
    }

    return count;
}
void printList( DLinkedList L );