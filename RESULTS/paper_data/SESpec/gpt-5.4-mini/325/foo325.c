
/*@ logic integer leading_digit(integer n) =
      n < 10 ? n : leading_digit(n / 10); */
/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */
/*@
  requires num == 1;
  assigns \nothing;
  ensures 0 <= \result <= 9;
  ensures \result >= 0;
*/
int foo325(int num) {

		int first = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= j;
          loop invariant first == fact(j - 1);
          loop invariant 1 <= first;
          loop invariant num == \at(num,Pre);
          loop assigns j, first;
            */
            for (int j = 2; j <= num; j++) {
			first *= j;
		}
            
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= first;
          loop invariant 0 <= result <= 9;
          
          loop invariant result == 0 || result > 0;
          loop assigns result, first;
            */
            while (first > 0) {
			result = first % 10;
			first /= 10;
		}
            
		return result;
}
