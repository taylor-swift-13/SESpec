#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo159(int * args, int args_len, int array);

int foo159(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((0 < array@pre) => (0 <= ret && ret <= array)) &&
((!(0 < array@pre)) => ((ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(array == array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre)
    */
    
            while (ret < array) {
			if (args[ret] <= 0 || args[ret] > array
					|| args[ret] == ret + 1) {
				ret++;
			} else {
				int j = args[ret];
				args[ret] = args[j - 1];
				args[j - 1] = j;
			}
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    ((ret < array) => (forall (k:Z), 0 <= k && k < ret => args_l[k] == k + 1)
          loop assigns ret)
    */
    
            for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
}