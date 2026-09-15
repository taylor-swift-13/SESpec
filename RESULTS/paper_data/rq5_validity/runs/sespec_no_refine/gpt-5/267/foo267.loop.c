
/*@ 
  logic integer cnt_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cnt_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100 ;
*/
int foo267(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < index ==> args[k] == \at(args[k],Pre) ;
          loop assigns index, ret, start;
            */
            for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
            
		return ret;
}
