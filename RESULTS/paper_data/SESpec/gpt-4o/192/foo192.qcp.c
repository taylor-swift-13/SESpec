#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (compute_w : Z -> Z -> Z -> Z) */
/*@ Extern Coq (compute_C : Z -> Z -> Z -> Z) */

int foo192(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
	
 	/*0*/ 
 /*@ Inv
    (2 <= index && index <= count + 1) &&
    (forall (k:Z), 0 <= k && k < index => w[k] == compute_w(w, C, k)) &&
    (forall (k:Z), 0 <= k && k < index => C[k] == compute_C(w, C, k)) &&
    (forall (k:Z), 0 <= k && k < w_len => true) &&
    (forall (k:Z), 0 <= k && k < C_len => true)
    */
for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
		return w[count];
}