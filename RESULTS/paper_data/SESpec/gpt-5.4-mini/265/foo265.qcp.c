#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
/*@ Extern Coq (selected_odd : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (last_odd : Z -> Z -> Z -> Z) */
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
    ((array < 0) || (index <= array)) &&
    (0 <= start && start <= index) &&
    (start == count_odd(ints, 0, index)) &&
    (ret == 0 || ret % 2 != 0) &&
    ((start == 0) => (ret == 0)) &&
    ((start > 0) => (ret == 0 || ret % 2 != 0)) &&
    (forall (k:Z), 0 <= k && k < index && (ints_l[k] % 2) != 0 => count_odd(ints, 0, k + 1) >= 1) &&
    ((index == array) => (start == count_odd(ints, 0, array))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre) &&
    (0 <= ints_len => (forall (k:Z), 0 <= k && k < ints_len => ints_l[k] == ints_l[k]@pre)) &&
    ((!(index < array@pre)) => (array == array@pre && ints_len == ints_len@pre && ints == ints@pre))
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