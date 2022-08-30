//
// Created by bruce on 8/29/22.
//
#include "ConvertToPolishNotation.h"
#include "../Fatal.h"
#include <stdio.h>

#define emptyTOS ( -1 )
#define minStackSize ( 5 )

struct StackRecord {
    int capacity;
    int topOfStack;
    char *element;
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

    S->element = malloc( sizeof( char ) * maxElements );
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

void push( Stack S, char value ) {
    if ( isFull( S ) )
        Error( "Full stack!!!" );
    else
        S->element[ ++S->topOfStack ] = value;
}

char top( Stack S ) {
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

char topAndPop( Stack S ) {
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

void convertToPolishNotation( char *str, char *s ) {
    int i, count;
    i = 0;
    count = 0;
    while ( str[ i ] != '\0' ) {
        i++;
        count++;
    }

    i = 0;
    Stack S;
    S = createStack( count );
    for ( int j = 0; str[ j ] != '\0'; ++j ) {
        if ( str[ j ] >= '0' && str[ j ] <= '9' )
            s[ i++ ] = str[ j ];
        else if ( str[ j ] == '*' || str[ j ] == '/' ) {
            if ( !isEmpty( S ) ) {
                while ( top( S ) == '*' || top( S ) == '/' ) {
                    s[ i++ ] = topAndPop( S );
                    if ( isEmpty( S ) )
                        break;
                }
            }
            push( S, str[ j ] );
        } else if ( str[ j ] == '+' || str[ j ] == '-' ) {
            if ( !isEmpty( S ) ) {
                while ( top( S ) == '+' || top( S ) == '-' || top( S ) == '*' ||
                        top( S ) == '/' ) {
                    s[ i++ ] = topAndPop( S );
                    if ( isEmpty( S ) )
                        break;
                }
            }
            push( S, str[ j ] );
        } else if ( str[ j ] == '(' ) {
            push( S, str[ j ] );
        } else if ( str[ j ] == ')' ) {
            if ( !isEmpty( S ) ) {
                while ( top( S ) != '(' ) {
                    s[ i++ ] = topAndPop( S );
                }
                pop( S );
            }
        } else {
            FatalError( "Please input the carrot expression" );
        }
    }
    while ( !isEmpty( S ) )
        s[ i++ ] = topAndPop( S );
}
