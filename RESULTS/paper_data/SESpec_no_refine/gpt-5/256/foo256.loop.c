
/*@
  logic boolean nondecreasing(int* a, integer lo, integer hi) =
    lo + 1 >= hi ? \true : (a[lo] <= a[lo+1] && nondecreasing(a, lo+1, hi));
*/

int foo256(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop assigns ret, top;
            */
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return ret;
}
