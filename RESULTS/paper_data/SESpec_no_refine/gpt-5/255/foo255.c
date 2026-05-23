
/*@
  // no extra predicates or logic functions needed
*/

/*@
  logic integer min_int(integer a, integer b) = a < b ? a : b;
*/
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (0 <= \result < args_len && args[\result] == array)
          ||
          (0 <= \result <= args_len
           && (\forall integer k; 0 <= k < \result ==> args[k] < array)
           && (\forall integer k; \result <= k < args_len ==> args[k] > array));
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures array == \old(array);
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
