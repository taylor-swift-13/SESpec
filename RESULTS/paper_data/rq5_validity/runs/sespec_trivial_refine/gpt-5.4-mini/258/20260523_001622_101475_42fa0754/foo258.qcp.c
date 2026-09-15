#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo258(int * i, int i_len, int array) 
/*@
With i_l
Require store_int_array(i, i_len, i_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int stop = array - 1;
	
 	/*0*/ 
 /*@ Inv
    exists  i_l,    
    store_int_array(i, i_len, i_l) &&
    (0 <= ret) &&
    (-1 <= stop) &&
    (ret <= stop + 1) &&
    (forall (k:Z), 0 <= k && k < ret => i_l[k] < k) &&
    (forall (k:Z), stop < k && k < array => i_l[k] > k)
    */
while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}