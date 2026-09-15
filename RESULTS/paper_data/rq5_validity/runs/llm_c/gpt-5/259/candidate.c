#include <limits.h>

int findFixedPoint(int * args, int args_len, int array);

/*@ 
  requires array >= 0;
  requires args_len >= array;
  requires \valid_read(args + (0 .. array-1));
  requires \forall integer k; 0 <= k + 1 < array ==> args[k] < args[k+1];
  assigns \nothing;
  ensures \result == -1 ==> \forall integer k; 0 <= k < array ==> args[k] != k;
  ensures \result != -1 ==> 0 <= \result < array && args[\result] == \result;
*/
int findFixedPoint(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		/*@
		  loop invariant 0 <= i <= array;
		  loop invariant -1 <= stop < array;
		  loop invariant i <= stop + 1;
		  loop invariant \forall integer k; 0 <= k < i ==> args[k] < k;
		  loop invariant \forall integer k; stop + 1 <= k < array ==> args[k] > k;
		  loop assigns i, stop;
		  loop variant stop - i + 1;
		*/
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
			/*@ assert i <= cur && cur <= stop; */
			/*@ assert 0 <= cur < array; */
			/*@ assert \valid_read(args + cur); */
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}
