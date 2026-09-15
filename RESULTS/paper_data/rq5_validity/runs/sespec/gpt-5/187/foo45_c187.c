
/*@ 
  logic integer min_prefix_excl(int* a, integer hi) =
    hi <= 0 ? a[0]
            : (min_prefix_excl(a, hi - 1) < a[hi - 1] ? min_prefix_excl(a, hi - 1) : a[hi - 1]);
*/

/*@
  logic integer cnt_eq_range(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : cnt_eq_range(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires size >= 0;
  requires array_len >= 0;
  requires size <= array_len;
  requires size == 0 || \valid(array + (0 .. size - 1));
  ensures \result == 0 ==> \old(size) == 0;
  assigns \nothing;
*/
int foo45_c187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

        /*@
          loop invariant 1 <= c;
          loop invariant size == \at(size,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop invariant (c < size) ==> (c <= \at(size,Pre));
          loop invariant (c == 1) ==> (f == array[0] && max == 1);
          loop invariant (c >= 1) ==> (f == min_prefix_excl(array, c));
          loop invariant \forall integer k; 0 <= k < c ==> f <= array[k];
          loop invariant 1 <= max <= c;
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
