//
// Created by bruce on 8/24/22.
//

#include "StackInLinkedList.h"
#include "../Fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    struct Node *next;
};

bool isEmpty( Stack S ) {
    return S->next == NULL;
}

Stack createStack() {
    Stack S;

    S = malloc( sizeof( struct Node ) );
    if ( S == NULL )
        FatalError( "Out of space!!!" );
    S->next = NULL;
    makeEmpty( S );
    return S;
}

void disposeStack( Stack S ) {
    if ( S != NULL ) {
        makeEmpty( S );
        free( S );
    }
}

void makeEmpty( Stack S ) {
    if ( S == NULL )
        Error( "Must use createStack first!!!" );
    else
        while ( !isEmpty( S ) )
            pop( S );
}

void push( Stack S, ElementType value ) {
    PtrToNode TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    else {
        TmpCell->element = value;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

ElementType top( Stack S ) {
    if ( isEmpty( S ) )
        Error( "Empty Stack!!!" );
    else
        return S->next->element;
}

void pop( Stack S ) {
    PtrToNode FirstCell;

    if ( isEmpty( S ) )
        Error( "Empty Stack!!!" );
    else {
        FirstCell = S->next;
        S->next = FirstCell->next;
        free( FirstCell );
    }
}

void printStack( Stack S ) {
    PtrToNode Tmp;
    Tmp = S->next;
    while ( Tmp != NULL ) {
        printf( "|   %d   |\n", Tmp->element );
        printf( "---------\n" );
        Tmp = Tmp->next;
    }
    printf( "\n" );
}

int main() {
    Stack S = createStack();
    for ( int i = 0; i < 5; ++i ) {
        push( S, i );
    }
    printStack( S );
    pop( S );
    printStack( S );
    printf( "%d\n", top( S ) );

    return 0;
}