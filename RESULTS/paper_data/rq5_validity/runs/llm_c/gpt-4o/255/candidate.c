/*@
    requires \valid_read(args+(0..args_len-1));
    requires args_len > 0;
    ensures 0 <= \result <= args_len;
    ensures \result == args_len || args[\result] >= array;
    ensures \result == 0 || args[\result-1] < array;
    assigns \nothing;
*/
int leftInsertion(int * args, int args_len, int array);

int leftInsertion(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		/*@
		    loop invariant 0 <= result <= args_len;
		    loop invariant -1 <= top < args_len;
		    loop invariant \forall integer k; 0 <= k < result ==> args[k] < array;
		    loop invariant \forall integer k; top < k < args_len ==> args[k] >= array;
		    loop assigns result, top;
		    loop variant top - result;
		*/
		while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
		return result;
}
