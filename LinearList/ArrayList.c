//
// Created by bruce on 8/19/22.
//

#include "ArrayList.h"

/**
 *
 * @param arrayLength
 * @return
 */

ArrayList *getArrayList( int arrayLength ) {
    ArrayList *arrayList = (ArrayList *) malloc( sizeof( ArrayList ) );
    arrayList->element =
        (ElementType *) malloc( sizeof( ElementType ) * arrayLength );
    arrayList->arrayLength = arrayLength;
    for ( int i = 0; i < arrayLength; i++ ) {
        arrayList->element[ i ] = 0;
    }
    arrayList->listSize = 0;
    return arrayList;
}
ArrayList *getCopyArrayList( ArrayList *targetArrayList ) {
    ArrayList *arrayList = (ArrayList *) malloc( sizeof( ArrayList ) );
    arrayList->element = (ElementType *) malloc( sizeof( ElementType ) *
                                                 targetArrayList->arrayLength );
    arrayList->arrayLength = targetArrayList->arrayLength;
    arrayList->listSize = targetArrayList->listSize;
    for ( int i = 0; i < targetArrayList->arrayLength; i++ ) {
        arrayList->element[ i ] = targetArrayList->element[ i ];
    }
    return arrayList;
}

ArrayList *changeLengthArrayList( ArrayList *targetArrayList ) {
    ArrayList *arrayList = getArrayList( targetArrayList->arrayLength * 2 );
    for ( int i = 0; i < targetArrayList->listSize; i++ ) {
        arrayList->element[ i ] = targetArrayList->element[ i ];
    }
    arrayList->listSize = targetArrayList->listSize;
    return arrayList;
}

// input/output
void insertValueArrayList( ArrayList *arrayList, int position,
                           ElementType value ) {
    if ( position < 0 || position > arrayList->listSize )
        FatalError( "Illegal index!!!" );

    if ( arrayList->listSize == arrayList->arrayLength ) {
        arrayList = changeLengthArrayList( arrayList );
        for ( int i = arrayList->listSize - 1; i >= position; i-- )
            arrayList->element[ i + 1 ] = arrayList->element[ i ];
        arrayList->element[ position ] = value;
        arrayList->listSize++;
    } else {
        for ( int i = arrayList->listSize - 1; i >= position; i-- )
            arrayList->element[ i + 1 ] = arrayList->element[ i ];
        arrayList->element[ position ] = value;
        arrayList->listSize++;
    }
}

void removeValueArrayList( ArrayList *arrayList, int position ) {
    if ( position < 0 || position >= arrayList->listSize )
        FatalError( "Illegal index!!!" );

    for ( int i = position; i < arrayList->listSize - 1; i++ )
        arrayList->element[ i ] = arrayList->element[ i + 1 ];
    arrayList->listSize--;
}

void pushValueArrayList( ArrayList *arrayList, ElementType value ) {
    if ( arrayList->listSize == arrayList->arrayLength ) {
        arrayList = changeLengthArrayList( arrayList );
        insertValueArrayList( arrayList, arrayList->listSize, value );
    } else
        insertValueArrayList( arrayList, arrayList->listSize, value );
}

void updateValueArrayList( ArrayList *arrayList, int position,
                           ElementType value ) {
    if ( position < 0 || position >= arrayList->listSize )
        FatalError( "Illegal index!!!" );

    arrayList->element[ position ] = value;
}

// erase
void eraseArrayList( ArrayList *arrayList ) {
    arrayList->listSize == 0;
    free( arrayList );
}

// switching
void swap( ArrayList *arrayList, int position1, int position2 ) {
    ElementType temp = arrayList->element[ position1 ];
    arrayList->element[ position1 ] = arrayList->element[ position2 ];
    arrayList->element[ position2 ] = temp;
}
void switchValuesArrayList( ArrayList *arrayList, int position1,
                            int position2 ) {
    if ( position1 < 0 || position2 < 0 || position1 >= arrayList->listSize ||
         position1 >= arrayList->listSize )
        FatalError( "Illegal index!!!" );

    swap( arrayList, position1, position2 );
}
int reverseArrayList( ArrayList *arrayList ) {
    for ( int i = 0; i < arrayList->listSize / 2; i++ )
        swap( arrayList, i, arrayList->listSize - i - 1 );
}

// sorting(TODO)
int bubbleSortArrayList( ArrayList *arrayList );
int selectionSortArrayList( ArrayList *arrayList );
int insertionSortArrayList( ArrayList *arrayList );
int blenderArrayList( ArrayList *arrayList );

// searching
int valueOcurranceArrayList( ArrayList *arrayList, ElementType value ) {
    int i, total = 0;
    for ( i = 0; i < arrayList->listSize; i++ )
        if ( arrayList->element[ i ] == value )
            total++;
    return total;
}
ElementType positionValueArrayList( ArrayList *arrayList, int position ) {
    if ( position < 0 || position >= arrayList->listSize )
        FatalError( "Illegal index!!!" );

    return arrayList->element[ position ];
}
ArrayList *valuePositionsArrayList( ArrayList *arrayList, ElementType value ) {
    int count = 0;
    int total = valueOcurranceArrayList( arrayList, value );
    ArrayList *resultArray = getArrayList( total );
    for ( int i = 0; i < arrayList->listSize; i++ ) {
        if ( arrayList->element[ i ] == value ) {
            pushValueArrayList( resultArray, i );
            count++;
        }
    }
    return resultArray;
}
void displayValuePositionsArrayList( ArrayList *arrayList, ElementType value ) {
    ArrayList *resultArray = valuePositionsArrayList( arrayList, value );
    displayArrayList( resultArray );
}
ElementType findMaxArrayList( ArrayList *arrayList ) {
    ElementType maxElement = 0;
    for ( int i = 0; i < arrayList->listSize; i++ ) {
        if ( maxElement < arrayList->element[ i ] )
            maxElement = arrayList->element[ i ];
    }
    return maxElement;
}
ElementType findMinArrayList( ArrayList *arrayList ) {
    ElementType minElement = 0;
    for ( int i = 0; i < arrayList->listSize; i++ ) {
        if ( minElement > arrayList->element[ i ] )
            minElement = arrayList->element[ i ];
    }
    return minElement;
}

// else
int size( ArrayList *arrayList ) {
    return arrayList->listSize;
}
int empty( ArrayList *arrayList ) {
    return arrayList->listSize == 0;
}

// display
void displayArrayList( ArrayList *arrayList ) {
    for ( int i = 0; i < arrayList->listSize; i++ ) {
        printf( "%d ", arrayList->element[ i ] );
    }
    printf( "\n" );
}