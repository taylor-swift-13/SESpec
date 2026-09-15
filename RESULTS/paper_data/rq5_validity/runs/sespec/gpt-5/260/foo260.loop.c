
int foo260(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (ret <= stop) ==> (0 <= ret && stop < \at(array,Pre));

          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= ret && ret <= \at(array,Pre)));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= stop && stop <= \at(array,Pre) - 1));
          loop invariant (!(0 <= \at(array,Pre) - 1)) ==> ((stop == \at(array,Pre) - 1)&&(ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre) ;
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
