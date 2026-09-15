/*@
    requires size >= 2;
    ensures \result == \sum(1, size, \lambda integer i; (i % 2 == 0 ? i : 0)) / (\sum(1, size, \lambda integer i; (i % 2 == 0 ? 1 : 0)));
    assigns \nothing;
*/
int averageEven(int size) {

		int average = 0;
		int total = 0;

		/*@
		loop invariant 1 <= j <= size + 1;
		loop invariant average == \sum(1, j-1, \lambda integer i; (i % 2 == 0 ? i : 0));
		loop invariant total == \sum(1, j-1, \lambda integer i; (i % 2 == 0 ? 1 : 0));
		loop assigns j, average, total;
		loop variant size - j;
		*/
		for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
}
