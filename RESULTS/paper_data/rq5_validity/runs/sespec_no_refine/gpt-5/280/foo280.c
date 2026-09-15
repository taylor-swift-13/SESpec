
/*@
  assigns \nothing;
  ensures (\result == "Even") <==> (cnt_divs(number, number) % 2 == 0);
  ensures (\result == "Odd")  <==> (cnt_divs(number, number) % 2 != 0);
*/
const char * foo280(int number) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result <= c - 1;
          loop invariant result == cnt_divs(number, c - 1);
          loop invariant (c <= \at(number,Pre)) ==> (result == cnt_divs(\at(number,Pre), c - 1));
          loop invariant (c <= \at(number,Pre)) ==> (result >= 0);
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
