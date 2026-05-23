int frequencyOfSmallest(int size, int * array, int array_len);

/*@
    requires 0 <= size <= array_len;
    requires array_len >= 0;
    requires \valid(array + (0 .. array_len - 1));
    assigns \nothing;
    ensures size == 0 ==> \result == 0;
    ensures size > 0 ==>
        (\exists integer i0; 0 <= i0 < size &&
            (\forall integer j; 0 <= j < size ==> array[j] >= array[i0]) &&
            \result == (\sum integer j; 0 <= j < size && array[j] == array[i0]; 1)
        );
*/
int frequencyOfSmallest(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		/*@
		    loop invariant (size <= 1 && c == 1) || (1 <= c && c <= size);
		    loop invariant c <= size ==> (\forall integer j; 0 <= j < c ==> array[j] >= f);
		    loop invariant c <= size ==> (\exists integer k; 0 <= k < c && array[k] == f);
		    loop invariant c <= size ==> max == (\sum integer j; 0 <= j < c && array[j] == f; 1);
		    loop assigns c, f, max;
		    loop variant size - c;
		*/
		for (int c = 1; c < size; c++) {
			if (f > array[c]) {
				f = array[c];
				max = 1;
			} else if (f == array[c]) {
				max++;
			}
		}
		return max;
}
