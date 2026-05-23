
/*@
  requires ints != \null;
  requires array >= 1;
  requires \valid_read(ints + (0 .. array - 1));
  assigns \nothing;
  ensures 0 <= \result <= array - 1;
*/
int foo204(int * ints, int ints_len, int array) {

	int find = 0;
	int offset = 0;
	int max = 1;

	/*@
	  loop invariant 0 <= offset <= max <= array;
	  loop invariant 0 <= find <= max - 1;
	  loop assigns offset, max, find;
	  loop variant array - max;
	*/
	while (offset < array && max < array) {
		if (ints[offset] == ints[max]) {
			offset++;
			max++;
			find++;
		} else if (ints[offset] > ints[max]) {
			offset++;
		} else {
			max++;
		}
	}

	return find;
}
