
        /*@
        */
        
int foo362(int size) {

		int result = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= size + 1;
          loop invariant total == \numof(int i, 1, c - 1, i % 2 == 0);
          loop invariant result == \sum(int i, 1, c - 1, (i % 2 == 0 ? i : 0));
          loop invariant total >= 0;
          loop invariant result >= 0;
          loop assigns c, result, total;
          loop variant size - c + 1;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
            
		return result / total;
}
