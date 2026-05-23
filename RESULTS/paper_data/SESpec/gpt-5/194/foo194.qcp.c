#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (exists_suffix_attains : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (exists_subarray_attains : Z -> Z -> Z -> Prop) */
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
    (Array == Array@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
    (0 <= max_so_far) &&
    (0 <= max_ending_here) &&
    (0 <= step && step <= n) &&
    (0 <= max && max <= n) &&
    (0 <= stop && stop <= n) &&
    (n == 0 => (max_so_far == 0 && max_ending_here == 0 && max == 0 && stop == 0 && step == 0)) &&
    ((max_ending_here == 0 && step == n) || (step <= n && max_ending_here == sum(a, step, n))) &&
    (max_so_far == 0 || (exists (i0:Z), exists (j0:Z), 0 <= i0 && i0 <= j0 && j0 < n && max_so_far == sum(a, i0, j0 + 1))) &&
    (max <= stop && stop <= n)
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