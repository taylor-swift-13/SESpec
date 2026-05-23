
/*@
  requires args_len >= 0;
  requires \valid_read(args + (0 .. args_len-1));
           assigns \nothing;
  ensures args == \old(args);
  ensures args_len == \old(args_len);
  ensures array == \old(array);
  ensures 0 <= \result <= args_len;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures (0 <= \result < args_len && args[\result] == array) ==> args[\result] == array;
    ensures \result == \result;
  assigns \nothing;
*/
int foo257(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret && ret <= \at(args_len,Pre);
          loop invariant -1 <= top && top < \at(args_len,Pre);
          loop invariant ret <= top + 1;
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> args[k] == \at(args[k], Pre);
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (ret <= top + 1);
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= ret && ret <= \at(args_len,Pre)));
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= top && top < \at(args_len,Pre)));
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
