
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires 0 <= array;
  requires \valid_read(args + (0 .. array-1));
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result == \null ==> (array > 0 && args[0] == 0);
  ensures \result >= -1;
*/
int foo260(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant stop < array;
          loop assigns ret, stop;
            */
            while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
            
		return -1;
}
