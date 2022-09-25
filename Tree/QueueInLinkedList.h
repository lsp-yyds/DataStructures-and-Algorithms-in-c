//
// Created by bruce on 8/25/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINLINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINLINKEDLIST_H

#include "BinaryTreeInLinkedList.h"
#include <stdbool.h>

struct Node;
struct Queue;
typedef struct Node *Node;
typedef struct Queue *Queue;
typedef struct TreeNode *QueueElementType;

bool isEmpty( Queue Q );
bool isFull( Queue Q );
Queue createQueue();
void disposeQueue( Queue Q );
void makeEmpty( Queue Q );
void Enqueue( Queue Q, QueueElementType node );
QueueElementType front( Queue Q );
void Dequeue( Queue Q );
int length( Queue Q );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINLINKEDLIST_H
