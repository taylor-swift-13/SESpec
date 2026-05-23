
/*@
  logic integer cnt_unmodified{L1,L2}(int* a, integer lo, integer hi) =
    (lo >= hi) ? 0
               : cnt_unmodified{L1,L2}(a, lo, hi-1) + ( \at(a[hi-1],L1) == \at(a[hi-1],L2) ? 1 : 0);
*/

/*@
  predicate unchanged_slice{L1,L2}(int* a, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> \at(a[k],L1) == \at(a[k],L2);
*/

/*@
  ensures a == \at(a,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures array == \at(array,Pre);
  assigns \nothing;
*/
int foo54_c196(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (n < \at(array,Pre)) ==> (0 <= n < \at(array,Pre));
          loop invariant (n < \at(array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_so_far));
          loop invariant (n < \at(array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_ending_here));
          loop invariant (n < \at(array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max <= n));
          loop invariant (n < \at(array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= stop <= n));
          loop invariant (n < \at(array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= step <= n+1));
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant unchanged_slice{Pre,Here}(a, 0, n);
          loop assigns n, max_ending_here, max_so_far, max, stop, step;
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
