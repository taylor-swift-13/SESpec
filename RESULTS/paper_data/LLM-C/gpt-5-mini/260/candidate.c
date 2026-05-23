int findFixedPoint(int * args, int args_len, int array);

 /*@
     requires array >= 0;
     requires array == 0 || \valid(args + (0 .. array-1));
     assigns \nothing;
     ensures \result == -1 || (0 <= \result && \result < array && args[\result] == \result);
 */
int findFixedPoint(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= ret <= array;
		    loop invariant -1 <= stop < array;
		    loop invariant ret <= stop + 1;
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
