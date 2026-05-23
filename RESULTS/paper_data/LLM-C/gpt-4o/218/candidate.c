/*@
    requires \valid(args + (0..args_len-1));
    requires args_len > 0;
    requires n > 0;
    ensures \result == -1 || (0 <= \result < args_len && args[\result] == Array);
    ensures \result == -1 ==> \forall integer i; 0 <= i < args_len ==> args[i] != Array;
    ensures \result != -1 ==> \forall integer i; 0 <= i < \result ==> args[i] != Array;
    assigns \nothing;
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
		    loop invariant \forall integer k; hi < k < n ==> args[k] != Array;
		    loop assigns i, hi, result, tmp;
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
