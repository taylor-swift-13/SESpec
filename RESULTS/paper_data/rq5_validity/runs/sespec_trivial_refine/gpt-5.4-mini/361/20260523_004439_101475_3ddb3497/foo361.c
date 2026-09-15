
/*@
requires size >= 2;
assigns \nothing;
ensures \result == size / 2 + 1;
ensures \result >= 2;
*/

int foo361(int size) {

		int average = 0;
		int total = 0;
		
        /*@
          loop invariant 1 <= j <= size + 1;
          loop invariant total == (j - 1) / 2;
          loop invariant average == total * (total + 1);
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
