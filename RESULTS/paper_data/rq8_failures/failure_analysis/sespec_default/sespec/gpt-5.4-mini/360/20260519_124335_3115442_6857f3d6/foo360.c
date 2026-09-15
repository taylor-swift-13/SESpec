
/*@ logic integer odd_sum(integer n) =
      n <= 0 ? 0 : odd_sum(n - 1) + ((n % 2 != 0) ? n : 0); */
/*@ logic integer odd_count(integer n) =
      n <= 0 ? 0 : odd_count(n - 1) + ((n % 2 != 0) ? 1 : 0); */
/*@ 
  assigns \nothing;
*/
int foo360(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop assigns c, average, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
            
		return average / total;
}
