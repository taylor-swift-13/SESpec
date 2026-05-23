#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo77_c218(int * args, int args_len, int Array, int n);

int foo77_c218(int * args, int args_len, int Array, int n) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int i = 0;
		int hi = n - 1;
		int result = -1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (0 <= i && i <= n) &&
(-1 <= hi && hi < n) &&
(n == n@pre) &&
(Array == Array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(\valid_read(args + (0 .. args_len-1))) &&
(sorted(args, 0, args_len)) &&
((result == -1) || (0 <= result && result < n && args_l[result] == Array)
          loop assigns result, hi, i)
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