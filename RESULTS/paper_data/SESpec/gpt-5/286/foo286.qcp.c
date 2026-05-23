#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fib2 : Z -> Z) */
int foo286(int j) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *r = (int *)malloc(sizeof(int) * (j + 1));
int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
	
 	/*@ Inv
    (r_len == j + 1) &&
    (2 <= p => 0 <= 2 && 2 <= p) &&
    (forall (k:Z), 0 <= k && k < 2 => r[k] == fib2(k)) &&
    (forall (k:Z), 0 <= k && k < p => r[k] == fib2(k)) &&
    (forall (k:Z), 1 <= k && k < p => r[k] >= r[k-1]) &&
    (j < 2 => (forall (k:Z), 0 <= k && k <= j => r[k] == fib2(k)))
    */
for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1]
                + 2 * r[p - 2];
    }
		return r[j];
}