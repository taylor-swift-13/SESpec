int averageEven(int size);

/*@ 
  requires size >= 2;
  requires size <= 92680;
  assigns \nothing;
  ensures \result == (size/2) + 1;
*/
int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		  loop invariant 1 <= j <= size + 1;
		  loop invariant total == (j-1)/2;
		  loop invariant average == total * (total + 1);
		  loop invariant total >= 0;
		  loop invariant average >= 0;
		  loop assigns j, average, total;
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
