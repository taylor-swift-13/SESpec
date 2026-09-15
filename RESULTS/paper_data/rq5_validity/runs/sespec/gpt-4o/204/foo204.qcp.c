#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo204(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l)
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) &&
    (0 <= offset && offset <= array) &&
    (1 <= max && max <= array + 1) &&
    (0 <= find && find <= offset) &&
    ((0 < array && 1 < array) => (offset <= max)) &&
    ((0 < array && 1 < array) => (max <= array + 1)) &&
    ((!(0 < array && 1 < array)) => ((max == 1)&&(offset == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre)
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