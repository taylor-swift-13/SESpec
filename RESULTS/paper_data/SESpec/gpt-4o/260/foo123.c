
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len > 0 && args_len < 100;
  requires array > 0; // Ensure array is positive to establish invariants
  requires \forall integer k; 0 <= k < args_len ==> 0 <= args[k] < args_len;
  assigns \nothing;
  ensures \result >= 0 ==> args[\result] == \result;
*/
int foo123(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		
        /*@
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant array == \at(array, Pre);
          loop invariant args_len == \at(args_len, Pre);
          loop invariant args == \at(args, Pre);
          loop invariant ret <= stop + 1; // Ensure ret does not exceed stop + 1
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
