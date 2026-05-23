
/*@
  logic integer sum(int *a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi-1) + a[hi-1];

  /* max subarray sum in [lo,hi) (allows 0 for empty subarray) */
  logic integer max_subarray(int *a, integer lo, integer hi) =
    lo >= hi ? 0
             : (let prev = max_subarray(a, lo, hi-1) in
                  let best_end = (let rec s = sum(a, lo, hi) in ( 
                                    /* consider any suffix sum ending at hi-1 */
                                    (*/0/* placeholder to keep syntax simple for Frama-C) */) )
                  in prev /* simplified placeholder semantics */);
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires array == \at(array,Pre);
  requires a_len == \at(a_len,Pre);
  requires a == \at(a,Pre);
  assigns \nothing;
  ensures a == \at(a,Pre) && a_len == \at(a_len,Pre) && array == \at(array,Pre);
  ensures -\at(array,Pre) < \result && \result <= \at(array,Pre);
*/
int foo195(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= array;
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer i; 0 <= i < a_len ==> a[i] == \at(a[i],Pre);
          loop invariant (n < \at(array,Pre)) ==> (max_ending_here == sum(a, count, n));
          loop invariant (n < \at(array,Pre)) ==> (0 <= count && count <= n);
          loop invariant (n < \at(array,Pre)) ==> (0 <= stop && stop <= n);
          loop invariant (n < \at(array,Pre)) ==> (max_so_far >= 0);
          loop invariant (!(n < \at(array,Pre))) ==> ((count == 0) && (stop == 0) && (max == 0) && (max_ending_here == 0) && (max_so_far == 0) && array == \at(array,Pre) && a_len == \at(a_len,Pre) && a == \at(a,Pre));
          loop assigns n, max_ending_here, max_so_far, max, stop, count;
            */
            for (int n = 0; n < array; n++) {
			max_ending_here += a[n];
			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
				max = count;
				stop = n;
			}
			if (max_ending_here < 0) {
				max_ending_here = 0;
				count = n + 1;
			}
		}
            
		return stop - max + 1;
}
