/*@
    requires ints_len >= 0;
    requires array >= 0;
    requires \valid_read(ints + (0 .. ints_len - 1));
    requires array <= ints_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int findMinSwaps(int * ints, int ints_len, int array);

 /*@
    requires ints_len >= 0;
    requires array >= 0;
    requires \valid_read(ints + (0 .. ints_len - 1));
    requires array <= ints_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		/*@
            loop invariant 0 <= min <= array;
            loop invariant 1 <= offset <= array + 1;
            loop invariant 0 <= find <= min;
            loop assigns find, min, offset;
            loop variant (array - min) + (array - offset);
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
