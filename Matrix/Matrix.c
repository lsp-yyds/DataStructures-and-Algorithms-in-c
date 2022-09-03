//
// Created by bruce on 9/3/22.
//

#include "Matrix.h"
#include <stdlib.h>

struct Matrix {
    ElementType *element;
    int theRows, theColumns;
};

Matrix createMatrix( int theRows, int theColumns ) {
    Matrix M = malloc( sizeof( struct Matrix ) );
    M->element = malloc( sizeof( ElementType ) * ( theRows * theColumns ) );
    M->theRows = theRows;
    M->theColumns = theColumns;
    return M;
}

void makeEmpty( Matrix M ) {
    for ( int i = 0; i < M->theRows; ++i ) {
        for ( int j = 0; j < M->theColumns; ++j )
            M->element[ j + i * M->theColumns ] = 0;
    }
}

void negative( Matrix M );
void addition( Matrix M, Matrix targetMatrix );
void multiplication( Matrix M, Matrix targetMatrix );
void printMatrix( Matrix M );