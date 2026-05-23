/*@ 
    requires args_len >= 0;
    requires n >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires n <= args_len;
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result == -1 || args[\result] == Array;
    ensures \result != -1 ==> (\forall integer k; 0 <= k < \result ==> args[k] != Array);
*/
int first(int * args, int args_len, int Array, int n);

 /*@ 
    requires args_len >= 0;
    requires n >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires n <= args_len;
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result == -1 || args[\result] == Array;
    ensures \result != -1 ==> (\forall integer k; 0 <= k < \result ==> args[k] != Array);
*/
int first(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= i <= n;
		    loop invariant -1 <= hi < n;
		    loop invariant -1 <= result < n;
		    loop invariant result == -1 || args[result] == Array;
		    loop invariant result != -1 ==> (\forall integer k; 0 <= k < result ==> args[k] != Array);
		    loop invariant (\forall integer k; 0 <= k < i ==> args[k] != Array);
		    loop invariant (\forall integer k; hi < k < n ==> args[k] > Array);
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
