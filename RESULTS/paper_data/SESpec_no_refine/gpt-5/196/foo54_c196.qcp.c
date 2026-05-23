#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo54_c196(int * a, int a_len, int array);

int foo54_c196(int * a, int a_len, int array) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    ((n < array@pre) => (0 <= n && n < array@pre)) &&
((n < array@pre) => (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == array@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= max_so_far))) &&
((n < array@pre) => (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == array@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= max_ending_here))) &&
((n < array@pre) => (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == array@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= max && max <= n))) &&
((n < array@pre) => (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == array@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= stop && stop <= n))) &&
((n < array@pre) => (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == array@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= step && step <= n+1))) &&
(array == array@pre) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(unchanged_slice{Pre,Here}(a, 0, n)
          loop assigns n, max_ending_here, max_so_far, max, stop, step)
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