#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo244(int * array, int array_len, int num, int p);

int foo244(int * array, int array_len, int num, int p) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100 &&
    ((index < num@pre) => (ret >= 0)) &&
(p == p@pre) &&
(num == num@pre) &&
(array_len == array_len@pre) &&
(array == array@pre) &&
(0 <= ret
          loop assigns index, ret)
    */
    
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@ 
              loop invariant 0 <= ret;
              loop assigns index, ret;
            */
            for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
		return ret;
}