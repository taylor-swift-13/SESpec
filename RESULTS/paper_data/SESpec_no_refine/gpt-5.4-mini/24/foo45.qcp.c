#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo45(int size, int * array, int array_len);

int foo45(int size, int * array, int array_len) 
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
    (array_len == array_len@pre) &&
(array == array@pre) &&
(size == size@pre) &&
(forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre
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