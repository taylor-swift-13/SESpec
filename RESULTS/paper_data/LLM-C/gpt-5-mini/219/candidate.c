/*@
    requires n >= 0;
    requires args != \null;
    requires \valid(args + (0 .. n-1));
    requires args_len >= n;
    requires \forall integer i; 0 <= i < n-1 ==> args[i] <= args[i+1];
    assigns \nothing;
    ensures \result == -1 <==> (\forall integer i; 0 <= i < n ==> args[i] != array);
    ensures \result >= 0 ==>
        (0 <= \result < n &&
         args[\result] == array &&
         \forall integer j; 0 <= j < \result ==> args[j] != array);
*/
int first(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= ret <= n;
		    loop invariant -1 <= hi < n;
		    loop invariant ret <= hi + 1;
		    loop invariant \forall integer k; 0 <= k < ret ==> args[k] < array;
		    loop invariant \forall integer k; hi+1 <= k < n ==> args[k] >= array;
		    loop invariant result == -1 || (0 <= result < n && args[result] == array);
		    loop assigns ret, hi, result, tmp;
		    loop variant hi - ret + 1;
		*/
		while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}
