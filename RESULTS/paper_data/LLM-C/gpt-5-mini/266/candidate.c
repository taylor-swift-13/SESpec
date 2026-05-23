int getOddOccurrence(int * array, int array_len, int Array);

/*@
    requires array_len >= 0;
    requires Array >= 0 && Array <= array_len;
    requires Array == 0 || \valid_read(array + (0 .. Array-1));
    assigns \nothing;
    ensures (\forall integer i; 0 <= i < Array ==> array[i] % 2 == 0) ==> \result == 0;
    ensures (\exists integer k; 0 <= k < Array &&
                array[k] % 2 != 0 &&
                (\sum integer j; 0 <= j <= k; (array[j] % 2 != 0 ? 1 : 0)) % 2 == 1 &&
                (\forall integer j; k < j < Array ==>
                    (\sum integer t; 0 <= t <= j; (array[t] % 2 != 0 ? 1 : 0)) % 2 == 0
                ) && \result == array[k]);
*/
int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= Array;
		    loop invariant 0 <= start <= index;
		    loop invariant start == (\sum integer j; 0 <= j < index; (array[j] % 2 != 0 ? 1 : 0));
		    loop invariant (
		        (
		            (\exists integer k; 0 <= k < index &&
		                array[k] % 2 != 0 &&
		                (\sum integer j; 0 <= j <= k; (array[j] % 2 != 0 ? 1 : 0)) % 2 == 1 &&
		                (\forall integer j; k < j < index ==>
		                    (\sum integer t; 0 <= t <= j; (array[t] % 2 != 0 ? 1 : 0)) % 2 == 0
		                ) && ret == array[k]
		            )
		        )
		        ||
		        (
		            (\forall integer i; 0 <= i < index ==> array[i] % 2 == 0) && ret == 0
		        )
		    );
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
