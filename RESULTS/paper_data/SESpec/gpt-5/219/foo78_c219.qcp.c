#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo78_c219(int * args, int args_len, int array, int n);

int foo78_c219(int * args, int args_len, int array, int n) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int hi = n - 1;
		int result = -1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (n == n@pre) &&
(array == array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(\valid_read(args + (0 .. n - 1))) &&
(sorted(args, 0, n)) &&
(-1 <= hi && hi < n) &&
(0 <= ret && ret <= hi + 1) &&
(result == -1 || (0 <= result && result < n && args_l[result] == array)
          loop assigns result, hi, ret)
    */
    
            while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}