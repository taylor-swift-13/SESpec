int averageEven(int size);

/*@
    requires size >= 2;
    assigns \nothing;
    ensures \result == (\sum integer k; 1 <= k <= size && k % 2 == 0; k)
                     /
                     (\sum integer k; 1 <= k <= size && k % 2 == 0; 1);
*/
int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= j <= size + 1;
		    loop invariant total == (\sum integer k; 1 <= k < j && k % 2 == 0; 1);
		    loop invariant average == (\sum integer k; 1 <= k < j && k % 2 == 0; k);
		    loop assigns j, total, average;
		    loop variant size - j + 1;
		*/
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
}
