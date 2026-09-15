int maxSubArraySum(int * a, int a_len, int array);

/*@ 
  requires array >= 1;
  requires a_len >= array;
  requires \valid_read(a + (0 .. array-1));
  assigns \nothing;
  ensures 1 <= \result <= array;
  ensures \exists integer s, e;
            0 <= s <= e < array &&
            \result == e - s + 1 &&
            (\forall integer i, j;
                0 <= i <= j < array ==>
                   \sum(k, i, j, \at(a[k], Pre)) 
                   <= \sum(k, s, e, \at(a[k], Pre)));
*/
int maxSubArraySum(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		/*@
		  loop invariant 0 <= n <= array;
		  loop invariant 0 <= count <= n;
		  loop invariant 0 <= max <= stop <= n;
		  loop assigns n, max_ending_here, max_so_far, max, stop, count;
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
