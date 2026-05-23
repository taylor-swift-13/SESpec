
int foo362(int size) {

		int result = 0;
		int total = 0;
		
        /*@
          loop invariant c >= 1;
          loop invariant size == \at(size,Pre);
          loop invariant total >= 0;
          loop invariant result >= 0;
          loop assigns c, result, total;
        */
        for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
            
		return result / total;
}
