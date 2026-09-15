#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo60_c202(int * ints, int ints_len, int array);

int foo60_c202(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100
Ensure Results(__return)
*/{

		int find = 0;
		int min = 0;
		int offset = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100 &&
    ((min == 0 && offset == 1 && find == 0) ||
                          (min + offset + find >= 1)) &&
((0 < array@pre && 1 < array@pre) => (0 <= find && find <= (min + offset - 1))) &&
((0 < array@pre && 1 < array@pre) => (0 <= min && min <= array@pre)) &&
((0 < array@pre && 1 < array@pre) => (1 <= offset && offset <= array@pre)) &&
((!(0 < array@pre && 1 < array@pre)) => ((offset == 1)&&(min == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
(array == array@pre) &&
(ints_len == ints_len@pre) &&
(ints == ints@pre
          loop assigns min, offset, find)
    */
    
        while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
}