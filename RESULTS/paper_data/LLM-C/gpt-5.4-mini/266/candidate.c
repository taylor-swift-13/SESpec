/*@ 
    requires array_len >= 0;
    requires Array >= 0;
    requires \valid_read(array + (0 .. Array-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < Array && array[i] == \result);
*/
int getOddOccurrence(int * array, int array_len, int Array);

 /*@ 
    requires array_len >= 0;
    requires Array >= 0;
    requires \valid_read(array + (0 .. Array-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < Array && array[i] == \result);
*/
int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@ 
		    loop invariant 0 <= index <= Array;
		    loop invariant start >= 0;
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && array[i] == ret);
		    loop assigns index, start, ret;
		    loop variant Array - index;
		*/
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}
