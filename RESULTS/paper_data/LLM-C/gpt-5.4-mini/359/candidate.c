/*@
    requires size >= 1;
    assigns \nothing;
    ensures \result >= 1;
*/
int averageOdd(int size);

 /*@
    requires size >= 1;
    assigns \nothing;
    ensures \result >= 1;
*/
int averageOdd(int size) {

		int ret = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant total >= 0;
		    loop invariant ret >= 0;
		    loop invariant total == 0 || ret / total >= 1;
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
