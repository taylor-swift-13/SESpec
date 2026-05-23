
/*@
  logic integer cnt_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cnt_odd(a, lo, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires 0 <= array <= args_len;
*/
int foo267(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= array;
          loop invariant 0 <= start <= index;
          loop invariant start == cnt_odd(args, 0, index);
          loop invariant (start == 0) ==> (ret == 0);
          loop invariant (start % 2 == 1) ==> (\exists integer k; 0 <= k < index && args[k] % 2 != 0 && cnt_odd(args, 0, k+1) % 2 == 1 && ret == args[k]);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
