
/*@
  logic integer count_divisors_upto(integer n, integer up) =
    up <= 2 ? 0 :
    ( (n % (up - 1) == 0) ? 1 + count_divisors_upto(n, up - 1) : count_divisors_upto(n, up - 1) );
*/

int foo317(int num) {

	int result = 0;
	if (num == 1)
		return 1;

	/*@
	  loop invariant 2 <= size;
	  loop invariant 0 <= result;
	  loop invariant result == count_divisors_upto(num, size);
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
