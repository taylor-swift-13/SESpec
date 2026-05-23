int findMinSwaps(int * ints, int ints_len, int array);

/*@
    requires array >= 0;
    requires ints_len >= array;
    requires array == 0 || \valid_read(ints + (0 .. array-1));
    assigns \nothing;
    ensures 0 <= \result <= array/2;
    ensures array <= 1 ==> \result == 0;
*/
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		    loop invariant 0 <= offset <= max && max <= array;
		    loop invariant 0 <= find <= array/2;
		    loop invariant offset + max <= 2 * array;
		    loop assigns offset, max, find;
		    loop variant 2 * array - (offset + max);
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
