/*@
    requires \valid(args + (0..args_len-1));
    requires 0 <= y <= args_len;
    ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
    ensures \result != -1 ==> (\forall integer i; \result < i < args_len ==> args[i] != x);
    assigns \nothing;
*/
int last(int * args, int args_len, int x, int y);

int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@
		loop invariant 0 <= i <= y;
		loop invariant -1 <= r < y;
		loop invariant -1 <= k < y;
		loop invariant \forall integer j; 0 <= j < i ==> (args[j] != x || k >= j);
		loop invariant k == -1 || (0 <= k < y && args[k] == x);
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
