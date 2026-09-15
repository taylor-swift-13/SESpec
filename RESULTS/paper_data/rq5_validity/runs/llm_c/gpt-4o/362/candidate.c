/*@ 
    requires size >= 0;
    ensures \result == 0 ==> size < 2;
    ensures size >= 2 ==> \result == (\sum integer i; 1 <= i <= size && i % 2 == 0; i) / (\numof integer i; 1 <= i <= size && i % 2 == 0);
    assigns \nothing;
*/
int averageEven(int size);

int averageEven(int size) {

		int result = 0;
		int total = 0;
		/*@
		loop invariant 1 <= c <= size + 1;
		loop invariant result == (\sum integer i; 1 <= i < c && i % 2 == 0; i);
		loop invariant total == (\numof integer i; 1 <= i < c && i % 2 == 0);
		loop assigns c, result, total;
		loop variant size - c;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		/*@ assert total > 0 || size < 2; */
		return result / total;
}
