#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sorted_prefix : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (binary_search_progress : Z -> Z -> Z -> Z -> Prop) */
int foo217(int * args, int args_len, int x, int y) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int i = 0;
		int r = y - 1;
		int k = -1;

	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= i) &&
    (-1 <= r && r < args_len) &&
    (i <= args_len) &&
    (-1 <= k && k < args_len) &&
    (forall (j:Z), 0 <= j && j < args_len => args_l[j] == args_l[j]@pre) &&
    (binary_search_progress(args, i, r + 1, x))
    */
while (i <= r) {
        int tmp = (i + r) / 2;
        if (args[tmp] == x) {
            k = tmp;
            i = tmp + 1;
        } else if (args[tmp] < x) {
            i = tmp + 1;
        } else {
            r = tmp - 1;
        }
    }

		return k;
}