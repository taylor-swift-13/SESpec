
/*@
  requires array >= 0;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
*/
int foo260(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant ret <= stop + 1;
          loop invariant -1 <= stop < array;
          loop invariant 0 <= array;
          loop invariant args == \at(args,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
          loop invariant \exists integer k; 0 <= k < array ==> args[k] == k || ret > stop;
          loop invariant (0 <= \at(array,Pre) - 1) ==> ((0 <= ret <= stop + 1) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret >= 0));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= stop < array));
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop assigns ret, stop;
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
