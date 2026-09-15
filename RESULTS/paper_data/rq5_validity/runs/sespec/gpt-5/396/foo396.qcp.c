#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo396(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*0*/ 
 /*@ Inv
    (1 <= c && c <= p + 1) &&
    (even == \sum(integer k 1 <= k && k < c (2*k)*(2*k)*(2*k)*(2*k))) &&
    (even >= 0) &&
    (c == 1 => even == 0) &&
    (forall (k:Z), 1 <= k && k < c => (2*k)*(2*k)*(2*k)*(2*k) >= 0) &&
    (p == p@pre) &&
    ((c <= p@pre) => (even == \sum(integer k 1 <= k && k < c (2*k)*(2*k)*(2*k)*(2*k)))) &&
    ((!(c <= p@pre)) => ((even == 0)&&(p == p@pre)))
    */
for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}