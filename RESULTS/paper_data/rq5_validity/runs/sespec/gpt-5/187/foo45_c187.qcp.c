#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo45_c187(int size, int * array, int array_len);

int foo45_c187(int size, int * array, int array_len) 
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
(size == size@pre) &&
(array == array@pre) &&
(array_len == array_len@pre) &&
(forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre) &&
((c < size) => (c <= size@pre)) &&
((c == 1) => (f == array_l[0] && max == 1)) &&
((c >= 1) => (f == min_prefix_excl(array, c))) &&
(forall (k:Z), 0 <= k && k < c => f <= array_l[k]) &&
(1 <= max && max <= c
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