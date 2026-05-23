
/*@
  assigns \nothing;
*/
int foo363(int size) {
		int average = 0;
		int total = 0;
		
            /*@
          loop invariant 1 <= c;
          loop invariant size == \at(size,Pre);
          loop invariant average >= 0;
          loop invariant total >= 0;
          loop invariant average >= total;
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
