#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
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
    (0 <= i && i <= n) &&
    (-1 <= hi && hi < n) &&
    (-1 <= result && result < n) &&
    ((result == -1) || (args_l[result] == Array)) &&
    ((result == -1) => (i <= hi + 1))
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