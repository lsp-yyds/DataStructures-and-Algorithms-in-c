//
// Created by bruce on 8/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEQLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEQLIST_H

#include "../Fatal.h"

typedef int ElementType;
struct SeqList;
typedef struct SeqList SeqList;

SeqList *getSeqList( int arrayLength );
SeqList *getCopySeqList( SeqList *targetSeqList );
SeqList *changeLengthSeqList( SeqList *targetarrayList );

// input/output
void insertValueSeqList( SeqList *arrayList, int position, ElementType value );
void removeValueSeqList( SeqList *arrayList, int position );
void pushValueSeqList( SeqList *arrayList, ElementType value );
void updateValueSeqList( SeqList *arrayList, int position, ElementType value );

// erase
void eraseSeqList( SeqList *arrayList );

// switching
void swap( SeqList *arrayList, int position1, int position2 );
void switchValuesSeqList( SeqList *arrayList, int position1, int position2 );
int reverseSeqList( SeqList *arrayList );

// sorting
int bubbleSortSeqList( SeqList *arrayList );
int selectionSortSeqList( SeqList *arrayList );
int insertionSortSeqList( SeqList *arrayList );
int blenderSeqList( SeqList *arrayList );

// searching
int valueOcurranceSeqList( SeqList *arrayList, ElementType value );
ElementType positionValueSeqList( SeqList *arrayList, int position );
SeqList *valuePositionsSeqList( SeqList *arrayList, ElementType value );
void displayValuePositionsSeqList( SeqList *arrayList, ElementType value );
ElementType findMaxSeqList( SeqList *arrayList );
ElementType findMinSeqList( SeqList *arrayList );

// else
int size( SeqList *arrayList );
int empty( SeqList *arrayList );

// display
void displaySeqList( SeqList *arrayList );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_SEQLIST_H
