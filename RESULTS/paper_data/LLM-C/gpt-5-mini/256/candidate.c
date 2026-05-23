/*@
    requires args_len >= 0;
    requires \valid(args + (0 .. args_len - 1));
    requires \forall integer k; 0 <= k < args_len-1 ==> args[k] < args[k+1];
    assigns \nothing;
    ensures 0 <= \result <= args_len;
    ensures \forall integer j; 0 <= j < \result ==> args[j] < Array;
    ensures \forall integer j; \result <= j < args_len ==> args[j] >= Array;
*/
int leftInsertion(int * args, int args_len, int Array);

int leftInsertion(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant -1 <= top <= args_len - 1;
		    loop invariant ret <= top + 1;
		    loop invariant \forall integer j; 0 <= j < ret ==> args[j] < Array;
		    loop invariant \forall integer j; top + 1 <= j < args_len ==> args[j] > Array;
		    loop assigns ret, top;
		    loop variant top - ret + 1;
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
