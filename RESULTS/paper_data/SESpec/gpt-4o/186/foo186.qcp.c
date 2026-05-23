#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo186(int size, int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

	
 	/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (1 <= c && c <= size) &&
    (forall (k:Z), 0 <= k && k < c => a_l[k] >= f) &&
    (exists (k:Z), 0 <= k && k < c && a_l[k] == f) &&
    (forall (k:Z), 0 <= k && k < c => (a_l[k] == f) => (total >= 1))
    */
for (int c = 1; c < size; c++) {
        if (f > a[c]) {
            f = a[c];
            total = 1;
        } else if (f == a[c]) {
            total++;
        }
    }
		return total;
}