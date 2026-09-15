#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo187(int size, int * array, int array_len) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (1 <= c) &&
    (0 <= c && c <= size) &&
    (0 <= max && max <= c) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < c => f <= array_l[k]) &&
    ((c < size) => (0 <= c && c < array_len)) &&
    ((!(c < size)) => (c >= size)) &&
    (forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre)
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