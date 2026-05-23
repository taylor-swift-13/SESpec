#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cntodd : Z -> Z -> Z -> Z) */
/*@ Extern Coq (last_odd_idx : Z -> Z -> Z -> Z) */
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
    (0 <= start && start <= index) &&
    (start == cntodd(ints, 0, index)) &&
    ((last_odd_idx(ints, 0, index) == -1) => ret == 0) &&
    ((last_odd_idx(ints, 0, index) != -1) => (0 <= last_odd_idx(ints, 0, index) < index)) &&
    (forall (k:Z), 0 <= k && k < index => (ints_l[k] == ints_l[k]@pre)) &&
    ((index == array) => (start == cntodd(ints, 0, array))) &&
    ((index < array@pre) => (0 <= index && index < array)) &&
    ((index < array@pre) => (start == 0 => ret == 0)) &&
    ((index < array@pre) => (start >= 1 => last_odd_idx(ints,0,index) != -1)) &&
    ((index < array@pre) => (cntodd(ints,0,index) == start)) &&
    ((index < array@pre) => (ints == ints@pre)) &&
    ((index < array@pre) => (ints_len == ints_len@pre)) &&
    ((index < array@pre) => (array == array@pre)) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre) &&
    (forall (k:Z), 0 <= k && k < index => ints_l[k] == ints_l[k]@pre)
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