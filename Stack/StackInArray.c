//
// Created by bruce on 8/24/22.
//

#include "StackInArray.h"
#include "../Fatal.h"
#include <stdio.h>

#define emptyTOS ( -1 )
#define minStackSize ( 5 )

struct StackRecord {
    int capacity;
    int topOfStack;
    ElementType *element;
};

bool isEmpty( Stack S ) {
    return S->topOfStack == emptyTOS;
}

bool isFull( Stack S ) {
    return S->topOfStack == S->capacity - 1;
}

Stack createStack( int maxElements ) {
    Stack S;
    if ( maxElements < minStackSize )
        Error( "Stack size is too small!!!" );

    S = malloc( sizeof( struct StackRecord ) );
    if ( S == NULL )
        FatalError( "Out of space!!!" );

    S->element = malloc( sizeof( ElementType ) * maxElements );
    if ( S->element == NULL )
        FatalError( "Out of space!!!" );
    S->capacity = maxElements;
    makeEmpty( S );

    return S;
}

void disposeStack( Stack S ) {
    if ( S != NULL ) {
        free( S->element );
        free( S );
    }
}

void makeEmpty( Stack S ) {
    S->topOfStack = emptyTOS;
}

void push( Stack S, ElementType value ) {
    if ( isFull( S ) )
        Error( "Full stack!!!" );
    else
        S->element[ ++S->topOfStack ] = value;
}

ElementType top( Stack S ) {
    if ( isEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        return S->element[ S->topOfStack ];
}

void pop( Stack S ) {
    if ( isEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        S->topOfStack--;
}

ElementType topAndPop( Stack S ) {
    if ( isEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        return S->element[ S->topOfStack-- ];
}

void printStack( Stack S ) {
    for ( int i = S->topOfStack; i > emptyTOS; i-- ) {
        printf( "|   %d   |\n", S->element[ i ] );
        printf( "---------\n" );
    }
    printf( "\n" );
}

int main() {
    Stack S = createStack( 10 );
    makeEmpty( S );
    for ( int i = 0; i < 5; ++i ) {
        push( S, i );
    }
    printStack( S );
    pop( S );
    printStack( S );

    return 0;
}