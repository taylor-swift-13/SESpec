/*@
    requires number > 0;
    ensures \result >= 0;
    ensures \result == 0 ==> \forall integer c; 2 <= c <= number / c ==> number % c != 0;
    ensures \result > 0 ==> \exists integer c; 2 <= c <= number / c && number % c == 0;
    assigns \nothing;
*/
int countFac(int number);

int countFac(int number) {

		int result = 0;
		if (number == 1)
			return 1;

		/*@
		loop invariant 2 <= c <= number / c + 1;
		loop invariant result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> (number % k == 0 ==> result > 0);
		loop assigns c, result;
		loop variant number / c - c;
		*/
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}
