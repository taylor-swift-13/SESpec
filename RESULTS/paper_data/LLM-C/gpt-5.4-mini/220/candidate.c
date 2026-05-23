/*@
    requires args_len >= 0;
    requires n >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires n <= args_len;
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result != -1 ==> args[\result] == array;
    ensures \result != -1 ==> \forall integer j; 0 <= j < \result ==> args[j] != array;
    ensures \result == -1 ==> \forall integer j; 0 <= j < n ==> args[j] != array;
*/
int first(int * args, int args_len, int array, int n);

int first(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= i <= n;
		    loop invariant -1 <= hi < n;
		    loop invariant -1 <= result < n;
		    loop invariant result != -1 ==> args[result] == array;
		    loop invariant result != -1 ==> \forall integer j; 0 <= j < result ==> args[j] != array;
		    loop invariant \forall integer j; 0 <= j < i ==> args[j] != array;
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
