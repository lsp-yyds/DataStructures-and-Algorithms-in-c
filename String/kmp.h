//
// Created by bruce on 9/3/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_KMP_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_KMP_H

void prefix_table( const char pattern[], int prefix[], int n );
void move_prefix_table( int prefix[], int n );
void kmp_search( const char text[], const char pattern[] );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_KMP_H
