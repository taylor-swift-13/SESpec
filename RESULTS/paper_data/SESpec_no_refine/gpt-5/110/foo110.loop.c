
/*@
*/
        
int foo110(int num1, int num2) {

		int result = 1;
	 	num1 = (0 <= num1) ? num1 : -num1;
		num2 = (0 <= num2) ? num2 : -num2;

		if (num1 == 0 && num2 == 0) {
			return -1;
		}

		if (num1 == 0 || num2 == 0) {
			return (num1 > num2) ? num1 : num2;
		}

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant i <= num1 + 1;
          loop invariant i <= num2 + 1;
          loop invariant 1 <= result <= i - 1;
          loop invariant \forall integer d; 1 <= d < i ==> ( (num1 % d == 0 && num2 % d == 0) ==> result >= d );
          loop invariant num1 % result == 0;
          loop invariant num2 % result == 0;
          loop assigns result, i;
            */
            for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
            
		return result;
}
