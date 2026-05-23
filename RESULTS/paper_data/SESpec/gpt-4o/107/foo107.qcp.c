#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_nonzero : Z -> Z -> Z -> Z) */
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
    (count_nonzero(x, 0, index) == index) &&
    (forall (i:Z), 0 <= i && i < index => x_l[i] != 0) &&
    ((x_len - index > 0 && x_l[index] != 0) => (forall (i:Z), 0 <= i && i < index => x_l[i] != 0)) &&
    ((!(x_len - index > 0 && x_l[index] != 0)) => (index == x_len || x_l[index] == 0)) &&
    (forall (i:Z), 0 <= i && i < x_len => x_l[i] == x_l[i]@pre)
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