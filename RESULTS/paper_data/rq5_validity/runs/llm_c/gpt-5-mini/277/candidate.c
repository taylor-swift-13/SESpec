int getGcd(int * arg, int arg_len);

/*@
    requires arg_len > 0;
    requires \valid(arg + (0 .. arg_len-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < arg_len && arg[i] == \result);
*/
int getGcd(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		/*@
		    loop invariant 1 <= j <= arg_len;
		    loop invariant (\exists integer ri; 0 <= ri < j && ret == arg[ri]);
		    loop invariant g == 0 || (\exists integer gi; 0 <= gi < j && g == arg[gi]);
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
