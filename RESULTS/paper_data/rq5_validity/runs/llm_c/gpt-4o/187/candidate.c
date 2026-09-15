/*@
    requires size >= 0;
    requires array_len >= size;
    requires \valid(array + (0..array_len-1));
    ensures \result >= 0;
    ensures size == 0 ==> \result == 0;
    ensures size > 0 ==> \exists integer f; \exists integer count;
        (\forall integer i; 0 <= i < size ==> array[i] >= f) &&
        (\forall integer i; 0 <= i < size ==> (array[i] == f ==> count++)) &&
        \result == count;
    assigns \nothing;
*/
int frequencyOfSmallest(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		/*@
		    loop invariant 1 <= c <= size;
		    loop invariant \exists integer f; \exists integer count;
		        (\forall integer i; 0 <= i < c ==> array[i] >= f) &&
		        (\forall integer i; 0 <= i < c ==> (array[i] == f ==> count++)) &&
		        max == count;
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
