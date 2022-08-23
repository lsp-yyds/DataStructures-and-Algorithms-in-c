//
// Created by bruce on 8/19/22.
//

#include "SeqList.h"

/**
 * 位序从1开始的线性表的顺序表示
 * 一种特殊情况为element[0]为空,SeqList从element[1]开始存储元素
 * @param arrayLength
 * @return
 */

SeqList *getSeqList( int arrayLength ) {
    SeqList *seqList = (SeqList *) malloc( sizeof( SeqList ) );
    seqList->element =
        (ElementType *) malloc( sizeof( ElementType ) * arrayLength );
    seqList->arrayLength = arrayLength;

    for ( int i = 0; i < arrayLength; i++ )
        seqList->element[ i ] = 0;
    seqList->listSize = 0;

    return seqList;
}

SeqList *getCopySeqList( SeqList *targetSeqList ) {
    SeqList *seqList = getSeqList( targetSeqList->arrayLength );

    for ( int i = 0; i < targetSeqList->listSize; i++ )
        seqList->element[ i ] = targetSeqList->element[ i ];
    seqList->listSize = targetSeqList->listSize;

    return seqList;
}

SeqList *changeLengthSeqList( SeqList *targetSeqList ) {
    SeqList *seqList = getSeqList( targetSeqList->arrayLength * 2 );

    for ( int i = 0; i < targetSeqList->listSize; i++ )
        seqList->element[ i ] = targetSeqList->element[ i ];
    seqList->listSize = targetSeqList->listSize;

    return seqList;
}

// input/output
void insertValueSeqList( SeqList *seqList, int position, ElementType value ) {
    if ( position < 1 || position > seqList->listSize + 1 )
        FatalError( "Illegal index!!!" );

    if ( seqList->listSize == seqList->arrayLength )
        seqList = changeLengthSeqList( seqList );

    for ( int i = seqList->listSize; i >= position; i-- )
        seqList->element[ i ] = seqList->element[ i - 1 ];
    seqList->element[ position - 1 ] = value;
    seqList->listSize++;
}

void removeValueSeqList( SeqList *seqList, int position ) {
    if ( position < 1 || position > seqList->listSize )
        FatalError( "Illegal index!!!" );

    for ( int i = position; i < seqList->listSize - 1; i++ )
        seqList->element[ i - 1 ] = seqList->element[ i ];
    seqList->listSize--;
}

void pushValueSeqList( SeqList *seqList, ElementType value ) {
    if ( seqList->listSize == seqList->arrayLength )
        seqList = changeLengthSeqList( seqList );

    insertValueSeqList( seqList, seqList->listSize + 1, value );
}

void updateValueSeqList( SeqList *seqList, int position, ElementType value ) {
    if ( position < 1 || position > seqList->listSize )
        FatalError( "Illegal index!!!" );

    seqList->element[ position - 1 ] = value;
}

// erase
void eraseSeqList( SeqList *seqList ) {
    seqList->listSize = 0;
    free( seqList );
}

// switching
void swap( SeqList *seqList, int position1, int position2 ) {
    ElementType temp = seqList->element[ position1 - 1 ];
    seqList->element[ position1 - 1 ] = seqList->element[ position2 - 1 ];
    seqList->element[ position2 - 1 ] = temp;
}
void switchValuesSeqList( SeqList *seqList, int position1, int position2 ) {
    if ( position1 < 1 || position2 < 1 || position1 > seqList->listSize ||
         position1 > seqList->listSize )
        FatalError( "Illegal index!!!" );

    swap( seqList, position1, position2 );
}
int reverseSeqList( SeqList *seqList ) {
    for ( int i = 1; i <= seqList->listSize / 2; i++ )
        swap( seqList, i, seqList->listSize - i + 1 );
}

// sorting(TODO)
int bubbleSortSeqList( SeqList *seqList );
int selectionSortSeqList( SeqList *seqList );
int insertionSortSeqList( SeqList *seqList );
int blenderSeqList( SeqList *seqList );

// searching
int valueOcurranceSeqList( SeqList *seqList, ElementType value ) {
    int i, total = 0;
    for ( i = 0; i < seqList->listSize; i++ )
        if ( seqList->element[ i ] == value )
            total++;
    return total;
}
ElementType positionValueSeqList( SeqList *seqList, int position ) {
    if ( position < 1 || position > seqList->listSize )
        FatalError( "Illegal index!!!" );

    return seqList->element[ position - 1 ];
}
SeqList *valuePositionsSeqList( SeqList *seqList, ElementType value ) {
    int count = 0;
    int total = valueOcurranceSeqList( seqList, value );
    SeqList *resultArray = getSeqList( total );
    for ( int i = 0; i < seqList->listSize; i++ ) {
        if ( seqList->element[ i ] == value ) {
            pushValueSeqList( resultArray, i + 1 );
            count++;
        }
    }
    return resultArray;
}
void displayValuePositionsSeqList( SeqList *seqList, ElementType value ) {
    SeqList *resultArray = valuePositionsSeqList( seqList, value );
    displaySeqList( resultArray );
}
ElementType findMaxSeqList( SeqList *seqList ) {
    ElementType maxElement = 0;
    for ( int i = 0; i < seqList->listSize; i++ ) {
        if ( maxElement < seqList->element[ i ] )
            maxElement = seqList->element[ i ];
    }
    return maxElement;
}
ElementType findMinSeqList( SeqList *seqList ) {
    ElementType minElement = 0;
    for ( int i = 0; i < seqList->listSize; i++ ) {
        if ( minElement > seqList->element[ i ] )
            minElement = seqList->element[ i ];
    }
    return minElement;
}

// else
int size( SeqList *seqList ) {
    return seqList->listSize;
}
int empty( SeqList *seqList ) {
    return seqList->listSize == 0;
}

// display
void displaySeqList( SeqList *seqList ) {
    for ( int i = 0; i < seqList->listSize; i++ ) {
        printf( "%d ", seqList->element[ i ] );
    }
    printf( "\n" );
}