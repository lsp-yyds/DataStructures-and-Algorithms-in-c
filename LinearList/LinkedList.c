//
// Created by bruce on 8/20/22.
//

#include "LinkedList.h"
#include "../Fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    struct Node *next;
};

LinkedList makeEmpty( LinkedList L ) {
    L = malloc( sizeof( struct Node ) );
    if ( L == NULL )
        FatalError( "Out of space!!!" );
    L->next = NULL;
    return L;
}

bool isEmpty( LinkedList L ) {
    return L->next == NULL;
}

bool isLast( LinkedList L, LNode P ) {
    return P->next == NULL;
}

LNode header( LinkedList L ) {
    return L;
}

LNode first( LinkedList L ) {
    return L->next;
}

LNode advance( LNode P ) {
    return P->next;
}

ElementType retrieve( LNode P ) {
    return P->element;
}

int length( LinkedList L ) {
    int count;
    LNode P;

    count = 0;
    P = L->next;
    while ( P != NULL ) {
        P = P->next;
        count++;
    }

    return count;
}

bool checkNode( LinkedList L, LNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    LNode TmpCell;
    TmpCell = L->next;
    while ( TmpCell != NULL && TmpCell != P )
        TmpCell = TmpCell->next;
    return TmpCell == P;
}

LNode findPositionPrevious( LinkedList L, int i ) {
    if ( i < 1 || i > length( L ) )
        FatalError( "Illegal index!!!" );

    LNode P;
    int count;
    P = L;
    count = 0;
    while ( count < i - 1 ) {
        P = P->next;
        count++;
    }

    return P;
}

LNode findValuePrevious( LinkedList L, ElementType value ) {
    LNode P;

    P = L;
    while ( P->next != NULL && P->next->element != value )
        P = P->next;

    if ( P->next == NULL )
        FatalError( "LinkedList don't have this value!!!" );

    return P;
}

LNode findNodePrevious( LinkedList L, LNode P ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    LNode TmpCell;
    TmpCell = L;
    while ( TmpCell->next != NULL && TmpCell->next != P )
        TmpCell = TmpCell->next;
    if ( TmpCell->next == NULL )
        FatalError( "LinkedList don't have this node" );

    return TmpCell;
}

LNode findPosition( LinkedList L, int i ) {
    return findPositionPrevious( L, i )->next;

    //    LNode P;
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

LNode findValue( LinkedList L, ElementType value ) {
    return findValuePrevious( L, value )->next;

    //    P = L->next;
    //    while ( P != NULL && P->element != value )
    //        P = P->next;
    //
    //    return P;
}

LNode findLastNode( LinkedList L ) {
    LNode P;
    P = L;
    while ( !isLast( L, P ) )
        P = P->next;

    return P;
}

int findNodePosition( LinkedList L, LNode P ) {
    if ( P == NULL )
        FatalError( "Invalid node!!!" );

    LNode TmpCell;
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

void updateNode( LinkedList L, LNode P, ElementType value ) {
    checkNode( L, P );
    P->element = value;
}

void updateValue( LinkedList L, ElementType targetValue, ElementType value ) {
    updateNode( L, findValue( L, targetValue ), value );
}

void updatePosition( LinkedList L, int i, ElementType value ) {
    updateNode( L, findPosition( L, i ), value );
}

void headInsert( LinkedList L, ElementType value ) {
    LNode TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = value;
    TmpCell->next = L->next;
    L->next = TmpCell;
}

// TODO 需要性能改进
void tailInsert( LinkedList L, ElementType value ) {
    LNode P, TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    P = findLastNode( L );
    TmpCell->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void insertNodePrevious( LinkedList L, LNode P, ElementType value ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    if ( P == L )
        FatalError( "Can't insert before the head node!!!" );

    LNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    TmpCell->element = P->element;
    P->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

// 结点前插操作有两种实现方法,一是通过实现的查找前结点和结点后插操作,二是通过结点后插交换结点元素值
void insertPositionPrevious( LinkedList L, int i, ElementType value ) {

    insertNodePrevious( L, findPosition( L, i ), value );

    //    LNode P, TmpCell;
    //    P = findPosition( L, i );
    //    TmpCell = malloc( sizeof( struct Node ) );
    //    TmpCell->element = P->element;
    //    P->element = value;
    //    TmpCell->next = P->next;
    //    P->next = TmpCell;
}

void insertNodeFollowing( LinkedList L, LNode P, ElementType value ) {
    if ( P == NULL )
        FatalError( "Illegal node!!!" );

    LNode TmpCell;
    TmpCell = malloc( sizeof( struct Node ) );
    if ( TmpCell == NULL )
        FatalError( "Out of space!!!" );

    TmpCell->element = value;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void insertPositionFollowing( LinkedList L, int i, ElementType value ) {
    insertNodeFollowing( L, findPosition( L, i ), value );
}

void deleteNode( LinkedList L, LNode P ) {
    if ( P == L )
        FatalError( "Please use deleteList function to delete list!!!" );

    LNode TmpCell;
    TmpCell = findNodePrevious( L, P );
    TmpCell->next = P->next;
    free( P );

    //    if ( P->next != NULL ) {
    //        TmpCell = P->next;
    //        P->element = TmpCell->element;
    //        P->next = TmpCell->next;
    //        free( TmpCell );
    //    } else {
    //        TmpCell = findNodePrevious( L, P );
    //        TmpCell->next = P->next;
    //        free( P );
    //    }
}

void deleteValue( LinkedList L, ElementType value ) {
    deleteNode( L, findValue( L, value ) );

    //    P = findValuePrevious( L, value );
    //
    //    if ( !isLast( L, P ) ) {
    //        TmpCell = P->next;
    //        P->next = TmpCell->next;
    //        free( TmpCell );
    //    }
}

void deletePosition( LinkedList L, int i ) {
    deleteNode( L, findPosition( L, i ) );
}

void deleteList( LinkedList L ) {
    LNode P, Tmp;

    P = L->next;
    L->next = NULL;
    while ( P != NULL ) {
        Tmp = P->next;
        free( P );
        P = Tmp;
    }
}

void printList( LinkedList L ) {
    LNode P;

    P = L->next;
    printf( "head->" );
    while ( P != NULL ) {
        printf( "%d->", P->element );
        P = P->next;
    }
    printf( "NULL" );
    printf( "\n" );
}

int main() {
    LinkedList L;
    L = makeEmpty( L );
    int i;
    scanf( "%d", &i );
    while ( i != 9999 ) {
        tailInsert( L, i );
        scanf( "%d", &i );
    }
    printList( L );
    LNode S;
    S->element = 10;
    printf( "%d\n", findNodePrevious( L, S )->element );
    printList( L );
}
