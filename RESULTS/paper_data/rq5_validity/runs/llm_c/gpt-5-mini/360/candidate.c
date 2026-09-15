int averageOdd(int size);

/*@
    requires size >= 1 && size <= 92679;
    assigns \nothing;
    ensures \result == (size + 1) / 2;
*/
int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c && c <= size + 1;
		    loop invariant total == c/2;
		    loop invariant average == (c/2) * (c/2);
		    loop assigns c, average, total;
		    loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
