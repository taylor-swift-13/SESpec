
/*@
  logic integer count_max{L}(int* array, integer lo, integer hi, int v) =
    lo >= hi ? 0
             : count_max(array, lo, hi - 1, v) + (array[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
*/
int foo187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

        /*@
          loop invariant 1 <= c;
          loop invariant max >= 1;
          loop invariant \exists integer k; 0 <= k < c && f == array[k];
          loop invariant array_len == \at(array_len,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
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
