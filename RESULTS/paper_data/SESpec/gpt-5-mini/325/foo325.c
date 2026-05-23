
/*@
  requires \true;
  assigns \nothing;
  ensures 0 <= \result && \result <= 9;
*/
int foo325(int num) {

	int first = 1;
	
	/*@
	  loop invariant 2 <= j;
	  loop invariant j <= \at(num,Pre) + 1 || \at(num,Pre) < 2;
	  loop invariant 1 <= first;
	  loop invariant num == \at(num,Pre);
	  loop invariant (j == 2) ==> (first == 1);
	  loop assigns j, first;
	*/
	for (int j = 2; j <= num; j++) {
		first *= j;
	}
		
	int result = 0;
	
	/*@
	  loop invariant 0 <= result <= 9;                                       // result stores a digit
	  loop invariant 0 <= first;                                              // first is non-negative
	  loop assigns result, first;
	*/
	while (first > 0) {
		result = first % 10;
		first /= 10;
	}
	return result;
}
