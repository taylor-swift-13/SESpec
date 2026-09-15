
/*@ 
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 1;
  assigns \nothing;
  ensures 0 <= \result && \result <= 9;
*/
int foo326(int num) {

	int first = 1;
	
	/*@
	  loop invariant 2 <= c <= \at(num,Pre) + 1;
	  loop invariant 0 <= first;
	  loop invariant first == factorial(c - 1);
	  loop invariant num == \at(num,Pre);
	  loop assigns c, first;
	*/
	for (int c = 2; c <= num; c++) {
		first *= c;
	}
		
	int result = 0;
	
	/*@
	  loop invariant 0 <= result && result <= 9;
	  loop invariant 0 <= first;
	  loop assigns result, first;
	*/
	while (first > 0) {
		result = first % 10;
		first /= 10;
	}
	return result;
}
