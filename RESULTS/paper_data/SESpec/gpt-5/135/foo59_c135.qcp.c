#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo59_c135(int x, int n);

int foo59_c135(int x, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 1;
        for(int i = 0; i < n; i++)
	    res = res * x;
        return res;
}