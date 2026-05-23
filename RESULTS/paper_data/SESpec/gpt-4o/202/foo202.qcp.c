#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
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
    (0 <= min && min <= array) &&
    (1 <= offset && offset <= array) &&
    (0 <= find && find <= min) &&
    ((0 < array@pre && 1 < array@pre) => (min >= 0 && min <= array)) &&
    ((0 < array@pre && 1 < array@pre) => (offset >= 1 && offset <= array)) &&
    ((!(0 < array@pre && 1 < array@pre)) => ((offset == 1)&&(min == 0)&&(find == 0)&&(array == array@pre)&&(ints_len == ints_len@pre)&&(ints == ints@pre))) &&
    (array == array@pre) &&
    (ints_len == ints_len@pre) &&
    (ints == ints@pre) &&
    (forall (k:Z), 0 <= k && k < ints_len => ints_l[k] == ints_l[k]@pre)
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