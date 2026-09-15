
/*@
logic integer fact(integer n);
axiom fact_0: fact(0) == 1;
axiom fact_succ: \forall integer n; n >= 0 ==> fact(n + 1) == (n + 1) * fact(n);
*/


int foo324(int number) {

		int first = 1;
		
        /*@
          loop invariant 2 <= c <= number + 1;
          loop invariant first == fact(c - 1);
          loop invariant first > 0;
          loop assigns c, first;
        */
        
            /*@
          loop invariant 2 <= c <= number + 1;
          loop invariant first == fact(c - 1);
          loop invariant first > 0;
          loop assigns c, first;
            */
            for (int c = 2; c <= number; c++) {
			first *= c;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
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
