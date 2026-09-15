
/*@ logic integer sum_upto(integer n) = (n <= 0 ? 0 : n + sum_upto(n - 1)); */

int foo361(int size) {

		int average = 0;
		int total = 0;
		
            /*@
          loop invariant size == \at(size,Pre);
          loop assigns j, average, total;
            */
            for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
            
		return average / total;
}
