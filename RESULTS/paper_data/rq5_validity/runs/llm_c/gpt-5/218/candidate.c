int first(int * args, int args_len, int Array, int n);

/*@ 
  requires 0 <= n <= args_len;
  requires \valid_read(args + (0..n-1));
  requires \forall integer k1, k2; 0 <= k1 <= k2 < n ==> args[k1] <= args[k2];
  assigns \nothing;

  ensures (\forall integer k; 0 <= k < n ==> args[k] != Array) ==> \result == -1;
  ensures \result == -1 ==> (\forall integer k; 0 <= k < n ==> args[k] != Array);

  ensures \result != -1 ==> 0 <= \result < n;
  ensures \result != -1 ==> args[\result] == Array;
  ensures \result != -1 ==> (\forall integer k; 0 <= k < \result ==> args[k] < Array);
*/
int first(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		  loop invariant 0 <= i <= n;
		  loop invariant -1 <= hi < n;
		  loop invariant \forall integer k; 0 <= k < i ==> args[k] < Array;
		  loop invariant \forall integer k; hi < k < n ==> args[k] >= Array;
		  loop invariant result == -1 || (0 <= result < n && args[result] == Array && hi < result);
		  loop assigns i, hi, result;
		  loop variant hi - i + 1;
		*/
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			//@ assert 0 <= i <= hi < n;
			//@ assert 0 <= tmp && tmp <= hi && tmp < n;
			if (args[tmp] == Array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < Array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}
