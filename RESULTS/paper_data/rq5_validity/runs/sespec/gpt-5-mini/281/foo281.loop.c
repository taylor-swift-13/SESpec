
/*@
  logic integer count_divs{L}(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_divs(n, lo, hi - 1) + (n % (hi - 1) == 0 ? 1 : 0);
*/
const char * foo281(int num) {

	int result = 0;
		
	/*@
	  loop invariant index >= 1 && (index == 1 || index <= num + 1);
	  loop invariant 0 <= result <= index - 1;
	  loop invariant result == count_divs(num, 1, index);
	  loop invariant \forall integer i1, i2; 1 <= i1 <= i2 < index ==>
	                     count_divs(num, 1, i1) <= count_divs(num, 1, i2);
	  loop invariant (result > 0) ==> (\exists integer k; 1 <= k < index && num % k == 0);
	  loop invariant (index == num + 1) ==> (result == count_divs(num, 1, num + 1));
	  loop assigns index, result;
	*/
	for (int index = 1; index <= num; index++) {
		if (num % index == 0) {
			result++;
		}
	}
            
	if (result % 2 == 0) {
		return "Even";
	} else {
		return "Odd";
	}
}
