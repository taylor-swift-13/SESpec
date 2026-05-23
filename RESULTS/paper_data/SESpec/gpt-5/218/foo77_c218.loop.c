
/*@
  predicate sorted(int *a, integer lo, integer hi) =
    \forall integer i, j; lo <= i <= j < hi ==> a[i] <= a[j];
*/

/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires 0 <= n <= args_len;
  requires sorted(args, 0, args_len);
*/
int foo77_c218(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant -1 <= hi < n;
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. args_len-1));
          loop invariant sorted(args, 0, args_len);
          loop invariant (result == -1) || (0 <= result < n && args[result] == Array);
          loop assigns result, hi, i;
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
