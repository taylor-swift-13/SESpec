int findMinSwaps(int * ints, int ints_len, int array);

/*@
    requires array >= 0;
    requires ints_len >= array;
    requires \valid_read(ints + (0 .. array-1));
    assigns \nothing;
    ensures 0 <= \result <= array;
*/
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		/*@
		    loop invariant 0 <= min && min <= array;
		    loop invariant 0 <= offset && offset <= array;
		    loop invariant 0 <= find && find <= array;
		    loop invariant find <= min;
		    loop invariant find <= offset;
		    loop assigns min, offset, find;
		    loop variant 2*array - (min + offset);
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
