
/*@
  logic integer lower_bound_index(int* a, integer lo, integer hi, integer v) =
    lo > hi ? -1
    : (\exists integer k; lo <= k <= hi && a[k] == v
         ? (\min( { k | lo <= k <= hi && a[k] == v } ))
         : -1);
*/

/*@
  requires \valid_read(args + (0 .. \at(n,Pre) - 1));
  requires \at(n,Pre) > 0 && \at(n,Pre) < 100;
  assigns \nothing;
  ensures \result == lb_index_def(args, 0, \at(n,Pre) - 1, array);
*/
int foo219(int * args, int args_len, int array, int n) {

		int ret = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /*@
          loop invariant 0 <= ret <= \at(n,Pre);
          loop invariant -1 <= hi <= \at(n,Pre) - 1;
          loop invariant ret <= hi + 1;
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. \at(n,Pre) - 1));
          loop invariant (0 <= \at(n,Pre) - 1) ==>
            (
              ((result == -1) && (hi == \at(n,Pre) - 1) && (ret == 0) && (n == \at(n,Pre)) && (array == \at(array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)))
              ||
              ( result == -1
                || (0 <= result && result <= \at(n,Pre) - 1 && args[result] == array && (\forall integer k; 0 <= k < result ==> args[k] != array))
              )
            );
          loop assigns tmp, result, hi, ret;
          */
            while (ret <= hi) {
			int tmp = (ret + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				ret = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
