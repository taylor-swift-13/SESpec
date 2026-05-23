#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo220(int * args, int args_len, int array, int n) 
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
    (0 <= i) &&
    (hi < n) &&
    (result >= -1) &&
    (n == n@pre) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    ((0 <= n@pre - 1) => (result == -1 || args_l[result] == array))
    */
while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}