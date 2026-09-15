
/*@
  predicate sorted_args(int *a, integer n) =
    \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  requires args_len == 0 || sorted_args(args, args_len);
  assigns \nothing;
  ensures 0 <= \result <= args_len;
*/
int foo257(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= \at(args_len,Pre);
          loop invariant -1 <= top <= \at(args_len,Pre) - 1;
          loop invariant ret <= top + 1;
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \at(args_len,Pre) == 0 || \valid_read(\at(args,Pre) + (0..\at(args_len,Pre)-1));
          loop invariant \at(args_len,Pre) == 0 || sorted_args(\at(args,Pre), \at(args_len,Pre));

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
