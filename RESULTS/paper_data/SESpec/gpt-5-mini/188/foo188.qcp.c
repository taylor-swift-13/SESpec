#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_val : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (slice_min : Z -> Z -> Z -> Z) */
int foo188(int size, int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

	
 	/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (1 <= c && c <= size) &&
    (0 <= max && max <= c) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
    (f == slice_min(a, 0, c)) &&
    (1 <= max)
    */
for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				max = 1;
			} else if (f == a[c]) {
				max++;
			}
		}
		return max;
}