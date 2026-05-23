
/*@
  requires 0 <= start <= stop < args_len;
  requires args_len > 0;
*/
int foo251(int * args, int args_len, int start, int stop) {

	int found = start;
	int total = stop;
	int mid;

	/*@
	  loop invariant start <= found <= total + 1;
	  loop invariant start <= total + 1;
	  loop invariant 0 <= found;
	  loop invariant total < args_len;
	  loop invariant args_len > 0;
	  loop assigns found, total, mid;
	*/
	while (found <= total) {
		mid = (found + total) / 2;
		int i = args[mid];

		if (i == mid) {
			found = mid + 1;
		} else if (i < mid) {
			found = mid + 1;
		} else {
			total = mid - 1;
		}
	}

	return found;
}
