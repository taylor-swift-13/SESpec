
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi-1) + a[hi-1];
*/

/*@
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires \valid_read(a + (0 .. \at(a_len,Pre)-1));
  assigns \nothing;
            0 <= i <= j < \at(array,Pre) &&
            j - i + 1 == \result &&
            (\forall integer i2, j2;
               0 <= i2 <= j2 < \at(array,Pre) ==>
                 sum(a, i2, j2+1) <= sum(a, i, j+1));
*/
int foo196(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /*@
          loop invariant (n < \at(array,Pre)) ==> (0 <= max_so_far);
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer i; 0 <= i < \at(a_len,Pre) ==> a[i] == \at(a[i],Pre);
          loop assigns n, max_ending_here, max_so_far, max, stop, step;
            */
            for (int n = 0; n < array; n++) {
			max_ending_here += a[n];
			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
				max = step;
				stop = n;
			}
			if (max_ending_here < 0) {
				max_ending_here = 0;
				step = n + 1;
			}
		}
            
		return stop - max + 1;
}
