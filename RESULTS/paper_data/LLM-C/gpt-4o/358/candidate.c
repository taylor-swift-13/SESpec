/*@
    requires size >= 1;
    ensures \result == (\sum integer i; 1 <= i <= size && i % 2 != 0; i) / (\numof integer i; 1 <= i <= size && i % 2 != 0);
    assigns \nothing;
*/
int averageOdd(int size);

int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= index <= size + 1;
		loop invariant average == (\sum integer i; 1 <= i < index && i % 2 != 0; i);
		loop invariant total == (\numof integer i; 1 <= i < index && i % 2 != 0);
		loop assigns index, average, total;
		loop variant size - index;
		*/
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		//@ assert total > 0; // Since size >= 1, there is at least one odd number.
		return average / total;
}
