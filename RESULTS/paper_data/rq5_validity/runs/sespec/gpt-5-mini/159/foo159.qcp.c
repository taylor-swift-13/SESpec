#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo159(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= ret && ret <= array) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < ret => (args_l[k] == k + 1 || args_l[k] <= 0 || args_l[k] > array)) &&
    (forall (k:Z), 0 <= k && k < array => ((args_l[k] > 0 && args_l[k] <= args_len && args_l[k] != k + 1) || (args_l[k] <= 0 || args_l[k] > args_len || args_l[k] == k + 1))) &&
    ((ret == array) => (forall (i:Z), 0 <= i && i < array => (args_l[i] == i + 1 || args_l[i] <= 0 || args_l[i] > array)))
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
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= ret && ret <= array) &&
    (forall (k:Z), 0 <= k && k < ret => args_l[k] == k + 1) &&
    (forall (i:Z), 0 <= i && i < args_len => true) &&
    ((!(ret < array)) => (forall (i:Z), 0 <= i && i < array => args_l[i] == i + 1))
    */
for (ret = 0; ret < array; ret++) {
        if (args[ret] != ret + 1) {
            return ret + 1;
        }
    }
		return array + 1;
}