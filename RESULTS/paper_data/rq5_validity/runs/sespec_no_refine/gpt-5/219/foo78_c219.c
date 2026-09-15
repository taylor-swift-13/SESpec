

/*@
  logic integer min_int(integer a, integer b) = a < b ? a : b;
*/
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures \result == \result;
*/
int foo78_c219(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == n;
          loop invariant args == args;
          loop invariant args_len == args_len;
          loop invariant array == array;
          loop invariant -1 <= hi < n || n <= 0;
          loop invariant 0 <= ret <= n || n <= 0;
          loop invariant ret <= hi + 1 || n <= 0;
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
