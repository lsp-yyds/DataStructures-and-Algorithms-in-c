//
// Created by bruce on 9/3/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINARRAY_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINARRAY_H

#include <stdbool.h>

struct TreeRecord;
typedef struct TreeRecord *BinaryTree;
typedef int ElementType;

BinaryTree createBinaryTree( int maxElements );
void makeEmpty( BinaryTree T );
void insert( BinaryTree T, int position, ElementType value );
void delete ( BinaryTree T, int position );
bool findChildren( BinaryTree T, int position );
int findParent( BinaryTree T, int position );
void retrieve( BinaryTree T, int position );
void preOrder( BinaryTree T );
void inOrder( BinaryTree T );
void postOrder( BinaryTree T );
void levelOrder( BinaryTree T );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINARRAY_H
