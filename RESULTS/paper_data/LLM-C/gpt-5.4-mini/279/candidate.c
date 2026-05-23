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

		int g = 0;
		int ret = args[0];
		/*@
		    loop invariant 1 <= j <= args_len;
		    loop invariant ret == \min(args[0], \min(args[1], \min(args[2], \min(args[3], \min(args[4], \min(args[5], \min(args[6], \min(args[7], \min(args[8], args[9])))))))));
		    loop invariant g >= 0;
		    loop assigns j, g, ret;
		    loop variant args_len - j;
		*/
		for (int j = 1; j < args_len; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
		return g;
}
