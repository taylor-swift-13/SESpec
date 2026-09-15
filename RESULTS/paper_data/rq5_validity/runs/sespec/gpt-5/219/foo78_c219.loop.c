
/*@
  predicate sorted(int *a, integer lo, integer hi) =
    \forall integer i,j; lo <= i <= j < hi ==> a[i] <= a[j];
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires \valid_read(args + (0 .. \at(args_len,Pre) - 1));
  requires 0 <= \at(n,Pre) && \at(n,Pre) <= \at(args_len,Pre);
  requires sorted(args, 0, \at(n,Pre));
  assigns \nothing;
*/
        
int foo78_c219(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. n - 1));
          loop invariant sorted(args, 0, n);
          loop invariant -1 <= hi < n;
          loop invariant 0 <= ret <= hi + 1;
          loop invariant result == -1 || (0 <= result < n && args[result] == array);
          loop assigns result, hi, ret;
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
