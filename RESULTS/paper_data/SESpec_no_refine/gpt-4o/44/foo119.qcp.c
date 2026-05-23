#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo119(int * args, int args_len, int Array);

int foo119(int * args, int args_len, int Array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int top = args_len - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (0 <= ret && ret <= args_len) &&
(-1 <= top && top < args_len) &&
(ret <= top + 1) &&
(exists (k:Z), ret <= k && k <= top => args_l[k] == Array) &&
(count_eq(args, 0, args_len, Array) == count_eq(args, 0, args_len, Array)) &&
(sum(args, 0, args_len) == sum(args, 0, args_len)
      loop assigns ret, top)
    */
    
    while (ret <= top) {
        int i = (ret + top) / 2;
        if (args[i] == Array) {
            return i;
        } else if (args[i] < Array) {
            ret = i + 1;
        } else {
            top = i - 1;
        }
    }
		return ret;
}