/*@ 
    requires \valid_read(array + (0 .. array_len - 1));
    requires array_len >= 0;
    requires Array >= 0;
    requires Array <= array_len;
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= Array;
*/
int findMinSwaps(int * array, int array_len, int Array);

 /*@ 
    requires \valid_read(array + (0 .. array_len - 1));
    requires array_len >= 0;
    requires Array >= 0;
    requires Array <= array_len;
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= Array;
*/
int findMinSwaps(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		    loop invariant 0 <= offset <= Array;
		    loop invariant 1 <= max <= Array;
		    loop invariant 0 <= find <= Array;
		    loop invariant offset <= max;
		    loop assigns find, offset, max;
		    loop variant Array - max;
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
