/*@
    requires size >= 1;
    ensures \result >= 1;
    assigns \nothing;
*/
int averageOdd(int size);

int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= index <= size + 1;
		    loop invariant average >= 0;
		    loop invariant total >= 0;
		    loop assigns index, average, total;
		    loop variant size - index + 1;
		*/
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
}
