#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo203(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= offset && offset <= Array) &&
    (1 <= max && max <= Array) &&
    (0 <= find && find <= offset) &&
    (forall (k:Z), 0 <= k && k < offset => array_l[k] == array_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < max => array_l[k] == array_l[k]@pre) &&
    (forall (v:Z), 0 <= v && v < Array => count_eq(array, 0, array_len, v) == \at(count_eq(array, 0, array_len, v), Pre)) &&
    ((!(0 < Array@pre && 1 < Array@pre)) => ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == Array@pre)&&(array_len == array_len@pre)&&(array == array@pre))) &&
    (Array == Array@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre)
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