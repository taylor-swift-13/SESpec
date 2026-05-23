/*@
    requires num >= 1;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures (\let int result = (\num_of int index; 1 <= index <= num && num % index == 0);
             result % 2 == 0) ==> \result == "Even";
    ensures (\let int result = (\num_of int index; 1 <= index <= num && num % index == 0);
             result % 2 != 0) ==> \result == "Odd";
*/
const char * countDivisors(int num);

const char * countDivisors(int num) {

		int result = 0;
		/*@
		    loop invariant 1 <= index <= num + 1;
		    loop invariant 0 <= result <= index - 1;
		    loop invariant result == (\num_of int k; 1 <= k < index && num % k == 0);
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
