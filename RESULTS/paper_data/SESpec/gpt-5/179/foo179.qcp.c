#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo179(int * array, int array_len, int count) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre) &&
    (array == array@pre) &&
    (array_len == array_len@pre) &&
    (count == count@pre) &&
    ((count > 0) => (0 <= r && r <= top && top <= count@pre - 1)) &&
    ((count > 0) => (1 <= r + 1 && r + 1 <= count@pre)) &&
    ((count <= 0) => (r == 0 && top == count@pre - 1)) &&
    ((r >= top) => ((count > 0) => (1 <= r + 1 && r + 1 <= count@pre)))
    */
while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
		return r + 1;
}