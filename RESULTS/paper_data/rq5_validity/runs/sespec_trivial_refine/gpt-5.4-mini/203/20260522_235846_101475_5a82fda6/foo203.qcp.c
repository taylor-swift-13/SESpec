#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo203(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*0*/ 
 /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= offset && offset <= Array) &&
    (1 <= max && max <= Array) &&
    (0 <= find && find <= offset) &&
    (find < max)
    */
while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
}