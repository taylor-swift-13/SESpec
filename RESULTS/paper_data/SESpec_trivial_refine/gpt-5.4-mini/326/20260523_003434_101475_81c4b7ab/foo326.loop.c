
/*@
logic integer fact(integer n) = (n <= 1) ? 1 : n * fact(n - 1);
*/


int foo326(int num) {

		int first = 1;
		
        /*@
          loop assigns c, first;
          loop invariant 2 <= c <= num + 1;
          loop invariant first == fact(c - 1);
          loop invariant first >= 1;
        */
            /*@
          loop invariant 2 <= c <= num + 1;
          loop invariant first == fact(c - 1);
          loop invariant first >= 1;
          loop assigns c, first;
            */
            for (int c = 2; c <= num; c++) {
			first *= c;
		}
            
		int result = 0;
		
            /*@
          loop invariant first >= 0;
          loop invariant 0 <= result <= 9;
          loop assigns first, result;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
