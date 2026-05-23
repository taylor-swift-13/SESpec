int maxSubArraySum(int * a, int a_len, int array);

/*@
    requires array > 0;
    requires a_len >= array;
    requires \valid_read(a + (0 .. array-1));
    assigns \nothing;
    ensures 1 <= \result <= array;
    ensures \exists integer i0, j0;
        0 <= i0 <= j0 < array &&
        (\forall integer i, j;
            0 <= i <= j < array ==>
                \sum integer k; i <= k <= j; a[k] <= \sum integer k; i0 <= k <= j0; a[k]) &&
        \sum integer k; i0 <= k <= j0; a[k] >= 0 &&
        \result == j0 - i0 + 1;
*/
int maxSubArraySum(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		/*@
		    loop invariant 0 <= n <= array;
		    loop invariant max_so_far >= 0;
		    loop invariant max_ending_here >= 0;
		    loop invariant 0 <= count <= n;
		    loop invariant 0 <= max <= n;
		    loop assigns n, max_so_far, max_ending_here, max, stop, count;
		    loop variant array - n;
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
