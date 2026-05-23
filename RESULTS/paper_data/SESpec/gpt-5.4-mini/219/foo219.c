
/*@
  requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || \result != -1;
  ensures \result != -1 ==> args[\result] == array;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> args[i] == args[i];
  ensures \result == -1 ==> \result == -1;
*/
int foo219(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant (result != -1) ==> args[result] == array;
          loop invariant (ret <= hi) ==> (0 <= ret <= hi + 1);
          loop invariant (ret == 0) || (ret > 0);
          loop invariant (hi == n - 1) || (hi < n - 1);
          loop invariant (0 <= n - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(ret == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || ((result != -1) ==> args[result] == array));
          loop invariant (0 <= n - 1) ==> (0 <= ret <= hi + 1);
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
