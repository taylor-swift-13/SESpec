int findMinSwaps(int * ints, int ints_len, int array);

 /*@ 
   requires ints != \null;
   requires ints_len >= 0;
   requires 0 <= array <= ints_len;
   requires \valid_read(ints + (0..array-1));
   assigns \nothing;
   ensures 0 <= \result;
   ensures array == 0 ==> \result == 0;
   ensures array <= 1 ==> \result == 0;
   ensures array >= 1 ==> \result <= array - 1;
   ensures (\forall integer i; 0 <= i < array - 1 ==> ints[i] < ints[i+1]) ==> \result == 0;
 */
int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		/*@
		  loop invariant 0 <= min <= array;
		  loop invariant 0 <= offset;
		  loop invariant offset <= array + 1;
		  loop invariant 0 <= find;
		  loop invariant find <= min;
		  loop invariant find <= offset;
		  loop assigns min, offset, find;
		  loop variant 2*array - (min + offset);
		*/
		while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}

		return find;
}
