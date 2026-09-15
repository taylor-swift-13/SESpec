int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant total >= 0;
		loop invariant average >= 0;
		loop invariant total <= c - 1;
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 != 0 || total >= 1);
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
