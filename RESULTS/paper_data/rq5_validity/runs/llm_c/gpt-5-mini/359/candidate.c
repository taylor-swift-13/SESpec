int averageOdd(int size);

/*@
    requires size >= 1;
    assigns \nothing;
    ensures \result == (size + 1) / 2;
*/
int averageOdd(int size) {

		int ret = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c && c <= size + 1;
		    loop invariant ret == (\sum integer j; 1 <= j < c && j % 2 != 0; j);
		    loop invariant total == (\sum integer j; 1 <= j < c && j % 2 != 0; 1);
		    loop assigns c, ret, total;
		    loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
}
