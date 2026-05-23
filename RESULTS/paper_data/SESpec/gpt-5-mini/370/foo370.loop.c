
int foo370(int value, int k, int z) {

	int result = 0;
	
	/*@
	  loop invariant (result == 0) || (result % k == z);
	  loop invariant \forall integer x; 1 <= x < c ==> ( (x % k == z) ==> (result >= x) );
	  loop invariant (\exists integer x; 1 <= x < c && (x % k == z)) ==> (result != 0);
	  loop invariant z == \at(z,Pre);
	  loop invariant k == \at(k,Pre);
	  loop invariant value == \at(value,Pre);
	  loop assigns c, result;
	*/
	for (int c = 1; c <= value; c++) {
		if ((c % k) == z) {
			result = c;
		}
	}
		
	return result;
}
