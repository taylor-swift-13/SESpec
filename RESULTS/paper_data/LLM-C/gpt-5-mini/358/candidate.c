int averageOdd(int size);

/*@
    requires size >= 1;
    assigns \nothing;
    ensures (\sum integer i; 1 <= i <= size && i % 2 != 0; 1) > 0;
    ensures \result == (\sum integer i; 1 <= i <= size && i % 2 != 0; i) /
                       (\sum integer i; 1 <= i <= size && i % 2 != 0; 1);
*/
int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= index <= size + 1;
		    loop invariant average == (\sum integer j; 1 <= j < index && j % 2 != 0; j);
		    loop invariant total == (\sum integer j; 1 <= j < index && j % 2 != 0; 1);
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
