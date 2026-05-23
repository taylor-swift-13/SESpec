
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires array >= 0;
  requires array <= 0;
  requires array == 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo195(int * a, int a_len, int array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int count = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= stop <= n;
          loop invariant 0 <= count <= n + 1;
          loop invariant 0 <= max <= n + 1;
          loop invariant max_so_far >= max_ending_here;
          loop invariant max <= stop + 1;

          loop invariant (n < \at(array,Pre)) ==> (stop - max + 1 >= 0);
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_so_far));
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max_ending_here));
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= max));
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= stop));
          loop invariant (n < \at(array,Pre)) ==> (((count == 0)&&(stop == 0)&&(max == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(array == \at(array,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= count));
          loop invariant array == \at(array,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant a == \at(a,Pre);
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
