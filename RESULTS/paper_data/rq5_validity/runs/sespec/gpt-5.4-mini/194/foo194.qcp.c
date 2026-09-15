#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
int foo194(int * a, int a_len, int Array) 
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
    (0 <= n && n <= Array) &&
    (0 <= step && step <= n) &&
    (0 <= max && max <= n) &&
    (0 <= stop && stop <= n) &&
    (0 <= max_ending_here) &&
    (0 <= max_so_far) &&
    (max_ending_here == sum(a, step, n)) &&
    (max_so_far >= max_ending_here) &&
    (max_so_far >= 0) &&
    (forall (k:Z), 0 <= k && k < n => a_l[k] == a_l[k]@pre) &&
    (Array == Array@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre)
    */
for (int n = 0; n < Array; n++) {
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