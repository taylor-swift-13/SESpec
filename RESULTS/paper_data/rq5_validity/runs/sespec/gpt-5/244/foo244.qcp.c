#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (forall (k:Z), 0 <= k && k < num@pre => array_l[k] == array_l[k]@pre) &&
    ((index <= num@pre) => (ret >= 0)) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre)
    */
for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret >= 0;
          loop assigns ret, j;
            */
            /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (ret >= 0)
    */
for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
		return ret;
}