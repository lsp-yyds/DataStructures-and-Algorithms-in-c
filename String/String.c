//
// Created by bruce on 8/30/22.
//

#include "String.h"
#include "../Fatal.h"
#include <stdlib.h>

struct String {
    char *element;
    int strLength;
};

String createString() {
    String str = malloc( sizeof( struct String ) );
    if ( str == NULL )
        FatalError( "Out of space!!!" );
    makeEmpty( str );
    return str;
}

String strAssign( const char *s ) {
    int i, count;
    i = 0;
    count = 0;
    while ( s[ i ] != '\0' ) {
        i++;
        count++;
    }
    String str = malloc( sizeof( struct String ) );
    str->element = malloc( sizeof( char ) * count );
    for ( i = 0; s[ i ] != '\0'; i++ ) {
        str->element[ i ] = s[ i ];
    }
    str->strLength = count;
    return str;
}

void makeEmpty( String str ) {
    str->strLength = 0;
}

bool strEmpty( String str ) {
    return str->strLength == 0;
}

int strIndex( String str, String sub ) {
    // 朴素模式匹配思想

    int i = 1;
    String s;
    while ( i <= str->strLength - sub->strLength + 1 ) {
        s = subString( str, i, sub->strLength );
        if ( strCompare( s, sub ) != 0 )
            i++;
        else
            return i;
    }
    Error( "The substring is not included in the string!!!" );
    // return 0;

    //    int i, j;
    //    for ( i = 0; i < str->strLength; i++ ) {
    //        if ( str->element[ i ] == sub->element[ 0 ] ) {
    //            for ( j = i; j < i + sub->strLength; ++j ) {
    //                if ( str->element[ j ] != sub->element[ j - i ] )
    //                    break;
    //            }
    //        }
    //        if ( j == i + sub->strLength )
    //            return i + 1;
    //    }
    //    Error( "The substring is not included in the string!!!" );
}

int *getNext( String sub ) {
    int *next = malloc( sizeof( int ) * ( sub->strLength + 1 ) );
    next[ 1 ] = 0;
    int i, count;
    i = 1;
    count = 0;
    while ( i < sub->strLength ) {
        if ( count == 0 || sub->element[ i ] == sub->element[ count ] ) {
            i++;
            count++;
        }
    }
}

int strIndex_KMP( String str, String sub, int next[] ) {
}

void strCopy( String str, String s ) {
    str->element = malloc( sizeof( char ) * s->strLength );
    for ( int i = 0; i < s->strLength; ++i ) {
        str->element[ i ] = s->element[ i ];
    }
    str->strLength = s->strLength;
}

int strCompare( String str, String s ) {
    for ( int i = 0; i < str->strLength && i < s->strLength; ++i ) {
        if ( str->element[ i ] != s->element[ i ] )
            return str->element[ i ] - s->element[ i ];
    }
    return str->strLength - s->strLength;
}

int strLength( String str ) {
    return str->strLength;
}

void strConcat( String str, String s1, String s2 ) {
    str->element = malloc( sizeof( char ) * ( s1->strLength + s2->strLength ) );
    for ( int i = 0; i < s1->strLength; ++i )
        str->element[ i ] = s1->element[ i ];
    for ( int i = s1->strLength; i < s1->strLength + s2->strLength; ++i )
        str->element[ i ] = s2->element[ i - s1->strLength ];
    str->strLength = s1->strLength + s2->strLength;
}

String subString( String str, int index, int size ) {
    if ( index < 1 || index > str->strLength )
        Error( "Illegal index!!!" );

    if ( index + size - 1 > str->strLength )
        Error( "The substring is not included in the string" );

    String s = malloc( sizeof( struct String ) );
    if ( s == NULL )
        FatalError( "Out of space!!!" );

    s->element = malloc( sizeof( char ) * size );
    for ( int i = 0; i < size; ++i ) {
        s->element[ i ] = str->element[ index - 1 + i ];
    }
    s->strLength = size;
    return s;
}

void disposeString( String str ) {
    free( str->element );
    free( str );
}

void printString( String str ) {
    for ( int i = 0; i < str->strLength; ++i ) {
        printf( "%c", str->element[ i ] );
    }
    printf( "\n" );
}

int main() {
    String str = createString();
    String s = createString();
    str = strAssign( "Hello World!" );
    s = strAssign( "World!" );
    printf( "%d", strIndex( str, s ) );

    return 0;
}