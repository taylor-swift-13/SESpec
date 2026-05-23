
/*@
  logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1);
*/

/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= 9;
  
  ensures number <= 1 ==> \result >= 0;
*/
int foo324(int number) {

		int first = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= c;
          loop invariant first == fact(c - 1);
          loop invariant first >= 1;
          loop invariant number == \at(number,Pre);
          loop assigns c, first;
            */
            for (int c = 2; c <= number; c++) {
			first *= c;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result <= 9;
          loop invariant first >= 0;
          loop invariant (first > 0) ==> (result >= 0 && result <= 9);
          loop invariant (!(first > 0)) ==> (first == 0);
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
