
/*@
  requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires \forall integer i, j; 0 <= i <= j < args_len ==> args[i] <= args[j];
*/
int foo257(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret <= args_len;
          loop invariant -1 <= top < args_len;
          loop invariant ret <= top + 1;
          loop invariant args_len == \at(args_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant ret == 0 || args[ret - 1] < array;
          loop invariant top == args_len - 1 || args[top + 1] > array;
          loop invariant (ret > top) ==> (ret == 0 || args[ret - 1] < array);
          loop invariant (ret > top) ==> (top == args_len - 1 || args[top + 1] > array);
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (ret <= top + 1);
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret <= top + 1));
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (top < args_len));
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
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
