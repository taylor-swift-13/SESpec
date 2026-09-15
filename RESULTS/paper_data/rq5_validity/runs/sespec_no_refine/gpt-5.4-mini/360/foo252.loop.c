
/*@
*/

int foo252(int size) {

		int average = 0;
		int total = 0;
		
            
        /*@
          loop invariant (c <= \at(size,Pre)) ==> (average == (c / 2) * (c / 2) + (c % 2) * ((c / 2) + 1));
          loop invariant (c <= \at(size,Pre)) ==> (total == c / 2);
          loop invariant (!(c <= \at(size,Pre))) ==> ((total == 0)&&(average == 0)&&(size == \at(size,Pre)));
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
