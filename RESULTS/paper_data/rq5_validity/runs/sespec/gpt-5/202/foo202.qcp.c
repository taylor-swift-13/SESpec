#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo202(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l)
Ensure Results(__return)
*/{

		int find = 0;
		int min = 0;
		int offset = 1;

	
 	/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) &&
    (0 <= min) &&
    (1 <= offset) &&
    (0 <= find) &&
    (min <= offset) &&
    (forall (k:Z), 0 <= k && k < ints_len => ints_l[k] == ints_l[k]@pre) &&
    (find <= min) &&
    (find <= offset) &&
    (!(min < array && offset < array) => (min >= array || offset >= array)) &&
    ((0 < array@pre && 1 < array@pre) => (0 <= min && 1 <= offset)) &&
    ((0 < array@pre && 1 < array@pre) => (0 <= find)) &&
    ((!(0 < array@pre && 1 < array@pre)) => ((offset == 1)&&(min == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre)
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