//
// Created by bruce on 7/24/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_ARRAYLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_ARRAYLIST_H

#include "../Fatal.h"

typedef int ElementType;
typedef struct ArrayList {
    ElementType *element;
    int listSize;
    int arrayLength;
} ArrayList;

ArrayList *getArrayList( int arrayLength );
ArrayList *getCopyArrayList( ArrayList *targetArrayList );
ArrayList *changeLengthArrayList( ArrayList *targetarrayList );

// input/output
void insertValueArrayList( ArrayList *arrayList, int position,
                           ElementType value );
void removeValueArrayList( ArrayList *arrayList, int position );
void pushValueArrayList( ArrayList *arrayList, ElementType value );
void updateValueArrayList( ArrayList *arrayList, int position,
                           ElementType value );

// erase
void swap( ArrayList *arrayList, int position1, int position2 );
void eraseArrayList( ArrayList *arrayList );

// switching
void switchValuesArrayList( ArrayList *arrayList, int position1,
                            int position2 );
int reverseArrayList( ArrayList *arrayList );

// sorting
int bubbleSortArrayList( ArrayList *arrayList );
int selectionSortArrayList( ArrayList *arrayList );
int insertionSortArrayList( ArrayList *arrayList );
int blenderArrayList( ArrayList *arrayList );

// searching
int valueOcurranceArrayList( ArrayList *arrayList, ElementType value );
ElementType positionValueArrayList( ArrayList *arrayList, int position );
ArrayList *valuePositionsArrayList( ArrayList *arrayList, ElementType value );
void displayValuePositionsArrayList( ArrayList *arrayList, ElementType value );
ElementType findMaxArrayList( ArrayList *arrayList );
ElementType findMinArrayList( ArrayList *arrayList );

// else
int size( ArrayList *arrayList );
int empty( ArrayList *arrayList );

// display
void displayArrayList( ArrayList *arrayList );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_ARRAYLIST_H
