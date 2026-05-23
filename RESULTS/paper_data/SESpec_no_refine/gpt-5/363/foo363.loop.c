
/*@
  // Counts how many even integers are in the inclusive range [1..n].
  logic integer evencount(integer n) =
    n <= 0 ? 0 : (evencount(n - 1) + ((n % 2 == 0) ? 1 : 0));

  // Sums the even integers in the inclusive range [1..n].
  logic integer evensum(integer n) =
    n <= 0 ? 0 : (evensum(n - 1) + ((n % 2 == 0) ? n : 0));
*/

int foo363(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop assigns c, average, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
            
		return average / total;
}
