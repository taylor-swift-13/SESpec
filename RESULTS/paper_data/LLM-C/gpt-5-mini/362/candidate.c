int averageEven(int size);

/*@
    requires size >= 2;
    assigns \nothing;
    ensures \result == size/2 + 1;
*/
int averageEven(int size) {

		int result = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant total == (c - 1) / 2;
		    loop invariant result == ((c - 1) / 2) * (((c - 1) / 2) + 1);
		    loop assigns c, result, total;
		    loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}
