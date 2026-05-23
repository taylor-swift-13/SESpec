int averageEven(int size);

/*@ 
  requires 2 <= size && size <= 92680;
  assigns \nothing;
  ensures \result == size/2 + 1;
*/
int averageEven(int size) {

		int average = 0;
		int total = 0;
		for (int c = 1; c <= size; c++)
		/*@
			loop invariant 1 <= c && c <= size + 1;
			loop invariant 0 <= total && total == (c-1)/2;
			loop invariant average >= 0;
			loop invariant average == ((c-1)/2) * (((c-1)/2) + 1);
			loop assigns average, total, c;
			loop variant size - c + 1;
		*/
		{
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		/*@ assert total > 0; */
		/*@ assert average == total * (total + 1); */
		return average / total;
}
