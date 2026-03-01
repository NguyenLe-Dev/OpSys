#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

// know that if a float is p.q --> 17.14
// where one bit for signed bit, 17 for integer and 14 for fraction

// (1<<14)
// below is a series of callable macros to allow for float operations

// n is int
// x is floats

#define INT_TO_FLOAT(n) ((n) <<14)

// NOTE, this rounds towards 0
#define FLOAT_TO_INT_0(x) ((x) >> 14)

// Rounds a float to nearest int
// should be used for scheduler data
// load_avg, recent_cpu
#define FLOAT_TO_INT_NEAREST(x) ( ( x >= 0 ) ? ( ( (x) + ( 1 << 13 ) ) >> 14 ): ( ( (x) - ( 1 << 13 ) ) >> 14 ) )

#define ADD_FLOATS(x,y) ((x)+(y))
#define SUB_FLOATS(x,y) ((x)-(y))

// usage ADD_MIX(float, int)
#define ADD_FLOAT_INT(x,n) ((x)+( (n) << 14 ) )
#define SUB_FLOAT_INT(x,n) ((x)-( (n) << 14 ) )
#define SUB_INT_FLOAT(n,x) (( (n) << 14 ) - (x) )

// DW about cast
// MULT_FLOATS returns integer form
#define MULT_FLOATS(x,y) ( ( (int64_t)(x) * (y) ) >>14 )

#define MULT_FLOAT_INT(x,n) ((x)*(n))

#define DIV_FLOATS(x,y) ( ( (int64_t)(x) << 14 )  / (y) )
#define DIV_FLOAT_INT(x,n) ((x)/(n))

#endif