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
void negative( Matrix M );
void addition( Matrix M, Matrix targetMatrix );
void multiplication( Matrix M, Matrix targetMatrix );
void printMatrix( Matrix M );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_MATRIX_H
