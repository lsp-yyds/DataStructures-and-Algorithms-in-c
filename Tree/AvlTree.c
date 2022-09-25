//
// Created by bruce on 9/24/22.
//
#include "AvlTree.h"
#include "../Fatal.h"
#include <stdlib.h>

struct AvlNode {
    ElementType element;
    struct AvlNode *left, *right;
    int height;
};

static int height( Position P ) {
    if ( P == NULL )
        return -1;
    else
        return P->height;
}

AvlTree MakeEmpty( AvlTree T );
Position find( AvlTree T, ElementType value );
Position findMin( AvlTree T );
Position findMax( AvlTree T );
AvlTree insert( AvlTree T, ElementType value );
AvlTree delete ( AvlTree T, ElementType value );
ElementType retrieve( Position P );