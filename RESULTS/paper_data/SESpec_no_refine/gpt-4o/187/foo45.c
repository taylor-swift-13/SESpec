
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer min_value{L}(int* a, integer lo, integer hi) =
    lo >= hi ? \max_integer
             : \min(a[hi - 1], min_value(a, lo, hi - 1));
*/

/*@
  logic integer min_count{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_eq(a, lo, hi, min_value(a, lo, hi));
*/

/*@
  requires size > 0 && array_len > 0 && array_len < 100;
  requires \valid(array + (0..array_len-1));
  ensures \result == min_count(array, 0, size);
  assigns \nothing;
*/
int foo45(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		/*@
          loop invariant 1 <= c <= size;
          loop invariant f == min_value(array, 0, c);
          loop invariant max == count_eq(array, 0, c, f);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant size == \at(size,Pre);
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
