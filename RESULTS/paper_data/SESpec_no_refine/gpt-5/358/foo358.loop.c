
/*@
  logic integer sum_odd_upto(integer n) =
    n <= 0 ? 0 :
    (n % 2 == 1 ? n + sum_odd_upto(n - 1) : sum_odd_upto(n - 1));
*/

int foo358(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index <= \at(size,Pre)) ==> (sum_odd_upto(index - 1) >= 0 && total >= 0);
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
