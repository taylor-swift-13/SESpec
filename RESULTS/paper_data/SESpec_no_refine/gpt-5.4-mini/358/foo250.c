
/*@
  ensures size <= 0 ==> \result == 0 / 0;
  ensures size > 0 ==> \result == odd_sum(size) / odd_count(size);
  assigns \nothing;
*/
int foo250(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop invariant 1 <= index <= size + 1;
          loop invariant average == odd_sum(index - 1);
          loop invariant total == odd_count(index - 1);
          loop assigns index, average, total;
            */
            for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
            
		return average / total;
}
