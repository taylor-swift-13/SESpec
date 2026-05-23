/*@
    requires diff >= 0;
    ensures \result == (\sum integer c; 1 <= c <= diff; c * c * c) - (\sum integer c; 1 <= c <= diff; c);
    assigns \nothing;
*/
int difference(int diff);

int difference(int diff) {

		int result = 0;
		int max = 0;

		/*@
		loop invariant 1 <= c <= diff + 1;
		loop invariant result == (\sum integer i; 1 <= i < c; i * i * i);
		loop assigns c, result;
		loop variant diff - c;
		*/
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}

		/*@
		loop invariant 1 <= c <= diff + 1;
		loop invariant max == (\sum integer i; 1 <= i < c; i);
		loop assigns c, max;
		loop variant diff - c;
		*/
		for (int c = 1; c <= diff; c++) {
			max += c;
		}

		return result - max;
}
