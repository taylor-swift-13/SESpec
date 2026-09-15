
int foo361(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= j;
              loop invariant size == \at(size,Pre);
              loop invariant average >= 0;
              loop invariant total >= 0;
              loop invariant total <= j - 1;
              loop invariant total == (j - 1) / 2;
              loop invariant average == ((j - 1) / 2) * (((j - 1) / 2) + 1);
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
