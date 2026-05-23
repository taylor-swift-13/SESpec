
        /*@
        */
        
int foo194(int * a, int a_len, int Array) {

		int max_so_far = 0;
		int max_ending_here = 0;
		int max = 0;
		int stop = 0;
		int step = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= Array;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= step <= n;
          loop invariant 0 <= max <= stop <= n;
          loop assigns n, max_ending_here, max_so_far, max, stop, step;
            */
            for (int n = 0; n < Array; n++) {
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
