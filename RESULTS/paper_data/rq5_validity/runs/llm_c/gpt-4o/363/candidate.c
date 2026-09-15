/*@
    requires size >= 0;
    ensures \result >= 0;
    ensures \result == 0 ==> size < 2 || (\forall integer i; 1 <= i <= size ==> i % 2 != 0);
    ensures \result > 0 ==> (\exists integer i; 1 <= i <= size && i % 2 == 0);
    assigns \nothing;
*/
int averageEven(int size);

int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c <= size + 1;
		    loop invariant average >= 0;
		    loop invariant total >= 0;
		    loop invariant \forall integer i; 1 <= i < c ==> (i % 2 == 0 ==> average >= i * total);
		    loop assigns c, average, total;
		    loop variant size - c;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		//@ assert total > 0 ==> average % total == 0;
		return average / total;
}
