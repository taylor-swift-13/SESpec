/*@
    requires num > 0;
    ensures \result >= 2;
    ensures num % \result == 0 || num == 1;
    assigns \nothing;
*/
int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		    loop invariant result >= 0;
		    loop invariant 2 <= c <= num + 1;
		    loop invariant \forall integer x; 2 <= x < c ==> (num % x != 0 || \exists integer y; y > 0 && num == x * y);
		    loop assigns c, num, result;
		    loop variant num + 1 - c;
		*/
		for (int c = 2; c <= num; c++) {
			/*@
			    loop invariant num >= 0;
			    loop invariant result >= 2;
			    loop invariant num % c == 0 ==> (\exists integer y; y >= 0 && num == c * y);
			    loop assigns num, result;
			    loop variant num;
			*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
