
/*@
  requires size >= 2;
  assigns \nothing;
*/
int foo363(int size) {

		int average = 0;
		int total = 0;
		
        /*@
          loop invariant c >= 1;
          loop invariant size == \at(size,Pre);
          loop invariant total == (c - 1) / 2;
          loop invariant 0 <= average;
          loop invariant average >= total;
          loop invariant (c % 2 == 0) ==> average >= total;
          loop invariant (c > 1) ==> total >= 0;
          loop invariant (c <= \at(size,Pre)) ==> (total >= 0);
          loop invariant (c <= \at(size,Pre)) ==> (average >= 0);
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
