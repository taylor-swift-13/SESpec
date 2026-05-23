/*@
    requires \valid(args + (0..args_len-1));
    requires args_len > 0;
    ensures \result == -1 || (0 <= \result < args_len && args[\result] == \result);
    assigns \nothing;
*/
int findFixedPoint(int * args, int args_len, int array);

int findFixedPoint(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		/*@
		loop invariant 0 <= i <= array;
		loop invariant -1 <= stop < array;
		loop invariant \forall integer k; 0 <= k < i ==> args[k] != k;
		loop invariant \forall integer k; stop < k < array ==> args[k] != k;
		loop assigns i, stop;
		loop variant stop - i + 1;
		*/
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
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
