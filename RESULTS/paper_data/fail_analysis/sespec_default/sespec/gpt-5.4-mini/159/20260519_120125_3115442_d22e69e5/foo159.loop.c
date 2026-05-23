
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo159(int * args, int args_len, int array) {

		int ret = 0;
		
            
        /*@
          loop invariant (0 < \at(array,Pre)) ==> (0 <= ret <= array);
          loop invariant (!(0 < \at(array,Pre))) ==> ((ret == 0)&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
            */
            while (ret < array) {
			if (args[ret] <= 0 || args[ret] > array
					|| args[ret] == ret + 1) {
				ret++;
			} else {
				int j = args[ret];
				args[ret] = args[j - 1];
				args[j - 1] = j;
			}
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (ret < array) ==> (\forall integer k; 0 <= k < ret ==> args[k] == k + 1);
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
