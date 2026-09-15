
int foo318(int num) {

	int result = 0;
	if (num == 1)
		return 1;
	
	/*@
	  loop invariant 0 <= result;
	    // result is a non-negative counter (established at entry and preserved by increments)
	  loop invariant result <= c - 2;
	    // at any point result is at most the number of candidates already checked (c-2)
	  loop invariant (\forall integer k; 2 <= k < c ==> ( (num % k == 0) ==> (k <= num / k) ));
	    // for every already-checked divisor k, when k divides num it is the smaller partner
	  loop invariant (\forall integer k; 2 <= k < c ==> ( (num % k == 0) ==> (\exists integer pair; pair == num / k && pair * k == num) ));
	    // for every already-checked divisor k that divides num, the paired divisor exists (= num/k)
	  loop assigns c, result;
	*/
	for (int c = 2; c <= num / c; c++) {
		if (num % c == 0) {
			result++;
			if (num / c == c) {
				break;
			}
		}
	}
		
	return result;
}
