/*@
    requires size > 1;
    assigns \nothing;
    ensures \result >= 2;
*/
int averageEven(int size);

 /*@
    requires size > 1;
    assigns \nothing;
    ensures \result >= 2;
*/
int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= j <= size + 1;
		    loop invariant total >= 0;
		    loop invariant average >= 0;
		    loop invariant total == (j - 1) / 2;
		    loop assigns j, average, total;
		    loop variant size - j + 1;
		*/
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
}
