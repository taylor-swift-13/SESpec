int first(int * args, int args_len, int Array, int n);

/*@
    requires n >= 0;
    requires n == 0 || \valid(args + (0 .. n-1));
    requires \forall integer k; 0 <= k < n-1 ==> args[k] <= args[k+1];
    assigns \nothing;
    ensures -1 <= \result <= n-1;
    ensures \result == -1 <==> (\forall integer k; 0 <= k < n ==> args[k] != Array);
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result >= 0 ==> \forall integer k; 0 <= k < \result ==> args[k] != Array;
*/
int first(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= i <= n;
		    loop invariant -1 <= hi < n;
		    loop invariant result == -1 || (0 <= result < n && args[result] == Array);
		    loop invariant \forall integer k; 0 <= k < i ==> args[k] != Array;
		    loop invariant \forall integer k; hi < k < n ==> (k == result ? args[k] == Array : args[k] != Array);
		    loop assigns i, hi, result;
		    loop variant hi - i + 1;
		*/
		while (i <= hi) {
			int tmp = (i + hi) / 2;
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
