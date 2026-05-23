#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*@
    requires number >= 0;
    assigns \nothing;
    ensures (\sum integer i; 1 <= i <= number; (number % i == 0 ? 1 : 0)) % 2 == 0 ==> \result == "Even";
    ensures (\sum integer i; 1 <= i <= number; (number % i == 0 ? 1 : 0)) % 2 != 0 ==> \result == "Odd";
*/
const char * countDivisors(int number) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= number + 1;
		    loop invariant 0 <= result <= c-1;
		    loop invariant result == \sum integer i; 1 <= i <= c-1; (number % i == 0 ? 1 : 0);
		    loop assigns c, result;
		    loop variant number - c + 1;
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
