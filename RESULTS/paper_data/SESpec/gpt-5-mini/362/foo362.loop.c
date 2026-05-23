
/*@ 
  logic integer sum_even_upto(integer c) =
    c <= 1 ? 0 :
    ( (c - 1) % 2 == 0 ? (c - 1) + sum_even_upto(c - 1) : sum_even_upto(c - 1) );
*/

/*@ 
  logic integer count_even_upto(integer c) =
    c <= 1 ? 0 :
    ( (c - 1) % 2 == 0 ? 1 + count_even_upto(c - 1) : count_even_upto(c - 1) );
*/

int foo362(int size) {

	int result = 0;
	int total = 0;
	
	/*@
	  loop invariant 1 <= c;
	  loop invariant ( \at(size,Pre) >= 1 ) ==> ( c <= \at(size,Pre) + 1 );
	  loop invariant 0 <= total;
	  loop invariant 0 <= result;
	  loop invariant result == sum_even_upto(c);
	  loop invariant total == count_even_upto(c);
	  loop invariant size == \at(size,Pre);
	  loop assigns c, result, total;
	*/
	for (int c = 1; c <= size; c++) {
		if (c % 2 == 0) {
			result += c;
			total++;
		}
	}
		
	return result / total;
}
