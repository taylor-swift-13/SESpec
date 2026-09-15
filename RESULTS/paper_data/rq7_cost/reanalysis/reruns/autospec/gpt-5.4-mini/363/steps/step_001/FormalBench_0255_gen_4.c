int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant 0 <= total <= size / 2;
		loop invariant average >= 0;
		loop invariant total == \numof{integer k; 1 <= k < c && k % 2 == 0};
		loop invariant average == \sum(integer k; 1 <= k < c && k % 2 == 0; k);
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
