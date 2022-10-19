//
// Created by bruce on 10/14/22.
//

#include "LinearSearch.h"
#include "../Fatal.h"

struct SearchTable {
    ElementType *element;
    int length;
};

int linearSearch( SearchTable T, ElementType value ) {
    int i = 0;

    while ( i < T.length && T.element[ i ] != value )
        i++;

    return i == T.length ? -1 : i;
}

int inverseLinearSearch( SearchTable T, ElementType value ) {
    T.element[ 0 ] = value;
    int i = T.length;

    while ( T.element[ i ] != value )
        i--;

    return i;
}