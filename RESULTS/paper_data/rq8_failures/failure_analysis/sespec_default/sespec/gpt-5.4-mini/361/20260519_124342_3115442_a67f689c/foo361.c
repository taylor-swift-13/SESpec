
/*@ 
  assigns \nothing;
  
*/
int foo361(int size) {

		int average = 0;
		int total = 0;
		
            /*@
          loop invariant size == \at(size,Pre);
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
