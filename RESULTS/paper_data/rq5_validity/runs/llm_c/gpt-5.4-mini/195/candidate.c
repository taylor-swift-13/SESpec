/*@
    requires a_len >= 0;
    requires array >= 0;
    requires \valid_read(a + (0 .. a_len - 1));
    requires array <= a_len;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= array;
*/
int maxSubArraySum(int * a, int a_len, int array);

 /*@
    requires a_len >= 0;
    requires array >= 0;
    requires \valid_read(a + (0 .. a_len - 1));
    requires array <= a_len;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= array;
*/
int maxSubArraySum(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		/*@
		    loop invariant 0 <= n <= array;
		    loop invariant 0 <= count <= n + 1;
		    loop invariant 0 <= stop < array || stop == 0;
		    loop invariant 0 <= max <= n;
		    loop invariant max_so_far >= 0;
		    loop invariant max_ending_here >= 0;
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
