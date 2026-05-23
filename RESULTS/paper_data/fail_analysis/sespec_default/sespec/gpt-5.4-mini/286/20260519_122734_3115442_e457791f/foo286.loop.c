
#include <stdlib.h>

/*@
  logic integer seq286(int *r, integer lo, integer hi) =
    lo >= hi ? 0 : seq286(r, lo, hi - 1) + r[hi - 1];
*/

int foo286(int j) {

		int *r = (int *)malloc(sizeof(int) * (j + 1));
        int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
		
            /*@
              loop invariant p >= 2;
              loop invariant r[0] == 0;
              loop invariant r[1] == 1;
              loop invariant \forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2];
              loop assigns p, r[0..j];
            */
            for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
            
		return r[j];
}
