#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo204(int * ints, int ints_len, int array);

int foo204(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100 &&
    ((0 < array@pre && 1 < array@pre) => (0 <= find && find <= offset && find <= max && offset <= array && max <= array)) &&
((0 < array@pre && 1 < array@pre) => (0 <= find) ) &&
((0 < array@pre && 1 < array@pre) => (0 <= offset && offset <= array) ) &&
((0 < array@pre && 1 < array@pre) => (1 <= max && max <= array) ) &&
((!(0 < array@pre && 1 < array@pre)) => ((max == 1)&&(offset == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
(array == array@pre) &&
(ints_len == ints_len@pre) &&
(ints == ints@pre) &&
(forall (i:Z), 0 <= i && i < ints_len => ints_l[i] == ints_l[i]@pre
          loop assigns offset, max, find)
    */
    
            while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
}