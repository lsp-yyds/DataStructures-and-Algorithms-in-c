//
// Created by bruce on 8/19/22.
//
#include "ArrayList.h"

int main() {
    ArrayList *arrayList = getArrayList( 11 );
    if ( empty( arrayList ) ) {
        for ( int i = 0; i < 10; ++i ) {
            pushValueArrayList( arrayList, i );
        }
    } else {
        printf( "arrayList not empty" );
    }
    printf( "%d\n", size( arrayList ) );
    reverseArrayList( arrayList );
    updateValueArrayList( arrayList, 4, 9 );
    updateValueArrayList( arrayList, 9, 9 );
    printf( "%d\n", valueOcurranceArrayList( arrayList, 9 ) );
    valuePositionsArrayList( arrayList, 9 );
    printf( "%d\n", size( arrayList ) );
    printf( "%d\n", findMaxArrayList( arrayList ) );
    printf( "%d", findMinArrayList( arrayList ) );
    return 0;
}