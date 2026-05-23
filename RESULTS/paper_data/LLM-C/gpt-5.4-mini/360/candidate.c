/*@ 
    requires size >= 1;
    ensures \result >= 1;
    assigns \nothing;
*/
int averageOdd(int size);

 /*@ 
    requires size >= 1;
    ensures \result >= 1;
    assigns \nothing;
*/
int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant total >= 0;
		    loop invariant average >= 0;
		    loop invariant total == (c - 1) / 2;
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
