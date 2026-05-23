#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo61_c203(int * array, int array_len, int Array);

int foo61_c203(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100 &&
    ((0 < Array@pre && 1 < Array@pre) => (find + cnt_eq(array, offset, max, Array) == cnt_eq(array, 0, 1, Array))) &&
((0 < Array@pre && 1 < Array@pre) => (1 <= max && 0 <= offset)) &&
((!(0 < Array@pre && 1 < Array@pre)) => ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == Array@pre)&&(array_len == array_len@pre)&&(array == array@pre))) &&
(Array == Array@pre) &&
(array_len == array_len@pre) &&
(array == array@pre) &&
(forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre 
          loop assigns offset, max, find)
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