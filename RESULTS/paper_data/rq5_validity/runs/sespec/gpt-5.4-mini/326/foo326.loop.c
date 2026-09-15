
/*@
  logic integer fact(integer n) =
    n <= 1 ? 1 : n * fact(n - 1);
*/

int foo326(int num) {

		int first = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= c;
          loop invariant first == fact(c - 1);
          loop invariant first >= 1;
          loop invariant num == \at(num,Pre);
          loop invariant (c <= num) ==> (first > 0);
          loop invariant (c <= num) ==> (first == fact(c - 1) && first >= 1);
          loop assigns c, first;
            */
            for (int c = 2; c <= num; c++) {
			first *= c;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= first;
          loop invariant 0 <= result <= 9;
          loop invariant num == \at(num,Pre);
          
          loop invariant result >= 0;
          loop invariant first == 0 || first > 0;
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
