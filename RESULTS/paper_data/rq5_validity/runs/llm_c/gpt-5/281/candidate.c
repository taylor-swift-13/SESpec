const char * countDivisors(int num);

/*@ 
  requires num >= 1;
  assigns \nothing;

  ensures \result == "Even" || \result == "Odd";

  ensures 
    (\let res = \numof integer j; 1 <= j <= num && num % j == 0;
      (\result == "Even") <==> (res % 2 == 0));

  ensures 
    (\result == "Odd") <==> (\exists integer k; k >= 1 && k*k == num);
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		  loop invariant 1 <= index <= num + 1;
		  loop invariant 0 <= result <= index - 1;
		  loop invariant 
		    result == \numof integer j; 1 <= j < index && num % j == 0;
		  loop assigns index, result;
		  loop variant num - index + 1;
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
