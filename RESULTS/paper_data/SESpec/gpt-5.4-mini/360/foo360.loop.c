
/*@
  requires size >= 1;
*/
int foo360(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c;
          loop invariant c <= size + 1;
          loop invariant total == c / 2;
          loop invariant average == total * total;
          loop invariant average >= 0;
          loop invariant total >= 0;
          loop invariant (c % 2 == 0) ==> (average == total * total);
          loop invariant (c <= size) ==> (average == total * total);
          loop invariant (c <= size) ==> (average >= total);
          loop invariant (c <= size) ==> (total == c / 2);
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
