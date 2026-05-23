
/*@
  logic integer odd_count(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(args, lo, hi - 1) + (args[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@ 
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
*/
int foo267(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
            /*@
          loop invariant 0 <= start <= index;
          loop invariant start == odd_count(args, 0, index);
          loop invariant ret == 0 || ret % 2 != 0;
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < index ==> args[k] == \at(args[k],Pre);
          loop assigns index, ret, start;
            */
            for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
            
		return ret;
}
