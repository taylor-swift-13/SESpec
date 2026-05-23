#include <stddef.h>

int maxSubArraySum(int * a, int a_len, int array);

/*@ 
  requires a != \null;
  requires a_len >= 1;
  requires 1 <= array <= a_len;
  requires \valid_read(a + (0 .. a_len-1));

  assigns \nothing;

  ensures 1 <= \result <= array;
*/
int maxSubArraySum(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		/*@ 
		  loop invariant 0 <= n <= array;
		  loop invariant 0 <= step <= n;
		  loop invariant 0 <= max <= stop <= n;
		  loop invariant max_so_far >= 0;
		  loop invariant max_ending_here >= 0;
		  loop assigns n, max_so_far, max_ending_here, max, stop, step;
		  loop variant array - n;
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
