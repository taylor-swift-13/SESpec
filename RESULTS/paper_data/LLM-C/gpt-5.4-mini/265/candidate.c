/*@
    requires \valid_read(ints + (0 .. array - 1));
    requires array >= 0;
    requires ints_len >= 0;
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && \result == ints[i]);
*/
int getOddOccurrence(int * ints, int ints_len, int array);

 /*@
    requires \valid_read(ints + (0 .. array - 1));
    requires array >= 0;
    requires ints_len >= 0;
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && \result == ints[i]);
*/
int getOddOccurrence(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= array;
		    loop invariant start >= 0;
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && ret == ints[i]);
		    loop assigns index, start, ret;
		    loop variant array - index;
		*/
		for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
		return ret;
}
