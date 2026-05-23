int averageOdd(int size);

/*@
  requires size >= 1;
  requires size <= 92679;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
*/
int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@
		  loop invariant 1 <= c <= size + 1;
		  loop invariant total == c / 2;
		  loop invariant average == total * total;
		  loop invariant 0 <= total <= (size + 1) / 2;
		  loop invariant 0 <= average <= ((size + 1) / 2) * ((size + 1) / 2);
		  loop assigns average, total, c;
		  loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
		/*@ assert total > 0; */
		/*@ assert average == total * total; */
		return average / total;
}
