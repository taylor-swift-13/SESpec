int foo250(int size);

int foo250(int size) {

		int average = 0;
		int total = 0;
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
}
