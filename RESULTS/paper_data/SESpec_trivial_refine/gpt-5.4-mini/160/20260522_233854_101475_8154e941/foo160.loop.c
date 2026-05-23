
/*@
  requires \valid(positions + (0 .. positions_len - 1));
  requires 0 <= array <= positions_len;
*/
int foo160(int * positions, int positions_len, int array) {

	int ret = 0;

	/*@
	  loop invariant 0 <= ret <= array;
	  loop assigns ret, positions[..];
	*/
	while (ret < array) {
		if (positions[ret] <= 0 || positions[ret] > array
				|| positions[ret] == ret + 1) {
			ret++;
		} else {
			int index = positions[ret];
			positions[ret] = positions[index - 1];
			positions[index - 1] = index;
		}
	}

	/*@
	  loop invariant 0 <= ret <= array;
	  loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
	  loop assigns ret;
	*/
	for (ret = 0; ret < array; ret++) {
		if (positions[ret] != ret + 1) {
			return ret + 1;
		}
	}

	return array + 1;
}
