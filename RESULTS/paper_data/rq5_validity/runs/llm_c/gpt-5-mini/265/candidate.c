int getOddOccurrence(int * ints, int ints_len, int array);

/*@
    requires \valid(ints + (0 .. ints_len-1));
    requires 0 <= array <= ints_len;
    assigns \nothing;
    ensures (\forall integer i; 0 <= i < array ==> ints[i] % 2 == 0) <==> \result == 0;
    ensures \result != 0 ==> (\exists integer j; 0 <= j < array && ints[j] % 2 != 0 && \result == ints[j]);
*/
int getOddOccurrence(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= array;
		    loop invariant 0 <= start <= index;
		    loop invariant (start % 2 == 0) ==> ret == 0;
		    loop invariant (start % 2 == 1) ==> (\exists integer j; 0 <= j < index &&
		                                              ints[j] % 2 != 0 &&
		                                              ret == ints[j] &&
		                                              (\forall integer k; j < k < index ==> ints[k] % 2 == 0));
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
