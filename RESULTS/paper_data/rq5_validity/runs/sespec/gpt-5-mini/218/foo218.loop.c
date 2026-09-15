
/* No top-level predicate using \at(.,Pre) is provided because \at(...,Pre)
   is only meaningful inside function-level annotations. Instead, the loop
   invariants below use \at(...,Pre) directly. */

int foo218(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (0 <= i && i <= \at(n,Pre));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (-1 <= hi && hi < \at(n,Pre));
              i <= hi + 1));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)
                                                     &&(n == \at(n,Pre))&&(Array == \at(Array,Pre))
                                                     &&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> args[k] == \at(args[k], Pre);
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
