//
// Created by bruce on 8/29/22.
//

#include "../Fatal.h"
#include "StackInArray.h"
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

bool bracketCheck( char str[], int length ) {
    Stack S = createStack( length / 2 + 1 );
    makeEmpty( S );
    for ( int i = 0; i < length; ++i ) {
        if ( str[ i ] == '(' || str[ i ] == '[' || str[ i ] == '{' )
            push( S, str[ i ] );
        else {
            if ( isEmpty( S ) )
                return false;
            // Error( "Brackets do not match!!!" );

            char top;
            top = topAndPop( S );
            if ( str[ i ] == ')' && top != '(' )
                return false;
            // Error( "Brackets do not match!!!" );
            if ( str[ i ] == ']' && top != '[' )
                return false;
            // Error( "Brackets do not match!!!" );
            if ( str[ i ] == '}' && top != '{' )
                return false;
            // Error( "Brackets do not match!!!" );
        }
    }
    if ( !isEmpty( S ) )
        return false;
    // Error( "Brackets do not match!!!" );
    return true;
}

int main() {
    char arr[] = { '(', '(', '(', ')', ')', '(', ')', ')' };
    if ( !bracketCheck( arr, 8 ) )
        printf( "Brackets do not match!!!" );
    else
        printf( "haha" );
    return 0;
}