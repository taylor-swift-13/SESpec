
/*@
  predicate bs_outside(int* args, integer n, integer lo, integer hi, int target) =
    (\forall integer k; 0 <= k < lo && k < n ==> args[k] < target)
    &&
    (\forall integer k; hi < k && k < n ==> args[k] > target);
*/

/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  assigns \nothing;
  ensures (\result >= 0 && \result < \at(args_len,Pre) && args[\result] == \at(array,Pre)) ==> args[\result] == \at(array,Pre);
  ensures (\result >= 0 && \result <= \at(args_len,Pre) && bs_outside(args, \at(args_len,Pre), \result, \result-1, \at(array,Pre))) ==> 
            (\forall integer k; 0 <= k < \result && k < \at(args_len,Pre) ==> args[k] < \at(array,Pre))
;
*/
int foo118(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		
            
        /*@
          loop invariant 0 <= result <= args_len;
          loop invariant -1 <= top < args_len;
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(result == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
