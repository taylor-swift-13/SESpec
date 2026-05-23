#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo259(int * args, int args_len, int array);

int foo259(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int i = 0;
		int stop = array - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((0 <= array@pre - 1) => (forall (k:Z), 0 <= k && k < array@pre => args_l[k] == args_l[k]@pre)) &&
((0 <= array@pre - 1) => (((stop == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= i && i <= array@pre && -1 <= stop && stop < array@pre && i <= stop + 1))) &&
((0 <= array@pre - 1) => (((stop == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || ( -1 <= stop && stop < array@pre ))) &&
((!(0 <= array@pre - 1)) => ((stop == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(array == array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre
          loop assigns i, stop)
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