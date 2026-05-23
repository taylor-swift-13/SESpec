/*@
    requires \valid(ints + (0..array-1));
    requires array > 0;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && ints[i] % 2 != 0 && \result == ints[i]);
    assigns \nothing;
*/
int getOddOccurrence(int * ints, int ints_len, int array);

int getOddOccurrence(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= array;
		    loop invariant start >= 0;
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && ints[i] % 2 != 0 && start % 2 != 0 && ret == ints[i]);
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
