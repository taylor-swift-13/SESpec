
/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  assigns args[0 .. args_len - 1], ret, stop;
  ensures (0 <= \result && \result < args_len) ==> args[\result] == \result;
  ensures (\result == -1) ==> (\forall integer j; 0 <= j < args_len ==> args[j] != j);
*/

int foo123(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /*@
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= ret <= stop + 1));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret <= stop + 1));
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant 0 <= ret;
          loop invariant stop < args_len;
          loop invariant -1 <= stop;
          loop assigns i, ret, stop;
            */
            while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
            
		return -1;
}
