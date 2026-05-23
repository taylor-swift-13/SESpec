
/*@
  requires size >= 0;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 && size % 2 == 0 ==> 2 * \result == size;
  ensures size > 0 && size % 2 != 0 ==> \result <= size;
  ensures size > 0 ==> \result >= 1;
*/
int foo358(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= index <= size + 1;
          loop invariant 0 <= total <= index / 2;
          loop invariant 0 <= average;
          loop invariant average == total * total;
          loop invariant total == index / 2;
          loop invariant (index <= size) ==> (average == total * total);
          loop invariant (index <= size) ==> (total == index / 2);
          loop invariant size == \at(size,Pre);
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
