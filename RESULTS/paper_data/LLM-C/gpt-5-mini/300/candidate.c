int findPeak(int * array, int array_len, int Array);

/*@
    requires Array > 0;
    requires array_len >= Array;
    requires \valid_read(array + (0 .. Array-1));
    assigns \nothing;
    ensures 0 <= \result < Array;
    ensures (\result == Array-1) || array[\result] >= array[\result+1];
*/
int findPeak(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		/*@
		    loop invariant 0 <= found <= top < Array;
		    loop invariant \exists integer k; found <= k <= top && (k == Array-1 || array[k] >= array[k+1]);
		    loop assigns found, top, i;
		    loop variant top - found;
		*/
		while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
