
/*@
  logic integer count_mismatch(int *a, int *b, integer lo, integer hi) =
    lo >= hi ? 0 :
    count_mismatch(a, b, lo, hi - 1) + (a[hi - 1] != b[hi - 1] ? 1 : 0);
*/

int foo95(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@
          loop invariant 0 <= i;
          loop invariant count_mismatch(a, b, 0, i) == 0;
          loop assigns i;
        */
        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
