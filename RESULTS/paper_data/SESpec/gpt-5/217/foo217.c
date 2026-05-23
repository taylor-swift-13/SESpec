
/*@
  logic integer last_index_of_value(int *a, integer n, integer x) =
    n <= 0 ? -1 : (a[n-1] == x ? n-1 : last_index_of_value(a, n-1, x));
*/

/*@
  requires y >= 0;
  requires y <= args_len;
  requires \valid_read(args + (0..y-1));
  requires \forall integer a, b; 0 <= a < b < y ==> args[a] <= args[b];
  assigns \nothing;
  ensures -1 <= \result < y;
  ensures \result != -1 ==> (0 <= \result < y && args[\result] == x);
  ensures \result != -1 ==> (\forall integer t; \result < t < y ==> args[t] >= x);
  ensures \result != -1 ==> (\forall integer t; 0 <= t < \result ==> args[t] <= x);
  ensures \result != -1 ==> (\forall integer t; \result < t < y ==> args[t] >= x);
*/
int foo217(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

        /*@
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);

          loop invariant \forall integer t; 0 <= t < y ==> args[t] == \at(args[t], Pre);

          loop invariant 0 <= i;
          loop invariant i <= y;
          loop invariant -1 <= r;
          loop invariant r <= y - 1;
          loop invariant i <= r + 1;

          loop invariant (i <= r) ==> (0 <= (i + r) / 2 && ((i + r) / 2) < y);

          loop invariant (k == -1) || (0 <= k && k < i);
          loop invariant (k == -1) || (args[k] == x);

          loop assigns k, i, r;
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
