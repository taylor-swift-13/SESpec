
/*@
  logic integer sum_slice{L}(int* a, integer lo, integer hi) =
    hi <= lo ? 0 : sum_slice(a, lo, hi - 1) + \at(a[hi - 1], L);
*/

/*@
  requires \valid_read(a + (0 .. a_len-1));
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  assigns \nothing;
*/
int foo53_c195(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

        /*@
          loop invariant 0 <= n;
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
          loop invariant (n < array) ==> n <= array;
          loop invariant max_so_far >= 0;
          loop invariant 0 <= count <= n;
          loop invariant (count <= n) ==> (max_ending_here == sum_slice(a, count, n));
          loop invariant (count == n) ==> (max_ending_here == 0);
          loop invariant 0 <= max <= n;
          loop invariant -1 <= stop <= n;
          loop assigns n, max_ending_here, max_so_far, max, stop, count;
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
