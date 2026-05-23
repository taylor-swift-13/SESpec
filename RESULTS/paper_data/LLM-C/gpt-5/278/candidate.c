int getGcd(int * args, int args_len);

/*@ predicate prefix_min_value(int *a, integer j, integer m) =
      0 <= j &&
      (\forall integer k; 0 <= k <= j ==> m <= a[k]) &&
      (\exists integer k0; 0 <= k0 <= j && a[k0] == m);
*/

/*@ requires args_len >= 1;
    requires \valid_read(args + (0 .. args_len-1));
    assigns \nothing;

    ensures \result >= 0;
    ensures \result <= (args[0] > 0 ? args[0] : 0);

    ensures \forall integer k; 1 <= k < args_len ==>
              (\forall integer m; prefix_min_value(args, k-1, m) ==> (args[k] > m ==> \result >= m));

    ensures (\exists integer k, m; 1 <= k < args_len && prefix_min_value(args, k-1, m) && m > 0 && args[k] > m)
            ==> \result > 0;

    ensures args[0] <= 0 ==> \result == 0;

    ensures (\forall integer j; 1 <= j < args_len ==> args[j] <= args[j-1]) ==> \result == 0;

    ensures \result == 0 ||
            (\exists integer i; 0 <= i < args_len &&
                prefix_min_value(args, i, \result) &&
                (\exists integer j; i < j < args_len && args[j] > \result));
*/
int getGcd(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		/*@
		  loop invariant 1 <= j <= args_len;
		  loop invariant prefix_min_value(args, j-1, tmp);
		  loop invariant ret >= 0;
		  loop invariant ret <= (args[0] > 0 ? args[0] : 0);
		  loop invariant \forall integer k; 1 <= k < j ==>
		    (\forall integer m; prefix_min_value(args, k-1, m) ==> (args[k] > m ==> ret >= m));
		  loop assigns j, ret, tmp;
		  loop variant args_len - j;
		*/
		for (int j = 1; j < args_len; j++) {
			if (args[j] > tmp) {
				ret = ret > tmp ? ret : tmp;
			} else {
				tmp = args[j];
			}
		}
		return ret;
}
