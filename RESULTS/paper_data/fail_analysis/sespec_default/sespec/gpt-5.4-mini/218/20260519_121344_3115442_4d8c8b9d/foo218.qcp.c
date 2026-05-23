#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo218(int * args, int args_len, int Array, int n);

int foo218(int * args, int args_len, int Array, int n) 
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
    ((0 <= n@pre - 1) => (0 <= i && i <= hi + 1)) &&
((0 <= n@pre - 1) => (((result == -1)&&(hi == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= i && i <= n@pre))) &&
((0 <= n@pre - 1) => (((result == -1)&&(hi == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= hi + 1 <= n@pre))) &&
((0 <= n@pre - 1) => (((result == -1)&&(hi == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (result == -1 || (0 <= result && result <= n@pre - 1 && args_l[result] == Array)))) &&
((!(0 <= n@pre - 1)) => ((result == -1)&&(hi == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(n == n@pre) &&
(Array == Array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre
          loop assigns i, hi, result)
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