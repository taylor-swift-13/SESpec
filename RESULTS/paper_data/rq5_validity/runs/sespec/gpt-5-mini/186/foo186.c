
/*@
  logic integer min_pref(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647 :
    ( hi-1 == lo ? a[lo] : ( min_pref(a, lo, hi-1) < a[hi-1] ? min_pref(a, lo, hi-1) : a[hi-1]) );
*/

/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi-1, v) + (a[hi-1] == v ? 1 : 0);
*/

/*@
  requires \at(size,Pre) != 0 && \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100 ;
  requires \valid_read(a + (0..a_len-1));
  requires 0 <= \at(size,Pre) <= a_len;
  assigns \nothing;
*/
int foo186(int size, int * a, int a_len) {

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

		
            
        /*@
          loop invariant 1 <= c <= \at(size,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer i; 0 <= i < a_len ==> a[i] == \at(a[i],Pre);
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
