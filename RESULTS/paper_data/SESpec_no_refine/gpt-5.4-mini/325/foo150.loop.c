
/*@
  logic integer fact_up_to(integer n) =
    n <= 1 ? 1 : n * fact_up_to(n - 1);
*/

int foo150(int num) {

		int first = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first == fact_up_to(j - 1);
          loop invariant j >= 2;
          loop invariant num == \at(num,Pre);
          loop assigns j, first;
            */
            for (int j = 2; j <= num; j++) {
			first *= j;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first >= 0;
          loop invariant result >= 0;
          loop invariant first == 0 || first > 0;
          loop invariant (!(first > 0)) ==> ();
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
