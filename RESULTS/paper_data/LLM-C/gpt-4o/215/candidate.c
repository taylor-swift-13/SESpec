/*@ 
    requires \valid(args + (0..args_len-1));
    requires 0 <= y <= args_len;
    ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
    ensures \result != -1 ==> (\forall integer k; \result < k < args_len ==> args[k] != x);
    assigns \nothing;
*/
int last(int * args, int args_len, int x, int y);

int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		/*@
		loop invariant 0 <= i <= y;
		loop invariant -1 <= r < y;
		loop invariant -1 <= p < y;
		loop invariant \forall integer k; 0 <= k < i ==> (args[k] != x || k <= p);
		loop invariant \forall integer k; r < k < y ==> args[k] != x;
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
