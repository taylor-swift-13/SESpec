#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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

	
 	/*0*/ 
 /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (1 <= c && c <= size) &&
    (forall (i:Z), 0 <= i && i < c => f <= array_l[i]) &&
    (exists (i:Z), 0 <= i && i < c && f == array_l[i]) &&
    (max == \numof integer i 0 <= i && i < c && array_l[i] == f)
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