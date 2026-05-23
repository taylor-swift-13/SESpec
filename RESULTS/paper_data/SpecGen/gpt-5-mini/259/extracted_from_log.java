class FindFixedPoint {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
	//@ ensures (\result >= 0 && \result < array) ==> args[\result] == \result;
	public static int findFixedPoint(int[] args, int array) {
		int i = 0;
		int stop = array - 1;
		//@ loop_invariant 0 <= i && i <= array;
		//@ loop_invariant -1 <= stop && stop < array;
		//@ loop_invariant i <= stop + 1;
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
			//@ assume 0 <= cur && cur < array;
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
}