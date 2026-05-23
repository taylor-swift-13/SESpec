/*@
    requires \valid(args + (0..args_len-1));
    requires args_len >= 0;
    requires \forall integer i; 0 <= i < args_len-1 ==> args[i] <= args[i+1];
    ensures 0 <= \result <= args_len;
    ensures \result < args_len ==> args[\result] >= array;
    ensures \result == args_len || args[\result] >= array;
    ensures \result == 0 || args[\result-1] < array;
    assigns \nothing;
*/
int leftInsertion(int * args, int args_len, int array);

int leftInsertion(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		loop invariant 0 <= ret <= args_len;
		loop invariant -1 <= top < args_len;
		loop invariant \forall integer i; 0 <= i < ret ==> args[i] < array;
		loop invariant \forall integer i; top < i < args_len ==> args[i] >= array;
		loop assigns ret, top;
		loop variant top - ret;
		*/
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
