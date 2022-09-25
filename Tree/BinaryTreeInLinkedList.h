//
// Created by bruce on 9/3/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINLINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINLINKEDLIST_H

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode BinaryTree;
typedef PtrToNode TreeNode;
typedef PtrToNode Position;
typedef int ElementType;

BinaryTree createBinaryTree( ElementType value );
TreeNode createNode( ElementType value );
void insert( Position P, char c, ElementType value );
void retrieve( Position P );
void preOrder( BinaryTree T );
void inOrder( BinaryTree T );
void postOrder( BinaryTree T );
void levelOrder( BinaryTree T );
void findPrevious( Position P );
void findFollowing( Position P );
int treeDepth( BinaryTree T );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_BINARYTREEINLINKEDLIST_H
