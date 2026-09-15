#include <stdlib.h>

/*@
    requires j >= 0;
    ensures \result == 0 ==> j == 0;
    ensures \result == 1 ==> j == 1;
    ensures \result == \old(j >= 2) ==> \result == \old(jacobsthalNum(j - 1) + 2 * jacobsthalNum(j - 2));
    assigns \nothing;
*/
int jacobsthalNum(int j);

int jacobsthalNum(int j) {
    /*@
        requires j >= 0;
        ensures \result == 0 ==> j == 0;
        ensures \result == 1 ==> j == 1;
        ensures \result == \old(j >= 2) ==> \result == \old(jacobsthalNum(j - 1) + 2 * jacobsthalNum(j - 2));
        assigns \nothing;
    */
		int *r = (int *)malloc(sizeof(int) * (j + 1));
int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		return r[j];
}
