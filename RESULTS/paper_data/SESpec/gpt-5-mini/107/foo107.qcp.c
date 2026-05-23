#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo107(int * x, int x_len) 
/*@
With x_l
Require store_int_array(x, x_len, x_l)
Ensure Results(__return)
*/{

         	assert(x_len >= 0);
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            	
 	/*@ Inv
    exists  x_l,    
    store_int_array(x, x_len, x_l) &&
    (0 <= index && index <= x_len) &&
    (x_len == x_len@pre) &&
    (true))) &&
    (forall (k:Z), 0 <= k && k < index => x_l[k] != 0) &&
    (forall (k:Z), 0 <= k && k < x_len => x_l[k] == x_l[k]@pre) &&
    ((x_len - index > 0 && x_l[index] != 0) => (0 <= index && index <= x_len - 1 && x_l[index] != 0)) &&
    ((!(x_len - index > 0 && x_l[index] != 0)) => (index == x_len || x_l[index] == 0))
    */
while (x_len - index > 0 && x[index] != 0) {
            index = index + 1;
        }
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}