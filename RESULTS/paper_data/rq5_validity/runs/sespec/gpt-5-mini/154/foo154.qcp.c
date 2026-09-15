#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo154(int * args, int args_len, int Array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= array && array <= Array) &&
    (true)) &&
    ((!(array < Array)) => (array == Array))
    */
for (int array = 0; array < Array; array++) {
		mpis[array] = args[array];
	}
	
 	/*1*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < p => mpis[k] == mpis[k])
    */
for (int i = 1; i < Array; i++) {
		
 	/*2*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (forall (k:Z), 0 <= k && k < Array => mpis[k] == mpis[k])
    */
for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int result = mpis[0];
	
 	for (int i = 1; i < Array; i++) {
		if (mpis[i] > result) {
			result = mpis[i];
		}
	}
		return result;
}