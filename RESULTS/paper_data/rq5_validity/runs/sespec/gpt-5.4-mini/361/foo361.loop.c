
/*@
  logic integer even_sum(integer n) =
    n <= 0 ? 0 : even_sum(n - 1) + ((n % 2 == 0) ? n : 0);

  logic integer even_count(integer n) =
    n <= 0 ? 0 : even_count(n - 1) + ((n % 2 == 0) ? 1 : 0);
*/

int foo361(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j;
          loop invariant average >= 0;
          loop invariant total >= 0;
          loop invariant average == even_sum(j - 1);
          loop invariant total == even_count(j - 1);
          loop invariant total <= j - 1;
          loop invariant average >= total;
          loop invariant (j == 1) || (j <= size + 1);
          loop invariant (j <= size) ==> (average >= total);
          loop invariant (j <= size) ==> (average >= 0);
          loop invariant (j <= size) ==> (total >= 0);
          loop invariant (j <= size) ==> (total <= j - 1);
          loop invariant (j <= size) ==> (average == even_sum(j - 1));
          loop invariant (j <= size) ==> (total == even_count(j - 1));
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
