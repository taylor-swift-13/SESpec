#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
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
    (0 <= index && index <= array) &&
    (0 <= start && start <= count_odd(ints, 0, index)) &&
    (ret == (start % 2 != 0 ? last_odd(ints, 0, index) : ret)) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] == ints_l[k]@pre)) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] % 2 != 0 => count_odd(ints, 0, k + 1) == count_odd(ints, 0, k) + 1)) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] % 2 == 0 => count_odd(ints, 0, k + 1) == count_odd(ints, 0, k))) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] % 2 != 0 => last_odd(ints, 0, k + 1) == ints_l[k])) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] % 2 == 0 => last_odd(ints, 0, k + 1) == last_odd(ints, 0, k)))
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