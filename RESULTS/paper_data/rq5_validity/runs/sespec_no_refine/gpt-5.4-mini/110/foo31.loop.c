
/*@ logic integer gcd_logic(integer a, integer b) =
      (a == 0 || b == 0) ? (a + b) :
      ((a <= b) ? gcd_logic(a, b - a) : gcd_logic(a - b, b));
*/

int foo31(int num1, int num2) {

		int result = 1;
	 	num1 = (0 <= num1) ? num1 : -num1;
		num2 = (0 <= num2) ? num2 : -num2;

		if (num1 == 0 && num2 == 0) {
			return -1;
		}

		if (num1 == 0 || num2 == 0) {
			return (num1 > num2) ? num1 : num2;
		}

		
        /*@
          loop invariant 1 <= result;
          loop invariant result <= num1;
          loop invariant result <= num2;
          loop invariant result <= i;
          loop invariant num1 % result == 0;
          loop invariant num2 % result == 0;
          loop invariant (\forall integer d; 1 <= d <= i && num1 % d == 0 && num2 % d == 0 ==> d <= result);
        */
        
            /*@
          loop invariant (!(i <= num1 && i <= num2)) ==> ();
          loop assigns i, result;
            */
            for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
            
		return result;
}
