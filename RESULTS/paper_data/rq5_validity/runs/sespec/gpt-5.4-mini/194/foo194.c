
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    hi <= lo ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires Array >= 0;
  requires \valid_read(a + (0 .. Array - 1));
  assigns \nothing;
  ensures Array == 0 ==> \result == 1;
  ensures Array > 0 ==> \result <= Array + 1;
  ensures \result <= Array + 1;
*/
int foo194(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= Array;
          loop invariant 0 <= step <= n;
          loop invariant 0 <= max <= n;
          loop invariant 0 <= stop <= n;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= max_so_far;
          loop invariant max_ending_here == sum(a, step, n);
          loop invariant max_so_far >= max_ending_here;
          loop invariant max_so_far >= 0;
          loop invariant \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
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
