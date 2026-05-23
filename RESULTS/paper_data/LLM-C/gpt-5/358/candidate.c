int averageOdd(int size);

/*@ 
  requires size >= 1;
  requires ((size + 1) / 2) * ((size + 1) / 2) <= \max_int;
  assigns \nothing;
  ensures \result == (size + 1) / 2;
  ensures \result >= 1;
*/
int averageOdd(int size) {

		int average = 0;
		int total = 0;
		/*@ 
		  loop invariant 1 <= index <= size + 1;
		  loop invariant 0 <= total;
		  loop invariant total == index / 2;
		  loop invariant average == total * total;
		  loop invariant 0 <= average <= \max_int;
		  loop assigns average, total, index;
		  loop variant size - index + 1;
		*/
		for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		/*@ assert total > 0; */
		return average / total;
}
