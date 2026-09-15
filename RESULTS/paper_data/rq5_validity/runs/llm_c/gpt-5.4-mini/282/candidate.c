/*@
    requires num >= 1;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures ((\result == "Even") <==> ((\sum integer c; 1 <= c <= num && num % c == 0; 1) % 2 == 0));
    ensures ((\result == "Odd") <==> ((\sum integer c; 1 <= c <= num && num % c == 0; 1) % 2 != 0));
*/
const char * countDivisors(int num);

 /*@
    requires num >= 1;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures ((\result == "Even") <==> ((\sum integer c; 1 <= c <= num && num % c == 0; 1) % 2 == 0));
    ensures ((\result == "Odd") <==> ((\sum integer c; 1 <= c <= num && num % c == 0; 1) % 2 != 0));
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= num + 1;
		    loop invariant 0 <= result <= c - 1;
		    loop invariant result == (\sum integer i; 1 <= i < c && num % i == 0; 1);
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
