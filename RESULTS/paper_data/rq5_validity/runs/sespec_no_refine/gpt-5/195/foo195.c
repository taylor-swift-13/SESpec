
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    hi <= lo ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
*/
int foo195(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count <= n;
          loop invariant max_ending_here == sum(a, count, n);
          loop invariant a == \at(a,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant array == \at(array,Pre);
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
