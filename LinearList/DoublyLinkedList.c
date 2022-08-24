//
// Created by bruce on 8/22/22.
//
#include "DoublyLinkedList.h"
#include "../Fatal.h"
#include <stdlib.h>

DLinkedList makeEmpty( DLinkedList L ) {
    // 可能出现无法访问地址的问题
    // if ( L != NULL )
    //     deleteList( L );
    L = malloc( sizeof( struct Node ) );
    if ( L == NULL )
        FatalError( "Out of space!!!" );
    L->next = NULL;
    L->prior = NULL;
    return L;
}

bool isEmpty( DLinkedList L ) {
    return L->next == NULL;
}

bool isLast( DLinkedList L, DNode P ) {
    return P->next == NULL;
}

DNode header( DLinkedList L ) {
    return L;
}

DNode first( DLinkedList L ) {
    return L->next;
}

DNode advance( DNode P ) {
    return P->next;
}

DNode retreat( DNode P ) {
    return P->prior;
}

ElementType retrieve( DNode P ) {
    return P->element;
}

int length( DLinkedList L ) {
    int count;
    DNode P;

    count = 0;
    P = L->next;
    while ( P != NULL ) {
        P = P->next;
        count++;
    }

    return count;
}

bool checkNode( DLinkedList L, DNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    DNode TmpCell;
    TmpCell = L->next;
    if ( TmpCell != NULL && TmpCell != P )
        TmpCell = TmpCell->next;

    return TmpCell == P;
}

DNode findPositionPrevious( DLinkedList L, int i ) {
    return findPosition( L, i )->prior;
}

DNode findValuePrevious( DLinkedList L, ElementType value ) {
    return findValue( L, value )->prior;
}

DNode findNodePrevious( DLinkedList L, DNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    if ( P->prior == NULL )
        FatalError( "This is the head node!!!" );

    return P->prior;
}

DNode findPosition( DLinkedList L, int i ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    DNode P;
    int count;

    P = L;
    count = 0;
    while ( P != NULL && count < i ) {
        P = P->next;
        count++;
    }

    return P;
}

DNode findValue( DLinkedList L, ElementType value ) {
    DNode P;

    P = L->next;
    while ( P != NULL && P->element != value )
        P = P->next;

    if ( P == NULL )
        FatalError( "DoublyLinkedList don't have this value" );

    return P;
}

DNode findLastNode( DLinkedList L ) {
    DNode P;
    P = L;
    while ( !isLast( L, P ) )
        P = P->next;

    return P;
}

int findNodePosition( DLinkedList L, DNode P ) {
    if ( P == NULL )
        FatalError( "Illegal pointer" );

    DNode TmpCell;
    int count;
    TmpCell = L;
    count = 0;
    while ( TmpCell != NULL && TmpCell != P ) {
        TmpCell = TmpCell->next;
        count++;
    }
    if ( TmpCell == NULL )
        FatalError( "CircularLinkedList don't have this node!!!" );

    return count;
}

void updateNode( DLinkedList L, DNode P, ElementType value ) {
    // 对性能有一定的影响
    checkNode( L, P );
    P->element = value;
}

void updateValue( DLinkedList L, ElementType targetValue, ElementType value ) {
    updateNode( L, findValue( L, targetValue ), value );
}

void updatePosition( DLinkedList L, int i, ElementType value ) {
    updateNode( L, findPosition( L, i ), value );
}

void headInsert( DLinkedList L, ElementType value ) {
    insertNodeFollowing( L, L, value );
}

void tailInsert( DLinkedList L, ElementType value ) {
    insertNodeFollowing( L, findLastNode( L ), value );
    //    DNode P, TmpCell;
    //
    //    P = L;
    //    TmpCell = malloc( sizeof( struct Node ) );
    //    TmpCell->element = value;
    //    while ( !isLast( L, P ) )
    //        P = P->next;
    //    TmpCell->next = P->next;
    //    P->next = TmpCell;
    //    TmpCell->prior = L;
}

void insertNodePrevious( DLinkedList L, DNode P, ElementType value ) {
    if ( P == L )
        FatalError( "Can't insert before the head node!!!" );

    DNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = value;
    P->prior->next = TmpCell;
    TmpCell->prior = P->prior;
    TmpCell->next = P;
    P->prior = TmpCell;
}

void insertPositionPrevious( DLinkedList L, int i, ElementType value ) {
    insertNodePrevious( L, findPosition( L, i ), value );
}

void insertNodeFollowing( DLinkedList L, DNode P, ElementType value ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    DNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = value;
    if ( isLast( L, P ) ) {
        TmpCell->next = P->next;
        P->next = TmpCell;
        TmpCell->prior = P;
    } else {
        TmpCell->next = P->next;
        P->next->prior = TmpCell;
        P->next = TmpCell;
        TmpCell->prior = P;
    }
}

void insertPositionFollowing( DLinkedList L, int i, ElementType value ) {
    insertNodeFollowing( L, findPosition( L, i ), value );
}

void deleteNode( DLinkedList L, DNode P ) {
    if ( P == L )
        FatalError( "Please use deleteList function to delete list!!!" );

    if ( isLast( L, P ) ) {
        P->prior->next = P->next;
        free( P );
    } else {
        P->prior->next = P->next;
        P->next->prior = P->prior;
        free( P );
    }
}

void deleteValue( DLinkedList L, ElementType value ) {
    deleteNode( L, findValue( L, value ) );
}

void deletePosition( DLinkedList L, int i ) {
    deleteNode( L, findPosition( L, i ) );
}

void deleteList( DLinkedList L ) {
    DNode P, Tmp;

    P = L->next;
    L->next = NULL;
    L->prior = NULL;
    while ( P != NULL ) {
        Tmp = P->next;
        free( P );
        P = Tmp;
    }
}

void printList( DLinkedList L ) {
    DNode P;

    P = L->next;
    if ( length( L ) == 0 )
        printf( "NULL<-head->NULL" );
    else {
        printf( "NULL<-head" );
        while ( P != NULL ) {
            printf( "<->%d", P->element );
            P = P->next;
        }
        printf( "->NULL" );
    }
    printf( "\n" );
}

int main() {
    DLinkedList L;
    L = makeEmpty( L );
    for ( int i = 0; i < 5; ++i ) {
        headInsert( L, i );
    }
    printList( L );
    return 0;
}