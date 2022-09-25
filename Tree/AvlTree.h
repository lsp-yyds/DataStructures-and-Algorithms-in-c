//
// Created by bruce on 9/24/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_AVLTREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_AVLTREE_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty( AvlTree T );
Position find( AvlTree T, ElementType value );
Position findMin( AvlTree T );
Position findMax( AvlTree T );
AvlTree insert( AvlTree T, ElementType value );
AvlTree delete ( AvlTree T, ElementType value );
ElementType retrieve( Position P );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_AVLTREE_H
