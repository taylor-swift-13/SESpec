
/*@ 
  logic integer sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum{L}(a, lo, hi - 1) + \at(a[hi - 1], L);
*/

/*@ 
  predicate exists_suffix_attains{L}(int* a, integer n, integer meh) =
    \exists integer i; 0 <= i <= n && meh == sum{L}(a, i, n + 1);
*/

/*@ 
  predicate exists_subarray_attains{L}(int* a, integer n, integer msf) =
    \exists integer i, j; 0 <= i <= j <= n && msf == sum{L}(a, i, j + 1);
*/

/*@
  requires \valid_read(a + (0..a_len-1));
  requires 0 <= Array <= a_len;
  assigns \nothing;
*/
int foo194(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@
          loop invariant 0 <= n <= Array;
          loop invariant Array == \at(Array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);

          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= step && step <= n;
          loop invariant 0 <= max && max <= n;
          loop invariant 0 <= stop && stop <= n;

          loop invariant n == 0 ==> (max_so_far == 0 && max_ending_here == 0 && max == 0 && stop == 0 && step == 0);

          loop invariant (max_ending_here == 0 && step == n)
                       || (step <= n && max_ending_here == sum(a, step, n));

          loop invariant max_so_far == 0 || (\exists integer i0, j0; 0 <= i0 <= j0 < n && max_so_far == sum(a, i0, j0 + 1));

          loop invariant max <= stop && stop <= n;

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
