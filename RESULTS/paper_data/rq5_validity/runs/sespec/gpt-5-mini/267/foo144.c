
/*@
  // Logic function that counts number of odd elements in args[0..hi-1]
  logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi-1] % 2 != 0) ? 1 : 0);
*/

/*@
  // Logic to get the last odd element among a[0..hi-1] that has odd occurrence index
  // Returns 0 when none.
  logic integer last_odd_at_odd_occurrence(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi-1] % 2 != 0
                ? (odd_count(a, lo, hi) % 2 == 1 ? a[hi-1] : last_odd_at_odd_occurrence(a, lo, hi-1))
                : last_odd_at_odd_occurrence(a, lo, hi-1));
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires 0 <= array <= args_len;
  assigns \nothing;   
*/
int foo144(int * args, int args_len, int array) {

	int ret = 0;
	int start = 0;
	
	/*@
	  loop invariant 0 <= index;
	  loop invariant 0 <= start && start <= index;
	  loop invariant start == odd_count(args, 0, index);
	  loop invariant ret == last_odd_at_odd_occurrence(args, 0, index);
	  loop invariant array == \at(array,Pre);
	  loop invariant args_len == \at(args_len,Pre);
	  loop invariant args == \at(args,Pre);
	  loop invariant \forall integer k; 0 <= k < \at(array,Pre) ==> args[k] == \at(args[k],Pre);
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
