#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (max_subarray_sum : Z -> Z -> Z -> Z) */
int foo195(int * a, int a_len, int array) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

	
 	/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= n && n <= array) &&
    (max_ending_here == sum(a, count, n)) &&
    (forall (k:Z), 0 <= k && k < n => max_subarray_sum(a, 0, k) == max_so_far || max_subarray_sum(a, 0, k) <= max_subarray_sum(a, 0, k + 1)) &&
    (count >= 0 && count <= n) &&
    (stop >= 0 && stop <= n) &&
    (array == array@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre)
    */
for (int n = 0; n < array; n++) {
        max_ending_here += a[n];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            max = count;
            stop = n;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            count = n + 1;
        }
    }
		return stop - max + 1;
}