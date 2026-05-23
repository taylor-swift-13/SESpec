
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires size >= 0;
  requires size == 0 || array != \null;
  requires array_len >= 0;
  requires size <= array_len;
  requires size == 0 || \valid_read(array + (0..size-1));
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> \result >= 0;
*/
int foo187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

        /*@
          loop invariant 1 <= c;
          loop invariant 0 <= c <= size;
          loop invariant 0 <= max <= c;
          loop invariant \valid_read(array + (0..size-1));
          loop invariant \forall integer k; 0 <= k < c ==> f <= array[k];
          loop invariant (c < size) ==> (0 <= c && c < array_len);
          loop invariant (!(c < size)) ==> (c >= size);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop assigns c, f, max;
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
