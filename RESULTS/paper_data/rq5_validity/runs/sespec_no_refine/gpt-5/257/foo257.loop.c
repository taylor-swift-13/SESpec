
/*@
  predicate sorted_strict{L}(int *a, integer n) =
    \forall integer i,j; 0 <= i < j < n ==> a[i] < a[j];
*/

int foo257(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= args_len ==> (0 <= ret <= args_len && -1 <= top < args_len && ret <= top + 1);
          loop assigns ret, top;
            */
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return ret;
}
