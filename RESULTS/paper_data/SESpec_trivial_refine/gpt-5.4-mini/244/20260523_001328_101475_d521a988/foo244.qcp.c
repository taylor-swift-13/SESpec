#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_current : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_prefix : Z -> Z -> Z -> Z -> Z) */
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
    (0 <= index && index <= num)
    */
for (int index = 0; index < num; index++) {
			
            /*@
          loop invariant 0 <= j <= num;
          loop invariant index < num;
          loop invariant 0 <= index <= num;
          loop assigns j, ret;
            */
            /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= j && j <= num) &&
    (index < num) &&
    (0 <= index && index <= num)
    */
for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
		return ret;
}