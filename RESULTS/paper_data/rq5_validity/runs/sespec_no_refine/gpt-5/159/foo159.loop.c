
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo159(int * args, int args_len, int array) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant \forall integer k; 0 <= k < array ==> 1 <= args[k] <= array || args[k] <= 0 || args[k] > array;
          loop invariant \forall integer v; 1 <= v <= array ==> count_eq(args, 0, array, v) == \at(count_eq(args, 0, array, v), Pre);
          loop assigns ret, args[..];
            */
            while (ret < array) {
			if (args[ret] <= 0 || args[ret] > array
					|| args[ret] == ret + 1) {
				ret++;
			} else {
				int j = args[ret];
				args[ret] = args[j - 1];
				args[j - 1] = j;
			}
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant \forall integer k; 0 <= k < ret ==> args[k] == k + 1;
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
