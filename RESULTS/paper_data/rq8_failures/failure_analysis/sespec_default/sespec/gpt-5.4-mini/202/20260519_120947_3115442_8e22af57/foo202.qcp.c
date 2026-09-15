#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo202(int * ints, int ints_len, int array);

int foo202(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100
Ensure Results(__return)
*/{

		int find = 0;
		int min = 0;
		int offset = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100 &&
    (0 <= find) &&
(0 <= min) &&
(1 <= offset) &&
(find <= min) &&
(min <= offset) &&
(array == array@pre) &&
(ints_len == ints_len@pre) &&
(ints == ints@pre) &&
(forall (k:Z), 0 <= k && k < ints_len@pre => ints_l[k] == ints_l[k]@pre
          loop assigns min, offset, find)
    */
    
            while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
}