
/*@
logic integer odd_count(integer n) = (n + 1) / 2;
*/

int foo358(int size) {

		int average = 0;
		int total = 0;
		
        /*@
          loop invariant average == total * total;
          loop invariant total == index / 2;
          loop invariant index >= 1;
          loop assigns average, total, index;
        */
        for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
            
		return average / total;
}
