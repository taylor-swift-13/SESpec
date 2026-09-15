
/*@
logic integer fact(integer n) = (n <= 1 ? 1 : n * fact(n - 1));
*/

int foo325(int num) {

		int first = 1;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first == fact(j - 1);
          loop invariant j >= 2;
          loop assigns first, j;
            */
            for (int j = 2; j <= num; j++) {
			first *= j;
		}
            
		int result = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant first >= 0;
          loop invariant result >= 0 && result <= 9;
          loop assigns first, result;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
