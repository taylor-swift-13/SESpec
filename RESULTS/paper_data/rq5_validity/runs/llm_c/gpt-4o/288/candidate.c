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
		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
		return ret[j];
}
