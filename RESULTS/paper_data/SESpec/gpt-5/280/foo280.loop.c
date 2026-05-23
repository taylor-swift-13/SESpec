
/*@
  logic integer divcnt(integer n, integer hi) =
    hi <= 0 ? 0 : divcnt(n, hi - 1) + (n % hi == 0 ? 1 : 0);
*/

const char * foo280(int number) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c;
          loop invariant (\at(number,Pre) >= 0) ==> (c <= \at(number,Pre) + 1);
          loop invariant 0 <= result <= c - 1;
          loop invariant result == divcnt(\at(number,Pre), c - 1);
          loop invariant \forall integer k; 1 <= k < c ==> divcnt(\at(number,Pre), k) <= divcnt(\at(number,Pre), c - 1);
          loop invariant result > 0 ==> \exists integer k; 1 <= k < c && (\at(number,Pre) % k == 0);
          loop invariant (\at(number,Pre) >= 0 && c == \at(number,Pre) + 1) ==> result == divcnt(\at(number,Pre), \at(number,Pre));
          loop invariant \forall integer k; 1 <= k < c ==> (k <= c - 1);
          loop invariant (c <= \at(number,Pre)) ==> (1 <= c);
          loop invariant (c <= \at(number,Pre)) ==> ((0 <= result <= c - 1) && (result == divcnt(\at(number,Pre), c - 1)));
          loop invariant number == \at(number,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
