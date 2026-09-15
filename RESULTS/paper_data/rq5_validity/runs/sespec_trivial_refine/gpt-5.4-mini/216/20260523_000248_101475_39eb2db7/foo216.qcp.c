#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo216(int * array, int array_len, int x, int y) 
/*@
With array_l y_l
Require store_int_array(array, array_len, array_l) && store_int_ptr(y)
Ensure Results(__return)
*/{

		int i = 0;
		int r = y - 1;
		int k = -1;

	
 	/*@ Inv
    exists  array_l y_l,    
    store_int_array(array, array_len, array_l) && store_int_array(y, INT_MAX, y_l) &&
    (0 <= i && i <= array_len) &&
    (-1 <= r && r < array_len) &&
    (i <= r + 1) &&
    (k == -1 || (0 <= k && k < array_len && array_l[k] == x))
    */
while (i <= r) {
			int tmp = (i + r) / 2;
			if (array[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (array[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
}