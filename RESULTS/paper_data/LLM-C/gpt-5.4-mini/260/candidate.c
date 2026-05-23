/*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires 0 <= array <= args_len;
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
*/
int findFixedPoint(int * args, int args_len, int array);

 /*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires 0 <= array <= args_len;
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
*/
int findFixedPoint(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= ret;
		    loop invariant -1 <= stop < array;
		    loop invariant ret <= stop + 1;
		    loop invariant \forall integer j; 0 <= j < ret ==> args[j] != j;
		    loop invariant \forall integer j; stop < j < array ==> args[j] != j;
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
