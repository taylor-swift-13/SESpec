
/*@
  logic integer prefix_sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : prefix_sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
*/
int foo194(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (n < \at(Array,Pre)) ==> (\forall integer k; 0 <= k < n ==> a[k] == \at(a[k], Pre));
          loop invariant (n < \at(Array,Pre)) ==> (((step == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(Array == \at(Array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (max_so_far >= max_ending_here && max_so_far >= 0));
          loop invariant Array == \at(Array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], Pre);
          loop assigns n, max_ending_here, max_so_far, max, stop, step;
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
