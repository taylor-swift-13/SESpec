/*@
    requires args_len >= 0;
    requires n >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires n <= args_len;
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < n);
    ensures \result != -1 ==> args[\result] == array;
    ensures \result != -1 ==> (\forall integer i; 0 <= i < \result ==> args[i] < array);
*/
int first(int * args, int args_len, int array, int n);

 /*@
    requires args_len >= 0;
    requires n >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires n <= args_len;
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < n);
    ensures \result != -1 ==> args[\result] == array;
    ensures \result != -1 ==> (\forall integer i; 0 <= i < \result ==> args[i] < array);
*/
int first(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		    loop invariant 0 <= ret <= n;
		    loop invariant -1 <= hi < n;
		    loop invariant -1 <= result < n;
		    loop invariant result != -1 ==> args[result] == array;
		    loop invariant result == -1 ==> (\forall integer i; 0 <= i < ret ==> args[i] < array);
		    loop invariant result == -1 ==> (\forall integer i; hi < i < n ==> args[i] > array);
		    loop assigns ret, hi, result;
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
