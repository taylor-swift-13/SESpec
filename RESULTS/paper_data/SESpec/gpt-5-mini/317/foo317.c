
/*@
  requires num >= 0;
  assigns \nothing;
*/
int foo317(int num) {

	int result = 0;
	if (num == 1)
		return 1;

	/*@
	  loop invariant 2 <= size;
	  loop invariant 0 <= result;
	  loop invariant result <= size - 1;
	  loop invariant result <= num;
	  loop assigns size, result;
	*/
	for (int size = 2; size <= num / size; size++) {
		if (num % size == 0) {
			result++;
			if (num / size == size) {
				break;
			}
		}
	}

	return result;
}
