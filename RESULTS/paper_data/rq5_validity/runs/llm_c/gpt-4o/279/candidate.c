/*@
    requires \valid(args+(0..args_len-1));
    requires args_len > 0;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < args_len ==> args[i] % \result == 0;
    assigns \nothing;
*/
int getGcd(int * args, int args_len);

int getGcd(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		/*@
		    loop invariant 1 <= j <= args_len;
		    loop invariant g >= 0;
		    loop invariant \forall integer k; 0 <= k < j ==> args[k] % g == 0;
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
