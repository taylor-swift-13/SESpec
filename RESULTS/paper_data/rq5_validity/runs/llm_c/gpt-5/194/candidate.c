int maxSubArraySum(int * a, int a_len, int Array);

/*@ 
  requires 1 <= Array <= a_len;
  requires \valid_read(a + (0 .. Array-1));
  assigns \nothing;
  ensures 1 <= \result <= Array;
  ensures \exists integer i, j;
            0 <= i <= j < Array &&
            \result == j - i + 1 &&
            \forall integer i2, j2; 
              0 <= i2 <= j2 < Array ==> 
                \sum(integer k, i, j, \old(a[k])) >= \sum(integer k, i2, j2, \old(a[k]));
*/
int maxSubArraySum(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@ 
		  loop invariant 0 <= n <= Array;
		  loop invariant 0 <= step <= n + 1;
		  loop invariant 0 <= max <= stop <= n;
		  loop invariant max_so_far >= 0;
		  loop invariant max_ending_here >= 0;
		  loop assigns n, max_so_far, max_ending_here, max, stop, step;
		  loop variant Array - n;
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
