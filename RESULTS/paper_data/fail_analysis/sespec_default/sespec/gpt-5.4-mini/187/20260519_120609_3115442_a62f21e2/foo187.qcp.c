#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo187(int size, int * array, int array_len);

int foo187(int size, int * array, int array_len) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100 &&
    (1 <= c) &&
(max >= 1) &&
(exists (k:Z), 0 <= k && k < c => f == array_l[k]) &&
(array_len == array_len@pre) &&
(size == size@pre) &&
(forall (i:Z), 0 <= i && i < array_len => array_l[i] == array_l[i]@pre
          loop assigns c, f, max)
    */
    
            for (int c = 1; c < size; c++) {
			if (f > array[c]) {
				f = array[c];
				max = 1;
			} else if (f == array[c]) {
				max++;
			}
		}
		return max;
}