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
	
 	/*@ Inv
    exists  i_l,    
    store_int_array(i, i_len, i_l) &&
    (array == array@pre) &&
    (i_len == i_len@pre) &&
    (i == i@pre) &&
    ((ret <= stop) => (ret <= (ret + (stop - ret) / 2) && (ret + (stop - ret) / 2) <= stop)) &&
    (forall (k:Z), 0 <= k && k < i_len => i_l[k] == i_l[k]@pre)
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