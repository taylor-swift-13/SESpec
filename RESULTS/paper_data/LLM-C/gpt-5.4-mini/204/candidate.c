/*@
    requires \valid_read(ints + (0 .. ints_len - 1));
    requires 0 <= array <= ints_len;
    assigns \nothing;
    ensures 0 <= \result;
*/
int findMinSwaps(int * ints, int ints_len, int array);

 /*@
    requires \valid_read(ints + (0 .. ints_len - 1));
    requires 0 <= array <= ints_len;
    assigns \nothing;
    ensures 0 <= \result;
*/
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		    loop invariant 0 <= offset <= array;
		    loop invariant 1 <= max <= array;
		    loop invariant 0 <= find;
		    loop invariant offset < array && max < array ==> find <= offset && find <= max;
		    loop assigns find, offset, max;
		    loop variant (array - offset) + (array - max);
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
