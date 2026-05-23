/*@
    requires num > 0;
    ensures \result >= 0;
    ensures \result == 0 ==> (\forall integer c; 2 <= c <= num / c ==> num % c != 0);
    ensures \result > 0 ==> (\exists integer c; 2 <= c <= num / c && num % c == 0);
*/
int countFac(int num);

int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= c <= num / c + 1;
		    loop invariant result >= 0;
		    loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || (num / k == k && result > 0));
		    loop assigns c, result;
		    loop variant num / c - c;
		*/
		for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
}
