int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant total >= 0;
		loop invariant average >= 0;
		loop invariant 2 * total <= c;
		loop invariant average >= total;
		loop invariant total <= c;
		loop invariant average >= 2 * total - 1;
		loop invariant total == c/2;
		loop invariant total == \numof{integer k; 1 <= k < c && k % 2 == 0};
		loop invariant total == \numof(integer k; 1 <= k < c && k % 2 == 0);
		loop invariant total == \numof(1, c-1, \lambda integer k; k % 2 == 0);
		loop invariant total == \numof(1 <= i < c && i % 2 == 0);
		loop invariant total <= size;
		loop invariant total <= size / 2;
		loop invariant total <= c - 1;
		loop invariant total <= average;
		loop invariant total * 2 <= c - 1 + (c - 1) % 2;
		loop invariant c <= size + 1;
		loop invariant average == \sum(integer k; 1 <= k < c && k % 2 == 0; k);
		loop invariant average == \sum(integer k; 1 <= k < c && k % 2 == 0, k);
		loop invariant average == \sum(1, c-1, \lambda integer k; k % 2 == 0 ? k : 0);
		loop invariant average == \sum(1 <= i < c && i % 2 == 0, i);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 == 0 ==> average >= k);
		loop invariant \forall integer k; 1 <= k < c ==> (k % 2 != 0 || total >= 1);
		loop invariant \forall integer k; 1 <= k < c && k % 2 == 0 ==> average >= k;
		loop invariant 1 <= c;
		loop invariant 0 <= total;
		loop invariant 0 <= average;
		loop assigns total;
		loop assigns c;
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
