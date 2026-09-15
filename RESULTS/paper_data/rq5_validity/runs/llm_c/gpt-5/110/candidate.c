/*@ 
  logic integer iabs(integer x) = x >= 0 ? x : -x;

  predicate divides(integer d, integer x) = d > 0 && (iabs(x) % d == 0);
*/

/*@ 
  requires \true;
  assigns \nothing;

  behavior both_zero:
    assumes num1 == 0 && num2 == 0;
    ensures \result == -1;

  behavior one_zero_1:
    assumes num1 == 0 && num2 != 0;
    ensures \result == iabs(\old(num2));

  behavior one_zero_2:
    assumes num1 != 0 && num2 == 0;
    ensures \result == iabs(\old(num1));

  behavior both_non_zero:
    assumes num1 != 0 && num2 != 0;
    ensures \result > 0;
    ensures divides(\result, \old(num1)) && divides(\result, \old(num2));
    ensures \forall integer d; d > 0 ==> ((divides(d, \old(num1)) && divides(d, \old(num2))) ==> d <= \result);
    ensures \result <= (iabs(\old(num1)) <= iabs(\old(num2)) ? iabs(\old(num1)) : iabs(\old(num2)));

  complete behaviors both_zero, one_zero_1, one_zero_2, both_non_zero;
  disjoint behaviors both_zero, one_zero_1, one_zero_2, both_non_zero;
*/
int gcd(int num1, int num2);

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
          loop invariant 1 <= i <= ((num1 <= num2) ? num1 : num2) + 1;
          loop invariant 1 <= result <= (i-1 <= ((num1 <= num2) ? num1 : num2) ? i-1 : ((num1 <= num2) ? num1 : num2));
          loop invariant divides(result, num1) && divides(result, num2);
          loop invariant \forall integer d; 1 <= d < i ==> ((num1 % d == 0 && num2 % d == 0) ==> d <= result);
          loop assigns result, i;
          loop variant ((num1 <= num2) ? num1 : num2) - i + 1;
        */
		for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
		return result;
}
