
/*@
  requires value == \at(value,Pre);
*/
int foo399(int value) {

	int result = 0;
	
	/*@
	  loop invariant 0 <= result;
	  loop invariant (\at(value,Pre) > 0) ==> (value >= 0);
	  loop invariant value <= \at(value,Pre);
	  loop invariant (\at(value,Pre) > 0) ==> (result >= 0);
	  loop invariant (\at(value,Pre) > 0) ==> (value == \at(value,Pre) || value < \at(value,Pre) || result == 0);
	  loop assigns value, result;
	*/
	while (value > 0) {
		value /= 10;
		result++;
	}
		
	return result;
}
