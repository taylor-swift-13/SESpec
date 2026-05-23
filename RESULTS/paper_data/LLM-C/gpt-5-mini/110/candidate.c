int gcd(int num1, int num2);

/*@
    assigns \nothing;
    behavior both_zero:
      assumes \old(num1) == 0 && \old(num2) == 0;
      ensures \result == -1;
    behavior one_zero:
      assumes (\old(num1) == 0 && \old(num2) != 0) || (\old(num1) != 0 && \old(num2) == 0);
      ensures \result == ((\old(num1) >= 0 ? \old(num1) : -\old(num1)) > (\old(num2) >= 0 ? \old(num2) : -\old(num2)) ? (\old(num1) >= 0 ? \old(num1) : -\old(num1)) : (\old(num2) >= 0 ? \old(num2) : -\old(num2)));
    behavior both_nonzero:
      assumes \old(num1) != 0 && \old(num2) != 0;
      ensures \result > 0;
      ensures (\old(num1) >= 0 ? \old(num1) : -\old(num1)) % \result == 0;
      ensures (\old(num2) >= 0 ? \old(num2) : -\old(num2)) % \result == 0;
      ensures \forall integer k; k > 0 && (\old(num1) >= 0 ? \old(num1) : -\old(num1)) % k == 0 && (\old(num2) >= 0 ? \old(num2) : -\old(num2)) % k == 0 ==> k <= \result;
    complete behaviors both_zero, one_zero, both_nonzero;
    disjoint behaviors both_zero, one_zero, both_nonzero;
*/
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
		  loop invariant 1 <= i;
		  loop invariant i <= num1 + 1;
		  loop invariant i <= num2 + 1;
		  loop invariant 1 <= result && result <= i;
		  loop invariant num1 % result == 0;
		  loop invariant num2 % result == 0;
		  loop invariant \forall integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ==> k <= result;
		  loop assigns i, result;
		  loop variant ( (num1 < num2) ? num1 : num2 ) - i + 1;
		*/
		for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
		return result;
}
