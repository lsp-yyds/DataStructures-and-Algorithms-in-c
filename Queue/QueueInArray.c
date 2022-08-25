//
// Created by bruce on 8/25/22.
//

#include "QueueInArray.h"
#include "../Fatal.h"

#define minQueueSize ( 5 )

struct QueueRecord {
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *element;
};

bool isEmpty( Queue Q ) {
    return Q->size == 0;
}
bool isFull( Queue Q ) {
    return Q->size == Q->capacity;
}
Queue createQueue( int maxElements ) {
    if ( maxElements < minQueueSize )
        Error( "Queue is too small!!!" );

    Queue Q;
    Q = malloc( sizeof( struct QueueRecord ) );
    if ( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->element = malloc( sizeof( ElementType ) * maxElements );
    if ( Q->element == NULL )
        FatalError( "Out of space!!!" );
    Q->capacity = maxElements;
    makeEmpty( Q );

    return Q;
}
void disposeQueue( Queue Q ) {
    if ( Q != NULL ) {
        free( Q->element );
        free( Q );
    }
}

void makeEmpty( Queue Q ) {
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
}

static int succ( Queue Q, int value ) {
    if ( ++value == Q->capacity )
        value = 0;
    return value;
}

void Enqueue( Queue Q, ElementType value ) {
    if ( isFull( Q ) )
        FatalError( "Full queue!!!" );
    else {
        Q->size++;
        Q->rear = succ( Q, Q->rear );
        Q->element[ Q->rear ] = value;
    }
}

ElementType front( Queue Q ) {
    if ( isEmpty( Q ) )
        Error( "Empty queue!!!" );
    return Q->element[ Q->front ];
}

void Dequeue( Queue Q ) {
    if ( isEmpty( Q ) )
        Error( "Empty queue!!!" );
    else {
        Q->size--;
        Q->front = succ( Q, Q->front );
    }
}

ElementType frontAndDequeue( Queue Q ) {
    ElementType value = 0;

    if ( isEmpty( Q ) )
        Error( "Empty queue!!!" );
    else {
        Q->size--;
        value = Q->element[ Q->front ];
        Q->front = succ( Q, Q->front );
    }
    return value;
}

void printQueue( Queue Q ) {
    int count = Q->front;
    printf( "   " );
    for ( int i = 0; i < Q->capacity; ++i ) {
        printf( "---" );
    }
    printf( "\n" );
    printf( "<--" );
    for ( int i = 0; i < Q->size; ++i ) {
        printf( " %d ", Q->element[ count ] );
        count = succ( Q, count );
    }
    for ( int i = 0; i < Q->capacity - Q->size; ++i ) {
        printf( " N " );
    }
    printf( "<--" );
    printf( "\n" );
    printf( "   " );
    for ( int i = 0; i < Q->capacity; ++i ) {
        printf( "---" );
    }
    printf( "\n" );
}

int main() {
    Queue Q = createQueue( 6 );
    makeEmpty( Q );
    printQueue( Q );
    for ( int i = 0; i < 6; ++i ) {
        Enqueue( Q, i );
    }
    printQueue( Q );
    Dequeue( Q );
    printQueue( Q );

    return 0;
}