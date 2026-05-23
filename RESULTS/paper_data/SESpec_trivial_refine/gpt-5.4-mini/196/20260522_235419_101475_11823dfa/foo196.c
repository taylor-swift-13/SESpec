
        /*@
        */

/*@
  requires 0 <= array;
  requires 0 <= a_len;
  requires array <= a_len;
  requires \valid_read(a + (0 .. array-1));
  assigns \nothing;
  ensures array == 0 ==> \result == 1;
  ensures array > 0 ==> 1 <= \result;
  ensures array > 0 ==> \result <= array;
  ensures array > 0 ==> \result >= 1;
  ensures array > 0 ==> \result <= a_len;
  ensures \result == 1 ==> array == 0 || array > 0;
*/
int foo196(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= array;
          loop invariant 0 <= step <= n;
          loop invariant 0 <= max <= n;
          loop invariant 0 <= stop <= n;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant max_so_far >= max_ending_here;
          loop assigns n, max_so_far, max_ending_here, max, stop, step;
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
