int averageEven(int size);

 /*@
     requires size >= 2;
     assigns \nothing;
     ensures \result == 
         (\sum integer j; 1 <= j && j <= size && j % 2 == 0; j)
         / (\sum integer j; 1 <= j && j <= size && j % 2 == 0; 1);
 */
int averageEven(int size) {

		int average = 0;
		int total = 0;
		/*@
		    loop invariant 1 <= c && c <= size + 1;
		    loop invariant average == (\sum integer j; 1 <= j && j < c && j % 2 == 0; j);
		    loop invariant total == (\sum integer j; 1 <= j && j < c && j % 2 == 0; 1);
		    loop assigns c, average, total;
		    loop variant size - c + 1;
		*/
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}
