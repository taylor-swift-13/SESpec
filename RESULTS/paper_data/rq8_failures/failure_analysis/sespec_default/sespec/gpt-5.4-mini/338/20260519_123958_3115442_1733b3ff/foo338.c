
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/



int foo338(int num) {

		int result = 0;
		
            /*@
              loop invariant 2 <= j;
              loop invariant result == 0 || result >= 2;
              loop assigns num, result;
            */
            for (int j = 2; j <= num; j++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            
            /*@
              loop invariant 2 <= j;
              loop invariant result == 0 || result >= 2;
              loop assigns num, result;
            */
            while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
            
		return result;
}
