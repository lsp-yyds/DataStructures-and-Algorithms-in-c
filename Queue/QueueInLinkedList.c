//
// Created by bruce on 8/25/22.
//

#include "QueueInLinkedList.h"
#include "../Fatal.h"

struct Node {
    ElementType element;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

bool isEmpty( Queue Q ) {
    return Q->rear == Q->front;
}

Queue createQueue() {
    Node P = malloc( sizeof( struct Node ) );
    if ( P == NULL )
        FatalError( "Out of space!!!" );
    P->next = NULL;

    Queue Q = malloc( sizeof( struct Queue ) );
    if ( Q == NULL )
        FatalError( "Out of space!!!" );
    Q->front = P;
    Q->rear = P;
    return Q;
}

void disposeQueue( Queue Q ) {
    if ( !isEmpty( Q ) )
        Dequeue( Q );
    free( Q );
}

void makeEmpty( Queue Q ) {
    while ( !isEmpty( Q ) )
        Dequeue( Q );
}

void Enqueue( Queue Q, ElementType value ) {
    Node TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );

    TmpCell->element = value;
    TmpCell->next = Q->rear->next;
    Q->rear->next = TmpCell;
    Q->rear = TmpCell;
}

ElementType front( Queue Q ) {
    return Q->front->next->element;
}

void Dequeue( Queue Q ) {
    Node P;
    if ( isEmpty( Q ) )
        Error( "Empty queue!!!" );

    P = Q->front->next;
    if ( P == Q->rear ) {
        Q->rear = Q->front;
        free( P );
    } else {
        Q->front->next = P->next;
        free( P );
    }
}

ElementType frontAndDequeue( Queue Q ) {
    ElementType TmpCell;
    TmpCell = front( Q );
    Dequeue( Q );
}

void printQueue( Queue Q ) {
    Node P;
    P = Q->front->next;
    printf( "<-- " );
    while ( P != Q->rear ) {
        printf( "%d ", P->element );
        P = P->next;
    }
    printf( "%d <--", P->element );
    printf( "\n" );
}

int length( Queue Q ) {
    int count;
    Node P;

    count = 0;
    P = Q->front->next;
    while ( P != NULL ) {
        count++;
        P = P->next;
    }

    return count;
}

int main() {
    Queue Q = createQueue();
    for ( int i = 0; i < 5; ++i ) {
        Enqueue( Q, i );
    }
    printQueue( Q );
    Dequeue( Q );
    printQueue( Q );
    printf( "%d", length( Q ) );
    return 0;
}