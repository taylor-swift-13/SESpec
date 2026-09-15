int averageEven(int size);

/* 2. FUNC CONTRACT */
int averageEven(int size) {

		int average = 0;
		int total = 0;
		/* 1. LOOP INVARIANT */
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
