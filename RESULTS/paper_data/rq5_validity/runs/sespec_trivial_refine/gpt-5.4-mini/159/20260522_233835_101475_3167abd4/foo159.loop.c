
/*@
  requires 0 <= args_len;
  requires \valid(args + (0 .. args_len-1));
  requires array <= args_len;
*/

int foo159(int * args, int args_len, int array) {

		int ret = 0;
		
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant \forall integer i; 0 <= i < ret ==> args[i] == i + 1;
          loop assigns ret, args[..];
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
            
		
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant \forall integer i; 0 <= i < ret ==> args[i] == i + 1;
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
