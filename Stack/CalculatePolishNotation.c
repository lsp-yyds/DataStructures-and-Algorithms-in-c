//
// Created by bruce on 8/30/22.
//

#include "CalculatePolishNotation.h"
#include "../Fatal.h"
#include "ConvertToPolishNotation.h"
#include <stdio.h>

#define emptyTOS ( -1 )
#define minStackSize ( 5 )

struct StackRecord {
    int capacity;
    int topOfStack;
    int *element;
};

bool IsEmpty( Stack S ) {
    return S->topOfStack == emptyTOS;
}

bool IsFull( Stack S ) {
    return S->topOfStack == S->capacity - 1;
}

Stack CreateStack( int maxElements ) {
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
    MakeEmpty( S );

    return S;
}

void DisposeStack( Stack S ) {
    if ( S != NULL ) {
        free( S->element );
        free( S );
    }
}

void MakeEmpty( Stack S ) {
    S->topOfStack = emptyTOS;
}

void Push( Stack S, int value ) {
    if ( IsFull( S ) )
        Error( "Full stack!!!" );
    else
        S->element[ ++S->topOfStack ] = value;
}

int Top( Stack S ) {
    if ( IsEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        return S->element[ S->topOfStack ];
}

void Pop( Stack S ) {
    if ( IsEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        S->topOfStack--;
}

int TopAndPop( Stack S ) {
    if ( IsEmpty( S ) )
        Error( "Empty stack!!!" );
    else
        return S->element[ S->topOfStack-- ];
}

void PrintStack( Stack S ) {
    for ( int i = S->topOfStack; i > emptyTOS; i-- ) {
        printf( "|   %d   |\n", S->element[ i ] );
        printf( "---------\n" );
    }
    printf( "\n" );
}

int calculatePolishNotation( char *str ) {
    int i, count;
    i = 0;
    count = 0;
    while ( str[ i ] != '\0' ) {
        i++;
        count++;
    }

    i = 0;
    Stack S;
    int num1, num2;
    S = CreateStack( count );
    for ( int j = 0; str[ j ] != '\0'; ++j ) {
        if ( str[ j ] >= '0' && str[ j ] <= '9' ) {
            Push( S, str[ j ] - 48 );
        } else if ( str[ j ] == '+' || str[ j ] == '-' || str[ j ] == '*' ||
                    str[ j ] == '/' ) {
            if ( str[ j ] == '+' ) {
                num2 = TopAndPop( S );
                num1 = TopAndPop( S );
                i = num1 + num2;
                Push( S, i );
            } else if ( str[ j ] == '-' ) {
                num2 = TopAndPop( S );
                num1 = TopAndPop( S );
                i = num1 - num2;
                Push( S, i );
            } else if ( str[ j ] == '*' ) {
                num2 = TopAndPop( S );
                num1 = TopAndPop( S );
                i = num1 * num2;
                Push( S, i );
            } else if ( str[ j ] == '/' ) {
                num2 = TopAndPop( S );
                num1 = TopAndPop( S );
                i = num1 / num2;
                Push( S, i );
            } else
                Error( "Please input the carrot expression!!!" );
        }
    }
    return TopAndPop( S );
}

int main() {
    char c[ 100 ];
    char *s = malloc( sizeof( char ) * 100 );
    gets( c );
    convertToPolishNotation( c, s );
    int i = 0;
    while ( s[ i ] != '\0' ) {
        printf( "%c ", s[ i ] );
        i++;
    }
    printf( "\n" );
    printf( "%d", calculatePolishNotation( s ) );
}