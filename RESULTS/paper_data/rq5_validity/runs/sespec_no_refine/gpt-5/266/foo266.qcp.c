#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo266(int * array, int array_len, int Array);

int foo266(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100 &&
    (Array == Array@pre) &&
(array_len == array_len@pre) &&
(array == array@pre) &&
((index < Array@pre) => ((start == 0) || (start > 0))) &&
(Array == Array@pre) &&
(array_len == array_len@pre) &&
(array == array@pre) &&
(forall (k:Z), 0 <= k && k < Array => array_l[k] == array_l[k]@pre 
          loop assigns index, ret, start)
    */
    
            for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}