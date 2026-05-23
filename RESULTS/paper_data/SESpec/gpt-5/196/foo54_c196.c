
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \forall integer i; 0 <= i < a_len ==> a[i] == \at(a[i], Pre);
  ensures a == \at(a, Pre);
  ensures a_len == \at(a_len, Pre);
  ensures array == \at(array, Pre);
*/
int foo54_c196(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a == \at(a,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant 0 <= n;
          loop invariant 0 <= step <= n+1;
          loop invariant (n == 0) ==> (step == 0 && max == 0 && stop == 0 && max_so_far == 0 && max_ending_here == 0);
          loop invariant max_so_far >= 0;
          loop invariant max_ending_here >= 0;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
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
