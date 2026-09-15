#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (ints_unchanged : Z -> Z -> Prop) */
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
    (0 <= find && find <= offset) &&
    (0 <= find && find <= max) &&
    (offset <= array) &&
    (1 <= max && max <= array) &&
    (offset + max - 2 * find >= 1) &&
    (find <= offset && find <= max) &&
    ((0 < array@pre && 1 < array@pre) => (find <= offset && find <= max && offset <= array && max <= array)) &&
    ((0 < array@pre && 1 < array@pre) => (find >= 0)) &&
    ((0 < array@pre && 1 < array@pre) => (offset >= 0 && max >= 0)) &&
    ((!(0 < array@pre && 1 < array@pre)) => ((max == 1)&&(offset == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre) &&
    (forall (k:Z), 0 <= k && k < ints_len => ints_l[k] == ints_l[k]@pre)
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