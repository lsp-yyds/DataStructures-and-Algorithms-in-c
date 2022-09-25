//
// Created by bruce on 9/3/22.
//

#include "Matrix.h"
#include "../Fatal.h"
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
    makeEmpty( M );
    return M;
}

void makeEmpty( Matrix M ) {
    for ( int i = 0; i < M->theRows; ++i ) {
        for ( int j = 0; j < M->theColumns; ++j )
            M->element[ j + i * M->theColumns ] = 0;
    }
}

Matrix negative( Matrix targetMatrix ) {
    Matrix M = createMatrix( targetMatrix->theRows, targetMatrix->theColumns );

    for ( int i = 0; i < targetMatrix->theRows; ++i ) {
        for ( int j = 0; j < targetMatrix->theColumns; ++j ) {
            M->element[ j + i * M->theColumns ] =
                -targetMatrix->element[ j + i * targetMatrix->theColumns ];
        }
    }

    return M;
}

Matrix addition( Matrix M_1, Matrix M_2 ) {
    if ( M_1->theRows != M_2->theRows || M_1->theColumns != M_2->theColumns )
        FatalError( "Two matrices cannot be added together!!!" );

    Matrix M = createMatrix( M_1->theRows, M_1->theColumns );

    for ( int i = 0; i < M->theRows; ++i ) {
        for ( int j = 0; j < M->theColumns; ++j ) {
            M->element[ j + i * M->theColumns ] =
                M_1->element[ j + i * M_1->theColumns ] +
                M_2->element[ j + i * M_2->theColumns ];
        }
    }

    return M;
}

Matrix multiplication( Matrix M_1, Matrix M_2 ) {
    if ( M_1->theColumns != M_2->theRows )
        FatalError( "Two matrices cannot be multiplied!!!" );

    Matrix M = createMatrix( M_1->theRows, M_2->theColumns );

    int ct = 0, cm = 0, cw = 0;

    for ( int i = 0; i < M_1->theRows; ++i ) {
        for ( int j = 0; j < M_2->theColumns; ++j ) {
            ElementType sum = M_1->element[ ct ] * M_2->element[ cm ];

            for ( int k = 1; k < M_1->theColumns; ++k ) {
                ct++;
                cm += M_2->theColumns;
                sum += M_1->element[ ct ] * M_2->element[ cm ];
            }
            M->element[ cw++ ] = sum;
            ct -= M_1->theColumns - 1;
            cm = j + 1;
        }
        ct += M_1->theColumns;
        cm = 0;
    }

    return M;
}

void printMatrix( Matrix M ) {
    for ( int i = 0; i < M->theRows; ++i ) {
        for ( int j = 0; j < M->theColumns; ++j ) {
            printf( "%d ", M->element[ j + i * M->theColumns ] );
        }
        printf( "\n" );
    }
}

int main() {
    Matrix M1 = createMatrix( 2, 3 );
    Matrix M2 = createMatrix( 3, 2 );

    for ( int i = 0; i < M1->theRows * M1->theColumns; ++i ) {
        M1->element[ i ] = i + 1;
    }

    for ( int i = 0; i < M2->theRows * M2->theColumns; ++i ) {
        M2->element[ i ] = i + 1;
    }

    printMatrix( M1 );
    printMatrix( M2 );

    Matrix M = multiplication( M1, M2 );
    printMatrix( M );
}