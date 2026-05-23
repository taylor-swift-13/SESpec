#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo219(int * args, int args_len, int array, int n) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int hi = n - 1;
		int result = -1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (n == n@pre) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    ((result != -1) => args_l[result] == array) &&
    ((ret <= hi) => (0 <= ret && ret <= hi + 1)) &&
    ((ret == 0) || (ret > 0)) &&
    ((hi == n - 1) || (hi < n - 1)) &&
    ((0 <= n - 1) => (((result == -1)&&(hi == n@pre - 1)&&(ret == 0)&&(n == n@pre)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || ((result != -1) => args_l[result] == array))) &&
    ((0 <= n - 1) => (0 <= ret && ret <= hi + 1))
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