//
// Created by bruce on 10/14/22.
//

#include "BinarySearch.h"

struct SearchTable {
    ElementType *element;
    int length;
};

// 非递归实现(升序)
int binarySerch( SearchTable T, ElementType value ) {
    int l = 0, r = T.length - 1, mid;

    while ( l < r ) {
        mid = l + ( r - l ) / 2;
        if ( T.element[ mid ] == value )
            return mid;
        else if ( T.element[ mid ] > value )
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}