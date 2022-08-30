//
// Created by bruce on 8/28/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEARCHTREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEARCHTREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree makeEmpty( SearchTree T );
Position find( SearchTree T, ElementType value );
Position findMin( SearchTree T );
Position findMax( SearchTree T );
SearchTree insert( SearchTree T, ElementType value );
SearchTree delete ( SearchTree T, ElementType value );
ElementType retrieve( Position P );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEARCHTREE_H
