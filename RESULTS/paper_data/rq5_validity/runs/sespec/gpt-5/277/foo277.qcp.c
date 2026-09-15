#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo277(int * arg, int arg_len) 
/*@
With arg_l
Require store_int_array(arg, arg_len, arg_l)
Ensure Results(__return)
*/{

		int g = 0;
		int ret = arg[0];
	
 	/*@ Inv
    exists  arg_l,    
    store_int_array(arg, arg_len, arg_l) &&
    (1 <= j && j <= arg_len) &&
    (forall (k:Z), 0 <= k && k < j => ret <= arg_l[k]) &&
    (exists (k0:Z), 0 <= k0 && k0 < j && ret == arg_l[k0]) &&
    (ret <= arg_l[0]) &&
    (g >= 0) &&
    ((j < arg_len) => ((forall (k:Z), 0 <= k && k < j => ret <= arg_l[k]) && (exists (k0:Z), 0 <= k0 && k0 < j && ret == arg_l[k0]))) &&
    ((!(j < arg_len)) => (forall (k:Z), 0 <= k && k < arg_len => ret <= arg_l[k])) &&
    (forall (k:Z), 0 <= k && k < arg_len => arg_l[k] == arg_l[k]@pre)
    */
for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}