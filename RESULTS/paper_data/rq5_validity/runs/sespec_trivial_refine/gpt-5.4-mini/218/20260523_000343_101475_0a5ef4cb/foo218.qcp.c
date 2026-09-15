#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (exists_in_range : Z -> Z -> Z -> Z -> Prop) */
int foo218(int * args, int args_len, int Array, int n) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int i = 0;
		int hi = n - 1;
		int result = -1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    ((i == 0) || (0 <= i && i <= hi + 1)) &&
    (hi < n) &&
    (result == -1 || (0 <= result && result < n && args_l[result] == Array))
    */
while (i <= hi) {
        int tmp = (i + hi) / 2;
        if (args[tmp] == Array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < Array) {
            i = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }
		return result;
}