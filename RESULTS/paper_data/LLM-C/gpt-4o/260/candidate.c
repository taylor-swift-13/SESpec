/*@
    requires \valid(args + (0..args_len-1));
    requires args_len > 0;
    ensures \result == -1 || (0 <= \result < args_len && args[\result] == \result);
    assigns \nothing;
*/
int findFixedPoint(int * args, int args_len, int array);

int findFixedPoint(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= ret <= stop + 1;
		    loop invariant -1 <= stop < array;
		    loop invariant \forall integer k; 0 <= k < ret ==> args[k] != k;
		    loop invariant \forall integer k; stop < k < array ==> args[k] != k;
		    loop assigns ret, stop;
		    loop variant stop - ret + 1;
		*/
		while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
}
