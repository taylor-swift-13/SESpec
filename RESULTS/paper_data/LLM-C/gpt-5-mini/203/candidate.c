int findMinSwaps(int * array, int array_len, int Array);

/*@
    requires 0 <= Array <= array_len;
    requires \valid(array + (0 .. Array-1));
    assigns \nothing;
    ensures 0 <= \result <= Array;
*/
int findMinSwaps(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		    loop invariant 0 <= offset <= max <= Array;
		    loop invariant 0 <= find <= offset;
		    loop assigns offset, max, find;
		    loop variant 2*Array - offset - max;
		*/
		while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
}
