#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_matches : Z -> Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (pair_count : Z -> Z -> Z -> Z -> Z) */
int foo244(int * array, int array_len, int num, int p) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= index && index <= num) &&
    (0 <= ret) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre)
    */
for (int index = 0; index < num; index++) {

            /*@
              loop invariant index + 1 <= j <= num;
              loop invariant 0 <= ret;
              loop invariant p == \at(p,Pre);
              loop invariant num == \at(num,Pre);
              loop invariant array_len == \at(array_len,Pre);
              loop invariant array == \at(array,Pre);
              loop assigns j, ret;
            */
            /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (index + 1 <= j && j <= num) &&
    (0 <= ret) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre)
    */
for (int j = index + 1; j < num; j++) {
                if (array[index] + array[j] == p) {
                    ret++;
                }
            }

        }
		return ret;
}