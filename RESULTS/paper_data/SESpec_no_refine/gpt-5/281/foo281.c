
/*@
  assigns \nothing;
  ensures (\let d = count_div(num, 1, num + 1);
           (d % 2 == 0) ==> \result == "Even" &&
           (d % 2 != 0) ==> \result == "Odd");
*/
const char * foo281(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result <= index - 1;
          loop invariant result == count_div(num, 1, index);
          loop assigns index, result;
            */
            for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
