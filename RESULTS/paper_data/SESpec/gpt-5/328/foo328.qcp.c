#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo328(int diff) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
	
 	/*@ Inv
    (c >= 1) &&
    (diff == diff@pre) &&
    (max == 0) &&
    (result >= 0) &&
    (c == 1 => result == 0) &&
    (c >= 2 => result >= (c - 1) * (c - 1) * (c - 1)) &&
    (forall (k:Z), 1 <= k && k < c => k >= 1) &&
    ((c <= diff@pre) => (c >= 1)) &&
    ((c <= diff@pre) => (result >= 0)) &&
    (!(c <= diff@pre) => ((max == 0) && (result >= 0) && (diff == diff@pre)))
    */
for (int c = 1; c <= diff; c++) {
        result += c * c * c;
    }
	
 	/*@ Inv
    (1 <= c) &&
    (diff == diff@pre) &&
    (max >= 0) &&
    (c == 1 => max == 0) &&
    (c >= 2 => max >= c - 1) &&
    (c >= 2 => max >= (c - 1)) &&
    (c >= 2 => max <= (c - 1) * diff) &&
    ((c <= diff) => (max + c >= max))
    */
for (int c = 1; c <= diff; c++) {
        max += c;
    }
		return result - max;
}