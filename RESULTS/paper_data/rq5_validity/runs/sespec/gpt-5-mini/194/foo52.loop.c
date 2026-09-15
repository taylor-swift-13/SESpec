
/*@ 
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi-1) + a[hi-1];
*/

/*@
  logic integer max_end_at(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (hi == lo+1 ? a[lo]
                           : (max_end_at(a, lo, hi-1) > 0 ? max_end_at(a, lo, hi-1) + a[hi-1] : a[hi-1]));
*/

/*@
  logic integer max_sub(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (hi == lo+1 ? a[lo]
                           : ((max_sub(a, lo, hi-1) >= max_end_at(a, lo, hi)) ? max_sub(a, lo, hi-1) : max_end_at(a, lo, hi)));
*/

/*@
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires \valid_read(a + (0 .. \at(a_len,Pre)-1));
*/
int foo52(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

            /*@
          loop invariant 0 <= n;
          loop invariant Array == \at(Array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant (n == 0) ==> (max_so_far == 0 && max_ending_here == 0 && max == 0 && stop == 0 && step == 0);
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant max_ending_here <= max_so_far;
          loop invariant (step >= 0);
          loop invariant 0 <= stop < (n == 0 ? 1 : n);
          loop invariant \forall integer i; 0 <= i < \at(Array,Pre) ==> a[i] == \at(a[i],Pre);
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
