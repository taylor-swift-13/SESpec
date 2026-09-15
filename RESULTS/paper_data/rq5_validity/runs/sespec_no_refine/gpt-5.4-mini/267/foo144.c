
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns ret, start, index;
  ensures array <= 0 ==> \result == 0;
  ensures array > 0 ==> (
    (\exists integer k; 0 <= k < array && 0 <= k < args_len &&
      args[k] % 2 != 0 &&
      (1 + (\numof integer j; 0 <= j <= k && j < array && j < args_len && args[j] % 2 != 0)) % 2 != 0 &&
      \result == args[k])
    || (\forall integer k; 0 <= k < array && 0 <= k < args_len &&
        args[k] % 2 != 0 &&
        (1 + (\numof integer j; 0 <= j <= k && j < array && j < args_len && args[j] % 2 != 0)) % 2 != 0 ==> \result != args[k])
  );
  ensures \result == 0 || (\exists integer i; 0 <= i < array && 0 <= i < args_len && \result == args[i] && args[i] % 2 != 0);
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
