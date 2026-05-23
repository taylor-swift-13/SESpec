/*@
    requires arg_len > 0;
    requires \valid_read(arg + (0 .. arg_len - 1));
    assigns \nothing;
    ensures \result == 0 || \result == \old(arg[0]);
*/
int getGcd(int * arg, int arg_len);

 /*@
    requires arg_len > 0;
    requires \valid_read(arg + (0 .. arg_len - 1));
    assigns \nothing;
    ensures \result == 0 || \result == \old(arg[0]);
*/
int getGcd(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		/*@
		    loop invariant 1 <= j <= arg_len;
		    loop invariant ret == \at(arg[0],Pre);
		    loop invariant g == 0 || g == ret;
		    loop assigns j, g, ret;
		    loop variant arg_len - j;
		*/
		for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}
