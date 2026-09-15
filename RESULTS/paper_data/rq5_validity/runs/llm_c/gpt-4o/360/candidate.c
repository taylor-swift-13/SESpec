/*@
    requires size > 0;
    ensures \result >= 0;
    ensures \result == (\sum integer i; 1 <= i <= size && i % 2 != 0; i) / (\count integer i; 1 <= i <= size && i % 2 != 0);
*/
int averageOdd(int size);

int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant average == (\sum integer i; 1 <= i < c && i % 2 != 0; i);
		    loop invariant total == (\count integer i; 1 <= i < c && i % 2 != 0);
		    loop assigns c, average, total;
		    loop variant size - c;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
