/*@
    requires \valid(args+(0..args_len-1));
    requires args_len > 0;
    ensures 0 <= \result <= args_len;
    ensures \result == args_len || args[\result] >= Array;
    ensures \result == 0 || args[\result-1] < Array;
    assigns \nothing;
*/
int leftInsertion(int * args, int args_len, int Array);

int leftInsertion(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
        loop invariant 0 <= ret <= args_len;
        loop invariant -1 <= top < args_len;
        loop invariant \forall integer k; 0 <= k < ret ==> args[k] < Array;
        loop invariant \forall integer k; top < k < args_len ==> args[k] >= Array;
        loop assigns ret, top;
        loop variant top - ret;
        */
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
