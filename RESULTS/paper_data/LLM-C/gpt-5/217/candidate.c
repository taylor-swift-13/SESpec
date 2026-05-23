int last(int * args, int args_len, int x, int y);

/*@ 
  requires args_len >= 0;
  requires 0 <= y <= args_len;
  requires y == 0 || \valid_read(args + (0 .. y-1));
  requires \forall integer i1, i2; 0 <= i1 <= i2 < y ==> args[i1] <= args[i2];
  assigns \nothing;
  ensures \result == -1 ==> (\forall integer t; 0 <= t < y ==> args[t] != x);
  ensures \result != -1 ==> (0 <= \result < y && args[\result] == x
                             && (\forall integer t; \result < t < y ==> args[t] != x));
  ensures \forall integer t; 0 <= t < y && args[t] == x ==> t <= \result;
*/
int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		/*@ 
		  loop invariant 0 <= i <= y;
		  loop invariant -1 <= r < y;
		  loop invariant i <= r + 1;
		  loop invariant -1 <= k < y;
		  loop invariant k < i;
		  loop invariant k == -1 || args[k] == x;
		  loop invariant \forall integer t; 0 <= t < i ==> args[t] <= x;
		  loop invariant \forall integer t; r < t < y ==> args[t] > x;
		  loop invariant \forall integer t; 0 <= t < i && args[t] == x ==> t <= k;
		  loop assigns i, r, k;
		  loop variant r - i + 1;
		*/
		while (i <= r) {
			int tmp = (i + r) / 2;
			/*@ assert i <= tmp <= r; */
			/*@ assert 0 <= tmp < y; */
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
