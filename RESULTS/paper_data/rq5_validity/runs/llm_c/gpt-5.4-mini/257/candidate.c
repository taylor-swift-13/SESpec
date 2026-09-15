/*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= args_len;
*/
int leftInsertion(int * args, int args_len, int array);

 /*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= args_len;
*/
int leftInsertion(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		    loop invariant 0 <= ret <= top + 1;
		    loop invariant -1 <= top < args_len;
		    loop invariant \valid_read(args + (0 .. args_len - 1));
		    loop assigns ret, top;
		    loop variant top - ret + 1;
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
