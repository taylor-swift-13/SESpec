
/*@
  requires \valid_read(ints + (0..ints_len-1));
  requires ints_len >= 0;
  requires 1 <= array <= ints_len;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= array;
*/
int foo202(int * ints, int ints_len, int array) {

	int find = 0;
	int min = 0;
	int offset = 1;

	/*@
	  loop invariant 0 <= min <= array;
	  loop invariant 1 <= offset <= array;
	  loop invariant 0 <= find;
	  loop invariant find <= min;
	  loop invariant find <= offset;
	  loop invariant ints_len == \at(ints_len, Pre);
	  loop invariant array == \at(array, Pre);
	  loop invariant ints == \at(ints, Pre);
	  loop assigns min, offset, find;
	*/
	while (min < array && offset < array) {
		if (ints[min] == ints[offset]) {
			min++;
			offset++;
			find++;
		} else if (ints[min] > ints[offset]) {
			min++;
		} else {
			offset++;
		}
	}

	return find;
}
