/*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures -1 <= \result < args_len;
    ensures \result == -1 || args[\result] == x;
    ensures \result == -1 || \forall integer j; \result < j < args_len ==> args[j] != x;
*/
int last(int * args, int args_len, int x, int y);

 /*@
    requires args_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures -1 <= \result < args_len;
    ensures \result == -1 || args[\result] == x;
    ensures \result == -1 || \forall integer j; \result < j < args_len ==> args[j] != x;
*/
int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;
		/*@
		    loop invariant 0 <= i;
		    loop invariant -1 <= r < args_len;
		    loop invariant -1 <= p < args_len;
		    loop invariant i <= args_len;
		    loop invariant i <= r + 1;
		    loop invariant p == -1 || args[p] == x;
		    loop invariant p == -1 || \forall integer j; p < j < args_len ==> args[j] != x;
		    loop assigns i, r, p;
		    loop variant r - i + 1;
		*/
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
}
