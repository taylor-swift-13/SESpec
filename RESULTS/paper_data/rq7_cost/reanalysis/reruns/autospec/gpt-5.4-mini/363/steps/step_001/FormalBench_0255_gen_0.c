int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant 0 <= total <= size;
		loop invariant 0 <= average;
		loop invariant total * 2 <= c - 1 + (c - 1) % 2;
		loop assigns c;
		loop assigns average;
		loop assigns total;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
