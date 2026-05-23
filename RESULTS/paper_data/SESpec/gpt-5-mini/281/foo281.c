
/*@
  requires \true;
  assigns \nothing;
  ensures \result != \null;
*/
const char * foo281(int num) {

	int result = 0;
		
	/*@
	  loop invariant 1 <= index;
	  loop invariant 0 <= result;
	  loop invariant result <= index - 1;
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
