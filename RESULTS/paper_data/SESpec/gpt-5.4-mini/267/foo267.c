
/*@
  logic integer oddcount(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : oddcount(args, lo, hi - 1) + ((args[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer oddret(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : (((args[hi - 1] % 2) != 0) && ((oddcount(args, lo, hi - 1) + 1) % 2 != 0))
               ? args[hi - 1]
               : oddret(args, lo, hi - 1);
*/

/*@
  requires array >= 0;
  requires \valid_read(args + (0..array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 0;
  ensures \result == oddret(args, 0, array);
  
*/
int foo267(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /*@
          loop invariant 0 <= index <= array;
          loop invariant 0 <= start <= index;
          loop invariant start == oddcount(args, 0, index);
          loop invariant ret == oddret(args, 0, index);
          loop invariant \forall integer k; 0 <= k < index ==> args[k] == \at(args[k], Pre);
          loop invariant array == \at(array, Pre);
          loop invariant args_len == \at(args_len, Pre);
          loop invariant args == \at(args, Pre);
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
