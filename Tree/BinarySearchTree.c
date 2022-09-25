//
// Created by bruce on 8/28/22.
//

#include "BinarySearchTree.h"
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
    // 递归(空间复杂度为O(h))
    if ( T == NULL )
        return NULL;
    if ( value < T->element )
        return find( T->left, value );
    else if ( value > T->element )
        return find( T->right, value );
    else
        return T;

    // 非递归(空间复杂度为O(1))
    //    while ( T != NULL && value != T->element ) {
    //        if ( value < T->element )
    //            T = T->left;
    //        else
    //            T = T->right;
    //    }
    //    return T;
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
    Position TmpCell;

    if ( T == NULL )
        Error( "Element is not found!!!" );
    else if ( value < T->element )
        T->left = delete ( T->left, value );
    else if ( value > T->element )
        T->right = delete ( T->right, value );
    else if ( T->left && T->right ) {
        TmpCell = findMin( T->right );
        // TmpCell = findMax( T->left );
        T->element = TmpCell->element;
        T->right = delete ( T->right, T->element );
    } else {
        TmpCell = T;
        if ( T->left == NULL )
            T = T->right;
        else if ( T->right == NULL )
            T = T->left;
        free( TmpCell );
    }

    return T;
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