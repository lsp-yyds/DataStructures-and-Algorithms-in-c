//
// Created by bruce on 9/3/22.
//

#include "BinaryTreeInArray.h"
#include "../Fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeRecord {
    ElementType *element;
    bool *isEmpty;
    int capacity;
};

BinaryTree createBinaryTree( int maxElements ) {
    BinaryTree T = malloc( sizeof( struct TreeRecord ) );
    if ( T == NULL )
        FatalError( "Out of space!!!" );

    T->element = malloc( sizeof( ElementType ) * ( maxElements + 1 ) );
    T->isEmpty = malloc( sizeof( bool ) * ( maxElements + 1 ) );
    if ( T->element == NULL || T->isEmpty == NULL )
        FatalError( "Out of space!!!" );

    T->capacity = maxElements;

    makeEmpty( T );
    return T;
}

void makeEmpty( BinaryTree T ) {
    for ( int i = 1; i < T->capacity; ++i ) {
        T->isEmpty[ i ] = true;
    }
}

// TODO 复制构造一颗通过数组实现的树

// TODO 对于插入位置大于数组容量情况的实现
void insert( BinaryTree T, int position, ElementType value ) {
    if ( position < 1 || position > T->capacity )
        FatalError( "Illegal index!!!" );

    T->element[ position ] = value;
    T->isEmpty[ position ] = false;
}

// 当结点为叶子结点时直接删除该结点,当结点为非叶子结点时删除该结点及孩子结点
void delete ( BinaryTree T, int position ) {
    if ( position < 1 || position > T->capacity )
        FatalError( "Out of space!!!" );

    if ( position * 2 > T->capacity )
        T->isEmpty[ position ] = true;

    if ( position * 2 + 1 <= T->capacity ) {
        T->isEmpty[ position ] = true;
        delete ( T, position * 2 );
        delete ( T, position * 2 + 1 );
    }
}

bool findChildren( BinaryTree T, int position ) {
    if ( position < 1 || position > T->capacity )
        FatalError( "Illegal index!!!" );

    return T->isEmpty[ position * 2 ] == false ||
           T->isEmpty[ position * 2 + 1 ] == false;
}

int findParent( BinaryTree T, int position ) {
    if ( position < 1 || position > T->capacity )
        FatalError( "Illegal index!!!" );

    return position / 2;
}

void retrieve( BinaryTree T, int position ) {
    printf( "%d ", T->element[ position ] );
}

void levelOrder( BinaryTree T ) {
    for ( int i = 1; i <= T->capacity; ++i ) {
        if ( T->isEmpty[ i ] == false )
            retrieve( T, i );
    }
    printf( "\n" );
}

int main() {
    BinaryTree T = createBinaryTree( 15 );
    int i = 0;
    scanf( "%d", &i );
    while ( i != 9999 ) {
        insert( T, i, i );
        scanf( "%d", &i );
    }
    levelOrder( T );
    delete ( T, 3 );
    levelOrder( T );

    return 0;
}