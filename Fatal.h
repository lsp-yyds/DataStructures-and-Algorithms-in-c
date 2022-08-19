//
// Created by bruce on 7/24/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_FATAL_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_FATAL_H

#include <stdio.h>
#include <stdlib.h>

#define Error( Str ) FatalError( Str )
#define FatalError( Str ) fprintf( stderr, "%s\n", Str ), exit( 1 )

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_FATAL_H
