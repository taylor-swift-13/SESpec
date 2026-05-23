/*@
    requires args_len > 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getGcd(int * args, int args_len);

 /*@
    requires args_len > 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getGcd(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		/*@
		    loop invariant 1 <= j <= args_len;
		    loop invariant ret >= 0;
		    loop invariant tmp == \min(args[0..j-1]);
		    loop assigns j, ret, tmp;
		    loop variant args_len - j;
		*/
		for (int j = 1; j < args_len; j++) {
			if (args[j] > tmp) {
				ret = ret > tmp ? ret : tmp;
			} else {
				tmp = args[j];
			}
		}
		return ret;
}
