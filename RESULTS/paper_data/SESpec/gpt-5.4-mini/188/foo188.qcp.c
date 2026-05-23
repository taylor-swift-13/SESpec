#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo188(int size, int * a, int a_len);

int foo188(int size, int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (a_len == a_len@pre) &&
(a == a@pre) &&
(size == size@pre) &&
(forall (k:Z), 0 <= k && k < c => f <= a_l[k]) &&
(exists (k:Z), 0 <= k && k < c && f == a_l[k]) &&
(1 <= max && max <= c) &&
(max >= 1) &&
(max <= c
          loop assigns c, f, max)
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