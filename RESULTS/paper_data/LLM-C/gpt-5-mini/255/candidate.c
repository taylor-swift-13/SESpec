int leftInsertion(int * args, int args_len, int array);

/*@
    requires args_len >= 0;
    requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
    requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
    assigns \nothing;
    ensures 0 <= \result <= args_len;
    ensures (\result < args_len && args[\result] == array)
            ||
            (\forall integer j; 0 <= j < \result ==> args[j] < array)
            &&
            (\forall integer j; \result <= j < args_len ==> args[j] > array);
*/
int leftInsertion(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		/*@
		  loop invariant 0 <= result;
		  loop invariant -1 <= top;
		  loop invariant top <= args_len - 1;
		  loop invariant result <= top + 1;
		  loop invariant \forall integer j; 0 <= j < result ==> args[j] < array;
		  loop invariant \forall integer j; top < j < args_len ==> args[j] > array;
		  loop assigns result, top;
		  loop variant top - result + 1;
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
