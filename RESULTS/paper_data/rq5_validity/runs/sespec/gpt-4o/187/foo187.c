
/*@
  logic integer count_occurrences(int* array, integer len, integer value) =
    len <= 0 ? 0 : count_occurrences(array, len - 1, value) + (array[len - 1] == value ? 1 : 0);
*/

/*@
  logic integer min_value(int* array, integer len) =
    len <= 0 ? 0 : (len == 1 ? array[0] : (array[len - 1] < min_value(array, len - 1) ? array[len - 1] : min_value(array, len - 1)));
*/

/*@
  predicate unchanged_array{L1,L2}(int* array, integer len) =
    \forall integer i; 0 <= i < len ==> \at(array[i],L1) == \at(array[i],L2);
*/

/*@
  requires size > 0;
  requires size <= array_len; // Ensure size is within the valid bounds of the array
  requires \valid(array + (0..array_len-1));
  requires array_len > 0 && array_len < 100;
  assigns \nothing;
*/
int foo187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

        /*@
          loop invariant 1 <= c <= size;
          loop invariant f == min_value(array, c);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i],Pre);
          loop invariant unchanged_array{Pre,Here}(array, array_len);
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
