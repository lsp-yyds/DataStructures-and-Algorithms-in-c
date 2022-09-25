//
// Created by bruce on 9/3/22.
//

#include "BinaryTreeInLinkedList.h"
#include "../Fatal.h"
#include "QueueInLinkedList.h"
#include <stdlib.h>

struct TreeNode {
    ElementType element;
    struct TreeNode *left, *right;
};

BinaryTree createBinaryTree( ElementType value ) {
    BinaryTree T = createNode( value );
    if ( T == NULL )
        FatalError( "Out of space!!!" );

    return T;
}

TreeNode createNode( ElementType value ) {
    TreeNode TmpCell = malloc( sizeof( struct TreeNode ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->element = value;
    TmpCell->left = NULL;
    TmpCell->right = NULL;

    return TmpCell;
}

void retrieve( Position P ) {
    // printf( "%c", P->element );
    printf( "%d ", P->element );
}

void preOrder( BinaryTree T ) {
    if ( T != NULL ) {
        retrieve( T );
        preOrder( T->left );
        preOrder( T->right );
    }
}

void inOrder( BinaryTree T ) {
    if ( T != NULL ) {
        preOrder( T->left );
        retrieve( T );
        preOrder( T->right );
    }
}
void postOrder( BinaryTree T ) {
    if ( T != NULL ) {
        preOrder( T->left );
        preOrder( T->right );
        retrieve( T );
    }
}

void levelOrder( BinaryTree T ) {
    Queue Q = createQueue();
    Position P;
    Enqueue( Q, T );
    while ( !isEmpty( Q ) ) {
        P = front( Q );
        Dequeue( Q );
        retrieve( P );
        if ( P->left != NULL )
            Enqueue( Q, P->left );
        if ( P->right != NULL )
            Enqueue( Q, P->right );
    }
}

// 对于一般二叉树的插入实现需要改进
void insert( Position P, char c, ElementType value ) {
    if ( P == NULL )
        FatalError( "P == NULL" );

    if ( c != 'l' && c != 'r' )
        FatalError( "Please input the current char" );

    if ( c == 'l' ) {
        if ( P->left == NULL )
            P->left = createNode( value );
    } else {
        if ( P->right == NULL )
            P->right = createNode( value );
    }
}

int main( int argc, char const *argv[] ) {
    BinaryTree T = createBinaryTree( 1 );
    insert( T, 'l', 2 );
    insert( T, 'r', 3 );
    preOrder( T );
    printf( "\n" );
    inOrder( T );
    printf( "\n" );
    postOrder( T );
    printf( "\n" );
    levelOrder( T );
    return 0;
}