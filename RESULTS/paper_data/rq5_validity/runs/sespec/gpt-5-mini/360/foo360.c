
/*@ 
  requires size >= 1;
  assigns \nothing;
  ensures \result == \result;
*/
int foo360(int size) {

	int average = 0;
	int total = 0;
	
    /*@
      loop invariant 1 <= c && c <= size + 1;
      loop invariant 0 <= average;
      loop invariant size == \at(size,Pre);

      loop invariant average >= total;
      loop invariant average <= total * \at(size,Pre);
      loop invariant total >= 0;
      loop invariant total > 0 ==> (\exists integer k; 1 <= k && k < c && k % 2 != 0);

      loop invariant (c <= \at(size,Pre)) ==> (average >= 0);

      loop assigns c, average, total;
    */
	for (int c = 1; c <= size; c++) {
		if (c % 2 != 0) {
			average += c;
			total++;
		}
	}
		
	return average / total;
}
