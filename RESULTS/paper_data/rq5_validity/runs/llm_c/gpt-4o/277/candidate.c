/*@
    requires \valid(arg + (0..arg_len-1));
    requires arg_len > 0;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < arg_len ==> \result == 0 || arg[i] % \result == 0;
    assigns \nothing;
*/
int getGcd(int * arg, int arg_len);

int getGcd(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		/*@
		    loop invariant 1 <= j <= arg_len;
		    loop invariant g >= 0;
		    loop invariant \forall integer k; 0 <= k < j ==> g == 0 || arg[k] % g == 0;
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
