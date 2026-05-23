
/*@
  logic integer odd_sum(integer n) =
    n <= 0 ? 0 : odd_sum(n - 1) + ((n % 2 != 0) ? n : 0);

  logic integer odd_count(integer n) =
    n <= 0 ? 0 : odd_count(n - 1) + ((n % 2 != 0) ? 1 : 0);
*/

int foo250(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop assigns index, average, total;
            */
            for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
            
		return average / total;
}
