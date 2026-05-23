/*@
    requires size > 0;
    ensures \result == (\sum integer i; 1 <= i <= size && i % 2 != 0; i) / (\num_of integer i; 1 <= i <= size && i % 2 != 0);
*/
int averageOdd(int size);

int averageOdd(int size) {

		int ret = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant ret == (\sum integer i; 1 <= i < c && i % 2 != 0; i);
		    loop invariant total == (\num_of integer i; 1 <= i < c && i % 2 != 0);
		    loop assigns c, ret, total;
		    loop variant size - c;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
}
