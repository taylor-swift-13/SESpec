
int foo259(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant stop < array;
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant (i <= stop) ==> (0 <= i && stop < array);
          loop invariant (0 <= \at(array,Pre) - 1) ==> (0 <= i <= \at(array,Pre));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (-1 <= stop < \at(array,Pre));
          loop invariant (0 <= \at(array,Pre) - 1) ==> (i <= stop + 1);
          loop assigns i, stop;
            */
            while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
            
		return -1;
}
