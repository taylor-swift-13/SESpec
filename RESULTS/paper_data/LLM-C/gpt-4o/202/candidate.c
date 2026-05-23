/*@
    requires \valid(ints + (0..ints_len-1));
    requires ints_len >= 0;
    requires array >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int findMinSwaps(int * ints, int ints_len, int array);

int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		/*@
		    loop invariant 0 <= min <= array;
		    loop invariant 1 <= offset <= array;
		    loop invariant find >= 0;
		    loop assigns min, offset, find;
		    loop variant array - min;
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
