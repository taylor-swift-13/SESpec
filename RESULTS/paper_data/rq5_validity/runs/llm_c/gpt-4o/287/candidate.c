#include <stdlib.h>

/*@
    requires c >= 0;
    ensures \result == 0 ==> c == 0;
    ensures \result == 1 ==> c == 1;
    ensures \result == \old(jacobsthalNum(c - 1)) + 2 * \old(jacobsthalNum(c - 2)) ==> c >= 2;
    assigns \nothing;
*/
int jacobsthalNum(int c);

int jacobsthalNum(int c) {
    /*@
        requires c >= 0;
        ensures \result == 0 ==> c == 0;
        ensures \result == 1 ==> c == 1;
        ensures \result == \old(jacobsthalNum(c - 1)) + 2 * \old(jacobsthalNum(c - 2)) ==> c >= 2;
        assigns \nothing;
    */
		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 0;
		j[1] = 1;
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}
