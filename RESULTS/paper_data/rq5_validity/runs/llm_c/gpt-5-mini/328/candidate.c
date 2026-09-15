int difference(int diff);

/*@
    requires diff >= 0;
    assigns \nothing;
    ensures \result == (\sum integer c; 1 <= c <= diff; c*c*c) - (\sum integer c; 1 <= c <= diff; c);
*/
int difference(int diff) {

		int result = 0;
		int max = 0;
		/*@
		    loop invariant 1 <= c <= diff + 1;
		    loop invariant result == (\sum integer j; 1 <= j < c; j*j*j);
		    loop assigns c, result;
		    loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		/*@
		    loop invariant 1 <= c <= diff + 1;
		    loop invariant max == (\sum integer j; 1 <= j < c; j);
		    loop assigns c, max;
		    loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}
