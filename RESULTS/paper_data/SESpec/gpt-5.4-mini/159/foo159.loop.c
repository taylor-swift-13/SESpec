
/*@
  requires array >= 0;
  requires \valid(args + (0 .. array - 1));
*/

int foo159(int * args, int args_len, int array) {

		int ret = 0;
		
            /*@
          loop invariant 0 <= ret <= array;
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop assigns args[0..array-1], ret;
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
          loop invariant \forall integer k; 0 <= k < ret ==> args[k] == k + 1;
          loop invariant \forall integer k; 0 <= k < ret ==> 1 <= args[k] <= array;
          loop invariant (ret == array) ==> (\forall integer k; 0 <= k < array ==> args[k] == k + 1);
          loop invariant (!(ret < array)) ==> (\forall integer k; 0 <= k < array ==> args[k] == k + 1);
          loop assigns ret;
            */
            for (ret = 0; ret < array; ret++) {
			if (args[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
