int frequencyOfSmallest(int size, int * array, int array_len);

/*@ 
  logic integer count_occurrences{L}(int *a, integer n, integer v) =
    (n <= 0) ? 0 : count_occurrences(a, n-1, v) + ((a[n-1] == v) ? 1 : 0);

  logic integer min_value{L}(int *a, integer n) =
    (n <= 0) ? 0 :
    (n == 1) ? a[0] :
    (min_value(a, n-1) < a[n-1] ? min_value(a, n-1) : a[n-1]);

*/

/*@
  requires size >= 0;
  requires array_len >= size;
  requires size == 0 || \valid_read(array + (0 .. size-1));
  assigns \nothing;

  behavior empty:
    assumes size == 0;
    ensures \result == 0;

  behavior nonempty:
    assumes size > 0;
    ensures \result == count_occurrences(array, size, min_value(array, size));
    ensures 1 <= \result <= size;

  complete behaviors;
  disjoint behaviors;
*/
int frequencyOfSmallest(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		/*@
		  loop invariant 1 <= c <= size;
		  loop invariant f == min_value(array, c);
		  loop invariant max == count_occurrences(array, c, f);
		  loop invariant 1 <= max <= c;
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
