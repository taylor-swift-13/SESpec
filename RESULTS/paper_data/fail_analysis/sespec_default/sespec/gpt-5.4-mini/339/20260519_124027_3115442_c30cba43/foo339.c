
/*@
  assigns \nothing;
  
*/
int foo339(int num, int z) {

	if (z < 0) {
		z = -z;
	}
	int result = 0;

	/*@
	  loop invariant 1 <= index <= z + 1;
	  loop invariant 0 <= result <= index - 1;
	  loop invariant result == result;
	  loop invariant z >= 0;
	  loop invariant num == \at(num,Pre);
	  loop invariant z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre));
	  loop assigns index, result;
	*/
	for (int index = 1; index <= z; index++) {
		if (num % index == 0) {
			result = result + 1;
		}
	}

	return result;
}
