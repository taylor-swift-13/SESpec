/*@
    requires data_len > 0;
    requires array > 0;
    requires \valid_read(data + (0 .. array - 1));
    assigns \nothing;
    ensures 0 <= \result < array;
*/
int findPeak(int * data, int data_len, int array);

 /*@
    requires data_len > 0;
    requires array > 0;
    requires \valid_read(data + (0 .. array - 1));
    assigns \nothing;
    ensures 0 <= \result < array;
*/
int findPeak(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		/*@
		    loop invariant 0 <= found <= top < array;
		    loop invariant \valid_read(data + (0 .. array - 1));
		    loop assigns found, top;
		    loop variant top - found;
		*/
		while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
