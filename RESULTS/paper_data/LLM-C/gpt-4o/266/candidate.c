/*@
    requires \valid(array + (0..Array-1));
    requires Array > 0;
    ensures \result == 0 || (\exists integer i; 0 <= i < Array && array[i] == \result && array[i] % 2 != 0);
    assigns \nothing;
*/
int getOddOccurrence(int * array, int array_len, int Array);

int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= Array;
		    loop invariant start >= 0;
		    loop invariant \forall integer i; 0 <= i < index ==> (array[i] % 2 != 0 ==> start >= 1);
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && array[i] == ret && array[i] % 2 != 0);
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
