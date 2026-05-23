
/*@
  logic integer prefix_sum(int* a, integer lo, integer hi) =
    hi <= lo ? 0
             : prefix_sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires 0 <= array && array <= \at(a_len,Pre);
  requires \valid(a + (0 .. \at(a_len,Pre) - 1));
  assigns \nothing;
*/
int foo195(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

        /*@
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant max_so_far >= max_ending_here;
          loop invariant max_so_far >= 0;
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (max_so_far >= max_ending_here));
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (max_ending_here >= 0));
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
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
