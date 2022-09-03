//
// Created by bruce on 9/3/22.
//

#include "kmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_table( const char pattern[], int prefix[], int n ) {
    prefix[ 0 ] = 0;
    int len = 0;
    int i = 1;

    while ( i < n ) {
        if ( pattern[ i ] == pattern[ len ] ) {
            len++;
            prefix[ i ] = len;
            i++;
        } else {
            if ( len > 0 ) {
                len = prefix[ len - 1 ];
            } else {
                prefix[ i ] = len;
                i++;
            }
        }
    }
}

void move_prefix_table( int prefix[], int n ) {

    for ( int i = n - 1; i > 0; i-- ) {
        prefix[ i ] = prefix[ i - 1 ];
    }

    prefix[ 0 ] = -1;
}

void kmp_search( const char text[], const char pattern[] ) {
    int n = (int) strlen( pattern );
    int m = (int) strlen( text );
    int *prefix = malloc( sizeof( int ) * n );
    prefix_table( pattern, prefix, n );
    move_prefix_table( prefix, n );

    // pattern[j]   len(pattern) = n
    // text[i]      len(text) = m
    int i, j;
    i = 0;
    j = 0;
    while ( i < m ) {
        if ( j == n - 1 && text[ i ] == pattern[ j ] ) {
            printf( "Found pattern at %d\n", i - j + 1 );
            j = prefix[ j ];
        }
        if ( text[ i ] == pattern[ j ] ) {
            i++;
            j++;
        } else {
            j = prefix[ j ];
            if ( j == -1 ) {
                i++;
                j++;
            }
        }
    }
}

int main() {
    char pattern[] = "aaab";
    int prefix[ 9 ];
    int n = 9;
    //    char pattern[] = "ABABCABAA";
    //    char text[] = "ABABABCABAAAGJALIJGLIABABCABAA";
    //    kmp_search( text, pattern );

    //    int prefix[ 9 ];
    //    int n = 9;
    //
    prefix_table( pattern, prefix, n );
    move_prefix_table( prefix, n );

    for ( int i = 0; i < n; ++i ) {
        printf( "%d\n", prefix[ i ] );
    }

    return 0;
}