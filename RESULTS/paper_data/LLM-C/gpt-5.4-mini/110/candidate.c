/*@
    requires num1 != INT_MIN;
    requires num2 != INT_MIN;
    assigns \nothing;
    ensures (num1 == 0 && num2 == 0) ==> \result == -1;
    ensures (num1 == 0 || num2 == 0) && !(num1 == 0 && num2 == 0) ==> \result == ((num1 < 0 ? -num1 : num1) > (num2 < 0 ? -num2 : num2) ? (num1 < 0 ? -num1 : num1) : (num2 < 0 ? -num2 : num2));
    ensures !(num1 == 0 || num2 == 0) ==> \result >= 1;
*/
int gcd(int num1, int num2);

#include <limits.h>

int gcd(int num1, int num2) {

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
		    loop invariant 1 <= i <= num1 + 1;
		    loop invariant 1 <= result <= i - 1 || (i == 1 && result == 1);
		    loop assigns i, result;
		    loop variant (num1 < num2 ? num1 : num2) - i + 1;
		*/
		for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
		return result;
}
