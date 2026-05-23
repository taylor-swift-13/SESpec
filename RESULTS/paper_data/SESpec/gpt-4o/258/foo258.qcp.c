#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (binary_search_invariant : Z -> Z -> Z -> Z -> Prop) */
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
    (0 <= ret && ret <= array) &&
    (-1 <= stop && stop < array) &&
    (ret <= stop + 1) &&
    (array == array@pre) &&
    (i_len == i_len@pre) &&
    (i == i@pre)
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