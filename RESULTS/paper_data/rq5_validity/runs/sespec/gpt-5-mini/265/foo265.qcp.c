#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
int foo265(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) &&
    (0 <= index) &&
    (index <= array@pre) &&
    (0 <= start && start <= index) &&
    (start == count_odd(ints, 0, index)) &&
    ((ret == 0) || (exists (k:Z), 0 <= k && k < index && (count_odd(ints, 0, k+1) % 2 == 1) && ints_l[k] == ret)) &&
    ((!(index < array)) => (start == count_odd(ints, 0, array))) &&
    ((!(index < array)) => ((ret == 0) || (exists (k:Z), 0 <= k && k < array && (count_odd(ints, 0, k+1) % 2 == 1) && ints_l[k] == ret))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre) &&
    (forall (k:Z), 0 <= k && k < ints_len => ints_l[k] == ints_l[k]@pre)
    */
for (int index = 0; index < array; index++) {
        if (ints[index] % 2 != 0) {
            start++;
            if (start % 2 != 0) {
                ret = ints[index];
            }
        }
    }
		return ret;
}