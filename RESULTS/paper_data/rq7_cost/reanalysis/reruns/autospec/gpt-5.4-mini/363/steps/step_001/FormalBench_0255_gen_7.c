int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant total >= 0;
		loop invariant average >= 0;
		loop invariant total == \numof(1 <= i < c && i % 2 == 0);
		loop invariant average == \sum(1 <= i < c && i % 2 == 0, i);
		loop assigns c;
		loop assigns total;
		loop assigns average;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
