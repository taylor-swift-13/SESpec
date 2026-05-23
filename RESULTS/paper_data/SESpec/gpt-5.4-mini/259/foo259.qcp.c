#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo259(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int i = 0;
		int stop = array - 1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= i) &&
    (stop < array) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre) &&
    ((i <= stop) => (0 <= i && stop < array)) &&
    ((0 <= array@pre - 1) => (0 <= i && i <= array@pre)) &&
    ((0 <= array@pre - 1) => (-1 <= stop && stop < array@pre)) &&
    ((0 <= array@pre - 1) => (i <= stop + 1))
    */
while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}