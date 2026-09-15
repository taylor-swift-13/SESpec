/*@
    requires array_len > 0;
    requires \valid_read(array + (0 .. array_len - 1));
    requires Array == array_len;
    assigns \nothing;
    ensures 0 <= \result < array_len;
*/
int findPeak(int * array, int array_len, int Array);

 /*@
    requires array_len > 0;
    requires Array == array_len;
    requires \valid_read(array + (0 .. array_len - 1));
    assigns \nothing;
    ensures 0 <= \result < array_len;
*/
int findPeak(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		/*@
		    loop invariant 0 <= found <= top < Array;
		    loop invariant Array == array_len;
		    loop assigns found, top;
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
