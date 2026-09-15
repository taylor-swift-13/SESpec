int first(int * args, int args_len, int array, int n);

/*@
    requires n >= 0;
    requires n == 0 || \valid(args + (0 .. n-1));
    requires \forall integer i; 0 <= i < n-1 ==> args[i] <= args[i+1];
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result == -1 ==> \forall integer k; 0 <= k < n ==> args[k] != array;
    ensures \result >= 0 ==> args[\result] == array && (\forall integer k; 0 <= k < \result ==> args[k] < array);
*/
int first(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= i <= n;
		    loop invariant -1 <= hi <= n-1;
		    loop invariant \forall integer k; 0 <= k < i ==> args[k] < array;
		    loop invariant \forall integer k; hi+1 <= k < n ==> args[k] >= array;
		    loop invariant result == -1 || (0 <= result < n && args[result] == array);
		    loop assigns i, hi, result;
		    loop variant hi - i + 1;
		*/
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}
