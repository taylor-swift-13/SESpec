#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo196(int * a, int a_len, int array) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

	
 	/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= n && n <= array) &&
    (0 <= max_so_far) &&
    (0 <= max_ending_here) &&
    (0 <= max) &&
    (0 <= stop) &&
    (0 <= step && step <= n) &&
    (max_so_far >= max_ending_here) &&
    (stop <= n) &&
    (max <= stop + 1) &&
    (array == array@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < n => a_l[k] == a_l[k]@pre) &&
    (!(n < array@pre) => n == array@pre)
    */
for (int n = 0; n < array; n++) {
			max_ending_here += a[n];
			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
				max = step;
				stop = n;
			}
			if (max_ending_here < 0) {
				max_ending_here = 0;
				step = n + 1;
			}
		}
		return stop - max + 1;
}