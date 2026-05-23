
        /*@
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
          loop invariant 0 <= count <= n;
          loop invariant 0 <= max <= n;
          loop invariant 0 <= stop <= n;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant max_so_far >= max_ending_here;
          loop invariant max <= stop;
          loop assigns n, max_so_far, max_ending_here, max, stop, count;
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
