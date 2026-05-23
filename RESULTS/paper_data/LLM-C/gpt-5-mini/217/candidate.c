int last(int * args, int args_len, int x, int y);

 /*@
    requires \valid(args + (0 .. args_len-1));
    requires 0 <= y <= args_len;
    requires \forall integer i; 0 <= i < y-1 ==> args[i] <= args[i+1];
    assigns \nothing;
    ensures \result >= -1 && \result < y;
    ensures \result == -1 <==> (\forall integer j; 0 <= j < y ==> args[j] != x);
    ensures \result != -1 ==> args[\result] == x;
    ensures \result != -1 ==> \forall integer j; \result < j < y ==> args[j] != x;
 */
int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		    loop invariant 0 <= i <= y;
		    loop invariant -1 <= r < y;
		    loop invariant -1 <= k < y;
		    loop invariant k < i;
		    loop invariant k == -1 || args[k] == x;
		    loop invariant \forall integer j; 0 <= j < i ==> args[j] <= x;
		    loop invariant \forall integer j; r+1 <= j < y ==> args[j] > x;
		    loop invariant \forall integer j; 0 <= j < i && args[j] == x ==> j <= k;
		    loop assigns i, r, k;
		    loop variant r - i + 1;
		 */
		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return k;
}
