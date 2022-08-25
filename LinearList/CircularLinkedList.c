//
// Created by bruce on 8/24/22.
//

#include "CircularLinkedList.h"
#include "../Fatal.h"
#include <stdio.h>

struct Node {
    ElementType element;
    struct Node *next;
};

CLinkedList makeEmpty( CLinkedList L ) {
    L = malloc( sizeof( struct Node ) );
    if ( L == NULL )
        FatalError( "Out of space!!!" );

    L->next = L;
    return L;
}

bool isEmpty( CLinkedList L ) {
    return L->next == L;
}

bool isLast( CLinkedList L, CNode P ) {
    return P->next == L;
}

CNode header( CLinkedList L ) {
    return L;
}

CNode first( CLinkedList L ) {
    return L->next;
}

CNode advance( CNode P ) {
    return P->next;
}

ElementType retrieve( CNode P ) {
    return P->element;
}

int length( CLinkedList L ) {
    CNode P;
    int count;

    P = L->next;
    count = 0;
    while ( P != L ) {
        P = P->next;
        count++;
    }

    return count;
}

bool checkNode( CLinkedList L, CNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    CNode TmpCell;
    TmpCell = L->next;
    while ( TmpCell != L && TmpCell != P )
        TmpCell = TmpCell->next;

    return TmpCell == P;
}

CNode findPositionPrevious( CLinkedList L, int i ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    CNode P;
    int count;
    P = L;
    count = 0;
    while ( count < i - 1 ) {
        P = P->next;
        count++;
    }

    return P;
}

CNode findValuePrevious( CLinkedList L, ElementType value ) {
    CNode P;

    P = L;
    while ( P->next != L && P->next->element != value )
        P = P->next;
    if ( P->next == L )
        FatalError( "CircularLinkedList don't have this value" );

    return P;
}

CNode findNodePrevious( CLinkedList L, CNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    CNode TmpCell;
    TmpCell = L;
    while ( TmpCell->next != L && TmpCell->next != P )
        TmpCell = TmpCell->next;
    if ( TmpCell->next == L )
        FatalError( "CircularLinkedList don't have this node!!!" );

    return TmpCell;
}

CNode findPosition( CLinkedList L, int i ) {
    return findPositionPrevious( L, i )->next;
}

CNode findValue( CLinkedList L, ElementType value ) {
    return findValuePrevious( L, value )->next;
}

CNode findLastNode( CLinkedList L ) {
    CNode P;
    P = L;
    while ( !isLast( L, P ) )
        P = P->next;

    return P;
}

int findNodePosition( CLinkedList L, CNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    CNode TmpCell;
    int count;

    TmpCell = L->next;
    count = 0;
    while ( TmpCell != L && TmpCell != P ) {
        TmpCell = TmpCell->next;
        count++;
    }
    if ( TmpCell == NULL )
        FatalError( "CircularLinkedList don't have this node!!!" );

    return count;
}

// 更改结点元素值
void updateNode( CLinkedList L, CNode P, ElementType value ) {
    checkNode( L, P );
    P->element = value;
}

void updateValue( CLinkedList L, ElementType targetValue, ElementType value ) {
    updateNode( L, findValue( L, targetValue ), value );
}

void updatePosition( CLinkedList L, int i, ElementType value ) {
    updateNode( L, findPosition( L, i ), value );
}

void headInsert( CLinkedList L, ElementType value ) {
    insertNodeFollowing( L, L, value );
}

void tailInsert( CLinkedList L, ElementType value ) {
    insertNodeFollowing( L, findLastNode( L ), value );
}

void insertNodePrevious( CLinkedList L, CNode P, ElementType value ) {
    insertNodeFollowing( L, findNodePrevious( L, P ), value );
}

void insertPositionPrevious( CLinkedList L, int i, ElementType value ) {
    insertNodePrevious( L, findPosition( L, i ), value );
}

void insertNodeFollowing( CLinkedList L, CNode P, ElementType value ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    CNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void insertPositionFollowing( CLinkedList L, int i, ElementType value ) {
    insertNodeFollowing( L, findPosition( L, i ), value );
}

void deleteNode( CLinkedList L, CNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    CNode TmpCell;
    TmpCell = findNodePrevious( L, P );
    TmpCell->next = P->next;
    free( P );
}

void deleteValue( CLinkedList L, ElementType value ) {
    deleteNode( L, findValue( L, value ) );
}

void deletePosition( CLinkedList L, int i ) {
    deleteNode( L, findPosition( L, i ) );
}

void deleteList( CLinkedList L ) {
    CNode P, Tmp;

    P = L->next;
    L->next = NULL;
    while ( P != L ) {
        Tmp = P->next;
        free( P );
        P = Tmp;
    }
}

void printList( CLinkedList L ) {
    CNode P;
    P = L->next;
    printf( "head->" );
    while ( P != L ) {
        printf( "%d->", P->element );
        P = P->next;
    }
    printf( "head\n" );
}

int main() {
    CLinkedList L;
    L = makeEmpty( L );
    for ( int i = 0; i < 5; ++i ) {
        tailInsert( L, i );
    }
    printList( L );
    return 0;
}