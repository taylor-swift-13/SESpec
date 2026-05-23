
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/

int foo144(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index < \at(array,Pre)) ==> (start >= 0) ;
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
