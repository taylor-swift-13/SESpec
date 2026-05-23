/*@
    requires diff >= 0;
    assigns \nothing;
*/
int difference(int diff);

 /*@
    requires diff >= 0;
    assigns \nothing;
    ensures \result == (\sum integer c; 1 <= c <= diff; c * c * c) - (\sum integer c; 1 <= c <= diff; c);
*/
int difference(int diff) {

		int result = 0;
		int max = 0;
		/*@
		    loop invariant 0 <= c <= diff + 1;
		    loop invariant result == (\sum integer k; 1 <= k < c; k * k * k);
		    loop assigns c, result;
		    loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		/*@
		    loop invariant 0 <= c <= diff + 1;
		    loop invariant max == (\sum integer k; 1 <= k < c; k);
		    loop assigns c, max;
		    loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}
