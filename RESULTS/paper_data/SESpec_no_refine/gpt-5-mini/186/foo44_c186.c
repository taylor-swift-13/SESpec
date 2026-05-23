
/*@
  logic integer min_slice(int *a, integer lo, integer hi) =
    lo >= hi ? 0
            : (lo + 1 == hi ? a[lo]
                            : (min_slice(a, lo, hi-1) < a[hi-1] ? min_slice(a, lo, hi-1) : a[hi-1]));

  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate valid_array{L}(int *a, integer a_len) = \valid_read(a + (0 .. a_len-1));

  logic integer min_slice_local(int *a, integer lo, integer hi) =
    lo >= hi ? 0
            : (lo + 1 == hi ? a[lo]
                            : (min_slice_local(a, lo, hi-1) < a[hi-1] ? min_slice_local(a, lo, hi-1) : a[hi-1]));

  logic integer count_eq_local(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq_local(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/
/*@
  requires \at(size,Pre) != 0 && \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires valid_array{Pre}(a,\at(a_len,Pre));
  requires 0 <= \at(size,Pre) <= \at(a_len,Pre);
  assigns \nothing;
*/
int foo44_c186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		
            
        /*@
          loop invariant 1 <= c <= \at(size,Pre);
          loop invariant 0 <= c <= \at(size,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer i; 0 <= i < \at(a_len,Pre) ==> a[i] == \at(a[i],Pre);
          loop invariant f == min_slice_local(a, 0, c);
          loop assigns c, f, total;
            */
            for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				total = 1;
			} else if (f == a[c]) {
				total++;
			}
		}
            
		return total;
}
