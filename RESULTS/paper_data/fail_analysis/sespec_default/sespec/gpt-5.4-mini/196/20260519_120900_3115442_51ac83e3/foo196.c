
/*@ 
  logic integer sum(int *a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
*/
int foo196(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /*@
          loop invariant 0 <= n;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= max;
          loop invariant 0 <= stop;
          loop invariant 0 <= step;
          loop invariant max_so_far >= max_ending_here;
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
