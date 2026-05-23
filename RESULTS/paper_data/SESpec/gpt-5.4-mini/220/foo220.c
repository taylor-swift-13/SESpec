

/*@
  requires 0 <= n <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || args[\result] == array;
  ensures \result >= -1;
  ensures \result == -1 || \result >= 0;
  ensures \result == \result;
*/
int foo220(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /*@
          loop invariant 0 <= i;
          loop invariant hi < n;
          loop invariant hi < args_len;
          loop invariant result >= -1;
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant result == -1 || args[result] == array;
          loop assigns result, hi, i;
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
