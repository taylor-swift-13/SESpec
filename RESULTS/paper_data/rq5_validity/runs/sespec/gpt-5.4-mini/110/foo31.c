
/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@ 
  ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
  ensures (\old(num1) != 0 || \old(num2) != 0) && (abs_int(\old(num1)) == 0 || abs_int(\old(num2)) == 0) ==> 
            \result == (abs_int(\old(num1)) > abs_int(\old(num2)) ? abs_int(\old(num1)) : abs_int(\old(num2)));
  ensures (\old(num1) != 0 || \old(num2) != 0) && abs_int(\old(num1)) != 0 && abs_int(\old(num2)) != 0 ==> 
            (1 <= \result && \result <= abs_int(\old(num1)) && 1 <= \result && \result <= abs_int(\old(num2)));
  assigns \nothing;
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
		  loop invariant num1 % result == 0;
		  loop invariant num2 % result == 0;
		  loop invariant num1 >= 0 && num2 >= 0;
		  loop invariant 1 <= i <= num1 + 1;
		  loop invariant result <= i;
		  loop assigns i, result;
		*/
		for (int i = 1; i <= num1 && i <= num2; i++) {
			if (num1 % i == 0 && num2 % i == 0) {
				result = i;
			}
		}
            
		return result;
}
