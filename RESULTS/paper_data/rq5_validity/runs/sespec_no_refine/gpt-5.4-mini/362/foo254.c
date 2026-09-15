
/*@
  assigns \nothing;
*/
int foo254(int size) {

		int result = 0;
		int total = 0;
		
            
        /*@
          loop invariant size == \at(size,Pre);
          loop assigns c, result, total;
          loop invariant 0 <= total;
        */
        for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
            
		return result / total;
}
