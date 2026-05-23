#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

long long foo70_helper1(short x);
long long foo70_helper2(int x);
long long foo70_helper3(long long x);
long long foo70_helper4(int x, int y);
long long foo70_helper5(int x, int y, int z);
long long foo70(int w, int x, int y, int z);

long long foo70(int w, int x, int y, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

	long trapeziumPerimeter = (long)w + (long)x + (long)y + (long)z;
	return trapeziumPerimeter;
}