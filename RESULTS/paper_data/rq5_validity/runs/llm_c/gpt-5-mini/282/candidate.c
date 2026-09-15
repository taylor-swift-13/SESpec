/*@
    requires num >= 0;
    assigns \nothing;
    ensures (\result == "Even") || (\result == "Odd");
    ensures num == 0 ==> \result == "Even";
    ensures num > 0 ==> (
        (\exists integer k; 1 <= k && k * k == num) ==> \result == "Odd"
    );
    ensures num > 0 ==> (
        (\forall integer k; k >= 1 ==> k * k != num) ==> \result == "Even"
    );
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		  loop invariant 1 <= c <= num + 1;
		  loop invariant 0 <= result <= num;
		  loop invariant result <= c-1;
		  loop assigns c, result;
		  loop variant num - c + 1;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
