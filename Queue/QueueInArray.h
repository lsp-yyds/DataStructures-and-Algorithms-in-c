//
// Created by bruce on 8/25/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINARRAY_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINARRAY_H

#include <stdbool.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

bool isEmpty( Queue Q );
bool isFull( Queue Q );
Queue createQueue( int maxElements );
void disposeQueue( Queue Q );
void makeEmpty( Queue Q );
void Enqueue( Queue Q, ElementType value );
ElementType front( Queue Q );
void Dequeue( Queue Q );
ElementType frontAndDequeue( Queue Q );
void printQueue( Queue Q );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_QUEUEINARRAY_H
