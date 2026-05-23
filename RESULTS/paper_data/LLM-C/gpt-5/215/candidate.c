int last(int * args, int args_len, int x, int y);

/*@ 
  requires 0 <= y <= args_len;
  requires \valid_read(args + (0..y-1));
  requires \forall integer i, j; 0 <= i <= j < y ==> args[i] <= args[j];
  assigns \nothing;
  ensures -1 <= \result < y;
  ensures (\result == -1) <==> (\forall integer k; 0 <= k < y ==> args[k] != x);
  ensures \result != -1 ==> args[\result] == x;
  ensures \result != -1 ==> (\forall integer k; 0 <= k < y && args[k] == x ==> k <= \result);
*/
int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		/*@
		  loop invariant 0 <= i <= y;
		  loop invariant -1 <= r < y;
		  loop invariant -1 <= p < y;
		  loop invariant p < i;
		  loop invariant p == -1 || args[p] == x;
		  loop invariant \forall integer k; 0 <= k < i ==> args[k] <= x;
		  loop invariant \forall integer k; r < k < y ==> args[k] > x;
		  loop invariant \forall integer k; 0 <= k < i && args[k] == x ==> k <= p;
		  loop invariant i <= r + 1;
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
