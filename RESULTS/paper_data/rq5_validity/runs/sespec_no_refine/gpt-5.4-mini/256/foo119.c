
/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  assigns \nothing;
  ensures (\exists integer i; 0 <= i < \at(args_len,Pre) && \at(args[i],Pre) == Array && \result == i) ||
          (\forall integer i; 0 <= i < \at(args_len,Pre) ==> \at(args[i],Pre) != Array && \result == \at(args_len,Pre));
*/
int foo119(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
            
        /*@
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= ret <= top + 1));
          loop invariant (0 <= \at(args_len,Pre) - 1) ==> (((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= top < \at(args_len,Pre)));
          loop invariant (!(0 <= \at(args_len,Pre) - 1)) ==> ((top == \at(args_len,Pre) - 1)&&(ret == 0)&&(Array == \at(Array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns i, ret, top;
        */
        while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
            
		return ret;
}
