int getGcd(int * args, int args_len);

/*@
    requires args_len > 0;
    requires \valid(args + (0 .. args_len-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer k; 0 <= k < args_len && args[k] == \result);
*/
int getGcd(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		/*@
		    loop invariant 1 <= j <= args_len;
		    loop invariant (\exists integer k; 0 <= k < j && args[k] == ret);
		    loop invariant g == 0 || (\exists integer k; 0 <= k < j && args[k] == g);
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
