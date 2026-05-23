
/*@
  // no extra predicates or logic functions needed
*/

int foo255(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant -1 <= top < args_len;
          loop invariant 0 <= result <= top + 1;
          loop invariant \forall integer k; 0 <= k < result ==> args[k] < array;
          loop invariant \forall integer k; top < k < args_len ==> args[k] > array;
          loop assigns result, top;
            */
            while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return result;
}
