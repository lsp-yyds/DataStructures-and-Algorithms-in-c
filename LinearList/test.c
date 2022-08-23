//
// Created by bruce on 8/19/22.
//
#include "SeqList.h"

int main() {
    SeqList *arrayList = getSeqList( 11 );
    for ( int i = 0; i < 10; ++i ) {
        pushValueSeqList( arrayList, i );
    }
    SeqList *arrayList1 = getCopySeqList( arrayList );
    arrayList1 = changeLengthSeqList( arrayList );
    printf( "%d\n", arrayList1->arrayLength );
    insertValueSeqList( arrayList1, 11, 10 );
    displaySeqList( arrayList1 );
    removeValueSeqList( arrayList1, 11 );
    displaySeqList( arrayList1 );
    reverseSeqList( arrayList1 );
    displaySeqList( arrayList1 );
    printf( "%d\n", findMaxSeqList( arrayList1 ) );
    printf( "%d\n", findMinSeqList( arrayList1 ) );
    return 0;
}