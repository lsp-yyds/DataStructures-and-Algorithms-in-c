//
// Created by bruce on 9/3/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_MATRIX_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_MATRIX_H

struct Matrix;
typedef struct Matrix *Matrix;
typedef int ElementType;

Matrix createMatrix( int theRows, int theColumns );
void makeEmpty( Matrix M );
Matrix negative( Matrix targetMatrix );
Matrix addition( Matrix M_1, Matrix M_2 );
Matrix multiplication( Matrix M_1, Matrix M_2 );
void printMatrix( Matrix M );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_MATRIX_H
