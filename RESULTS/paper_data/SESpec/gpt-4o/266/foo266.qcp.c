#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
int foo266(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= index && index <= Array) &&
    (0 <= start && start <= count_odd(array, 0, index)) &&
    (forall (k:Z), 0 <= k && k < index => array_l[k] == array_l[k]@pre) &&
    (Array == Array@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre)
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