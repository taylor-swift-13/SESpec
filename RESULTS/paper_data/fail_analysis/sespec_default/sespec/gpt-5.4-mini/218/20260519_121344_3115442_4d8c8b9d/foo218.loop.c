
/*@
  logic integer count_args_eq(int *args, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_args_eq(args, lo, hi - 1, v) + (args[hi - 1] == v ? 1 : 0);
*/

int foo218(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (0 <= i <= hi + 1);
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= hi + 1 <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (result == -1 || (0 <= result <= \at(n,Pre) - 1 && args[result] == Array)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop assigns i, hi, result;
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
