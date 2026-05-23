
/*@
  requires \valid(positions + (0 .. positions_len - 1));
  requires 0 <= positions_len;
  requires 0 <= array <= positions_len;
*/

int foo161(int * positions, int positions_len, int array) {

	int ret = 0;
	
	/*@
	  loop invariant 0 <= ret <= array;
	  loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
	  loop assigns ret, positions[..];
	*/
	while (ret < array) {
		if (positions[ret] <= 0 || positions[ret] > array
				|| positions[ret] == ret + 1) {
			ret++;
		} else {
			int j = positions[ret];
			positions[ret] = positions[j - 1];
			positions[j - 1] = j;
		}
	}
	
	/*@
	  loop invariant 0 <= ret <= array;
	  loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
	  loop assigns ret;
	*/
	for (ret = 0; ret < array; ret++) {
		if (positions[ret] != ret + 1) {
			return ret + 1;
		}
	}
	
	return array + 1;
}
