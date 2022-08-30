//
// Created by bruce on 8/28/22.
//

#include "SearchTree.h"
#include "../Fatal.h"
#include <stdlib.h>

struct TreeNode {
    ElementType element;
    struct TreeNode *left;
    struct TreeNode *right;
};

SearchTree makeEmpty( SearchTree T ) {
    if ( T != NULL ) {
        makeEmpty( T->left );
        makeEmpty( T->right );
        free( T );
    }
}

Position find( SearchTree T, ElementType value ) {
    if ( T == NULL )
        return NULL;
    if ( value < T->element )
        return find( T->left, value );
    else if ( value > T->element )
        return find( T->right, value );
    else
        return T;
}

Position findMin( SearchTree T ) {
    if ( T == NULL )
        return NULL;
    else if ( T->left == NULL )
        return T;
    else
        return findMin( T );
}

Position findMax( SearchTree T ) {
    if ( T == NULL )
        return NULL;
    else if ( T->right == NULL )
        return T;
    else
        return findMax( T );
}

SearchTree insert( SearchTree T, ElementType value ) {
    if ( T == NULL ) {
        T = malloc( sizeof( struct TreeNode ) );
        if ( T == NULL )
            FatalError( "Out of space!!!" );
        else {
            T->element = value;
            T->left = T->right = NULL;
        }
    } else if ( value < T->element )
        T->left = insert( T->left, value );
    else if ( value > T->element )
        T->right = insert( T->right, value );

    return T;
}

SearchTree delete ( SearchTree T, ElementType value ) {
    if ( T == NULL )
        Error( "Element is not found!!!" );
}

ElementType retrieve( Position P );

void printTree( SearchTree T ) {
    if ( T != NULL ) {
        printTree( T->left );
        printf( "%d", T->element );
        printTree( T->right );
    }
}

int main() {
    SearchTree T = makeEmpty( T );
    int a[] = { 33, 5, 65, 68, 35, 47, 89, 96 };
    for ( int i = 0; i < 8; ++i ) {
        T = insert( T, a[ i ] );
    }
    printTree( T );
    return 0;
}