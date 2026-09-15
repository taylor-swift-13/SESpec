int last(int * args, int args_len, int x, int y);

/*@
    requires args_len >= 0;
    requires 0 <= y <= args_len;
    requires args_len == 0 || \valid(args + (0 .. args_len - 1));
    requires \forall integer i; 0 <= i < args_len-1 ==> args[i] <= args[i+1];
    assigns \nothing;
    ensures
        (\result == -1) <==> (\forall integer i; 0 <= i < y ==> args[i] != x);
    ensures
        (\result >= 0) ==> (0 <= \result < y && args[\result] == x && \forall integer j; \result < j < y ==> args[j] != x);
*/
int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		/*@
		    loop invariant 0 <= i <= y;
		    loop invariant -1 <= r <= y-1;
		    loop invariant -1 <= p <= y-1;
		    loop invariant (\forall integer k; 0 <= k < i ==> args[k] <= x);
		    loop invariant (\forall integer k; r+1 <= k < y ==> args[k] > x);
		    loop invariant p == -1 || (0 <= p < i && args[p] == x);
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
