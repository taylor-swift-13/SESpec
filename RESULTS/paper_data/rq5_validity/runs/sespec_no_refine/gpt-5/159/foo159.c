
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  ensures \forall integer v; 1 <= v <= array ==> count_eq(args, 0, array, v) == \old(count_eq(args, 0, array, v));
  ensures (\forall integer k; 0 <= k < array ==> args[k] == k + 1) ==> \result == array + 1;
  ensures (\exists integer r; 0 <= r < array && args[r] != r + 1) ==>
          (1 <= \result <= array &&
           args[\result - 1] != \result &&
           (\forall integer k; 0 <= k < \result - 1 ==> args[k] == k + 1));
  assigns args[..];
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
