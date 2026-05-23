#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo329(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int max = 0;
	
 	/*@ Inv
    (1 <= j) &&
    (0 <= ret) &&
    (j == 1 => ret == 0) &&
    (j >= 2 => ret >= 1) &&
    (j >= 2 => ret >= (j-1)*(j-1)*(j-1)) &&
    (diff == diff@pre) &&
    (max == 0)
    */
for (int j = 1; j <= diff; j++) {
        ret += j * j * j;
    }
	
 	/*@ Inv
    (1 <= j) &&
    (0 <= max) &&
    (j == 1 => max == 0) &&
    (j >= 2 => max >= 1) &&
    (diff == diff@pre) &&
    (j >= 2 => max >= (j-1)) &&
    (j >= 2 => max >= (j*(j-1))/2) &&
    ((j <= diff) => (j <= diff@pre))
    */
for (int j = 1; j <= diff; j++) {
        max += j;
    }
		return ret - max;
}