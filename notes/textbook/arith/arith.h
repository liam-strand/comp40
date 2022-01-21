/* arith.h
 * 
 * By: Liam Strand
 * 
 * Taken from Hanson chapter 2
 * 
 * Basic mathematical functions
 * 
 */ 

/* returns maximum of x and y */
extern int Arith_max(int x, int y);

/* returns minimum of x and y */
extern int Arith_min(int x, int y);

/* returns x / y truncated left */
extern int Arith_div(int x, int y);

/* returns x % y always positive */
extern int Arith_mod(int x, int y);

/* returns integer to right on number line of x / y */
extern int Arith_ceiling(int x, int y);

/* returns integer to left on number line of x / y */
extern int Arith_floor  (int x, int y);
