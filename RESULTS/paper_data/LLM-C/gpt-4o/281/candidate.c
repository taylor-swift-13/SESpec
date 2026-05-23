/*@ 
    requires num > 0;
    ensures \result == "Even" || \result == "Odd";
    ensures \result == "Even" <==> (\exists integer count; count == (\sum integer i; 1 <= i <= num && num % i == 0 ? 1 : 0) && count % 2 == 0);
    ensures \result == "Odd" <==> (\exists integer count; count == (\sum integer i; 1 <= i <= num && num % i == 0 ? 1 : 0) && count % 2 != 0);
    assigns \nothing;
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		loop invariant 1 <= index <= num + 1;
		loop invariant result == (\sum integer i; 1 <= i < index && num % i == 0 ? 1 : 0);
		loop assigns index, result;
		loop variant num - index;
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
