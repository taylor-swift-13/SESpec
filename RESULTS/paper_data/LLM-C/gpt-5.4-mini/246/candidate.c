/*@
    requires args_len >= 0;
    requires num >= 0;
    requires num <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * args, int args_len, int num);

 /*@
    requires args_len >= 0;
    requires num >= 0;
    requires num <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
 */
int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop invariant ret <= index * (index - 1) / 2;
		    loop assigns index, ret, k;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= k <= num;
			    loop invariant ret >= 0;
			    loop assigns k, ret;
			    loop variant num - k;
			*/
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
}
