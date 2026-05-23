int first(int * args, int args_len, int array, int n);

/*@ 
  predicate Sorted(int *a, integer l, integer h) =
    \forall integer i, j; l <= i < j < h ==> a[i] <= a[j];
*/

/*@
  requires args != \null;
  requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid_read(args + (0 .. args_len-1));
  requires Sorted(args, 0, n);

  assigns \nothing;

  ensures -1 <= \result < n;
  ensures \result == -1 ==> (\forall integer k; 0 <= k < n ==> args[k] != array);
  ensures \result != -1 ==> (0 <= \result < n && args[\result] == array);
  ensures \result != -1 ==> (\forall integer k; 0 <= k < \result ==> args[k] < array);
*/
int first(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		  loop invariant 0 <= i <= n;
		  loop invariant -1 <= hi < n;
		  loop invariant i <= hi + 1;
		  loop invariant \forall integer k; 0 <= k < i ==> args[k] < array;
		  loop invariant \forall integer k; hi + 1 <= k && k < n ==> args[k] >= array;
		  loop invariant result == -1 || (0 <= result < n && args[result] == array);
		  loop assigns i, hi, result;
		  loop variant hi - i;
		*/
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			/*@ assert i <= hi ==> (i <= tmp && tmp <= hi && 0 <= tmp && tmp < n); */
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
