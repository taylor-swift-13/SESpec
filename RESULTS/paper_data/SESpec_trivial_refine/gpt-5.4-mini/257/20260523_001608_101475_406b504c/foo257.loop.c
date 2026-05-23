
/*@
predicate sorted_array{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

int foo257(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		
            /*@
          loop invariant args_len < 0 ==> ret == 0 && top == args_len - 1;
          loop invariant args_len >= 0 ==> ret >= 0;
          loop invariant args_len >= 0 ==> top < args_len;
          loop invariant args_len >= 0 ==> ret <= top + 1;
          loop assigns ret, top;
            */
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return ret;
}
