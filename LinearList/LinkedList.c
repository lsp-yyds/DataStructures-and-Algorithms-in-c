//
// Created by bruce on 8/20/22.
//

#include "LinkedList.h"
#include "../Fatal.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList makeEmpty( LinkedList L ) {
    if ( L != NULL )
        deleteList( L );
    L = malloc( sizeof( struct Node ) );
    if ( L == NULL )
        FatalError( "Out of space" );
    L->next = NULL;
    return L;
}

bool isEmpty( LinkedList L ) {
    return L->next == NULL;
}

bool isLast( LinkedList L, Position P ) {
    return P->next == NULL;
}

Position header( LinkedList L ) {
    return L;
}

Position first( LinkedList L ) {
    return L->next;
}

Position advance( Position P ) {
    return P->next;
}

int position( LinkedList L, Position P ) {
    if ( P == NULL )
        FatalError( "Invalid node!!!" );

    Position TmpCell;
    int count = 0;

    TmpCell = L;
    while ( TmpCell != NULL && TmpCell != P ) {
        TmpCell = TmpCell->next;
        count++;
    }

    return count;
}

ElementType retrieve( Position P ) {
    return P->element;
}

int length( LinkedList L ) {
    int count;
    Position P;

    count = 0;
    P = L->next;
    while ( P != NULL ) {
        P = P->next;
        count++;
    }

    return count;
}

Position findPrevious( LinkedList L, int i ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    Position P;
    int count;
    P = L;
    count = 0;
    while ( count < i - 1 ) {
        P = P->next;
        count++;
    }

    return P;
}

Position findValuePrevious( LinkedList L, ElementType value ) {
    Position P;

    P = L;
    while ( P->next != NULL && P->next->element != value )
        P = P->next;

    return P;
}

Position findPositionPrevious( LinkedList L, Position P ) {
    Position Tmp;

    Tmp = L;
    while ( Tmp->next != NULL && Tmp->next != P )
        Tmp = Tmp->next;

    return Tmp;
}

Position find( LinkedList L, int i ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    return findPrevious( L, i )->next;

    //    Position P;
    //    int count;
    //    P = L;
    //    count = 0;
    //    while ( count < i ) {
    //        P = P->next;
    //        count++;
    //    }
    //
    //    return P;
}

Position findValue( LinkedList L, ElementType value ) {
    Position P;

    return findValuePrevious( L, value )->next;

    //    P = L->next;
    //    while ( P != NULL && P->element != value )
    //        P = P->next;
    //
    //    return P;
}

void headInsert( LinkedList L, ElementType value ) {
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = value;
    TmpCell->next = L->next;
    L->next = TmpCell;
}

// TODO 需要性能改进
void tailInsert( LinkedList L, ElementType value ) {
    Position P, TmpCell;

    P = L;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = value;
    while ( !isLast( L, P ) )
        P = P->next;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

// 结点前插操作有两种实现方法,一是通过实现的查找前结点和结点后插操作,二是通过结点后插交换结点元素值
void insertPrior( LinkedList L, int i, ElementType value ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    Position P;
    P = find( L, i );
    insertPriorPosition( L, P, value );

    //    Position P, TmpCell;
    //    P = find( L, i );
    //    TmpCell = malloc( sizeof( struct Node ) );
    //    TmpCell->element = P->element;
    //    P->element = value;
    //    TmpCell->next = P->next;
    //    P->next = TmpCell;
}

void insertPriorPosition( LinkedList L, Position P, ElementType value ) {
    Position TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = P->element;
    P->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void insertNext( LinkedList L, int i, ElementType value ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    Position P;
    P = find( L, i );
    insertNextPosition( L, P, value );
}

void insertNextPosition( LinkedList L, Position P, ElementType value ) {
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void deletePosition( LinkedList L, Position P ) {
    Position TmpCell;

    if ( P->next != NULL ) {
        TmpCell = P->next;
        P->element = TmpCell->element;
        P->next = TmpCell->next;
        free( TmpCell );
    } else {
        TmpCell = findPositionPrevious( L, P );
        TmpCell->next = P->next;
        free( P );
    }
}

void deleteValue( LinkedList L, ElementType value ) {
    Position P, TmpCell;

    P = findValuePrevious( L, value );

    if ( !isLast( L, P ) ) {
        TmpCell = P->next;
        P->next = TmpCell->next;
        free( TmpCell );
    }
}

void delete ( LinkedList L, int i ) {
    deletePosition( L, find( L, i ) );
}

void deleteList( LinkedList L ) {
    Position P, Tmp;

    P = L->next;
    L->next = NULL;
    while ( P != NULL ) {
        Tmp = P->next;
        free( P );
        P = Tmp;
    }
}

void printList( LinkedList L ) {
    Position P;

    P = L->next;
    while ( P != NULL ) {
        printf( "%d", P->element );
        P = P->next;
    }
    printf( "\n" );
}

int main() {
    LinkedList L;
    L = makeEmpty( L );
    for ( int i = 0; i < 5; ++i ) {
        tailInsert( L, i );
    }
    printList( L );
    delete ( L, position( L, findValue( L, 5 ) ) );
    printList( L );
}
