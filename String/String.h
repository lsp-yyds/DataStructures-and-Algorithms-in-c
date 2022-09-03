//
// Created by bruce on 8/30/22.
//

/**
 * 对于串的顺序存储有四种方案
 * 本程序是串的链式存储的实现
 * 为提高存储密度可以将struct String的element域定义加长
 */

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_STRING_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_STRING_H

#include <stdbool.h>

struct String;
typedef struct String *String;

String strAssign( const char *s );
void makeEmpty( String str );
bool strEmpty( String str );
int strIndex( String str, String sub );
int *getNext( String sub );
int strIndex_KMP( String str, String sub, int next[] );
void strCopy( String str, String s );
int strCompare( String str, String s );
int strLength( String str );
void strConcat( String str, String s1, String s2 );
String subString( String str, int index, int size );
void disposeString( String str );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_STRING_H
