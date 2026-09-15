/*@ 
  requires args_len >= 0;
  requires 0 <= n <= args_len;
  requires \valid_read(args + (0..n-1));
  requires \forall integer i, j; 0 <= i <= j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures (\result == -1) || (0 <= \result < n && args[\result] == array);
  ensures (\result == -1) ==> (\forall integer i; 0 <= i < n ==> args[i] != array);
  ensures (\result != -1) ==> (\forall integer i; 0 <= i < \result ==> args[i] < array);
*/
int first(int * args, int args_len, int array, int n);

int first(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		/*@
		  loop invariant 0 <= ret <= n;
		  loop invariant -1 <= hi < n;
		  loop invariant ret <= hi + 1;
		  loop invariant result == -1 || (0 <= result < n && args[result] == array);
		  loop invariant \forall integer i; 0 <= i < ret ==> args[i] < array;
		  loop invariant \forall integer i; hi + 1 <= i < n ==> args[i] >= array;
		  loop invariant result != -1 ==> (\forall integer i; 0 <= i < result ==> args[i] < array) && hi < result;
		  loop assigns ret, hi, result;
		  loop variant hi - ret + 1;
		*/
		while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			/*@ 
			  assert ret <= tmp <= hi;
			  assert 0 <= tmp < n;
			*/
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		/*@ 
		  assert (result == -1) || (0 <= result < n && args[result] == array);
		  assert (result == -1) ==> (\forall integer i; 0 <= i < n ==> args[i] != array);
		  assert (result != -1) ==> (\forall integer i; 0 <= i < result ==> args[i] < array);
		*/
		return result;
}
