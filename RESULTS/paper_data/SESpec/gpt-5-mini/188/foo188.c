
/*@ 
  logic integer count_val(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_val(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  logic integer slice_min(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : (hi - lo == 1 ? a[lo] : (slice_min(a, lo, hi - 1) < a[hi - 1] ? slice_min(a, lo, hi - 1) : a[hi - 1]));
*/

/*@
  requires size >= 0;
  requires \valid_read(a + (0 .. a_len-1));
  requires 0 <= size <= a_len;
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> \result >= 1;
  ensures \forall integer i; 0 <= i < a_len ==> a[i] == \at(a[i], Pre);
*/
int foo188(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int max = 1;

        /*@
          loop invariant 1 <= c <= size;
          loop invariant 0 <= max <= c;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant f == slice_min(a, 0, c);
          loop invariant 1 <= max;
          loop assigns c, f, max;
        */
            for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				max = 1;
			} else if (f == a[c]) {
				max++;
			}
		}
            
		return max;
}
