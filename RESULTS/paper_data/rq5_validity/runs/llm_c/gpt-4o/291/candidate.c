#include <stdlib.h>

/*@
    requires c >= 0;
    ensures \result == 2 if c == 0;
    ensures \result == 1 if c == 1;
    ensures \result == \sum(0, c, \lambda integer k; (k == 0 ? 2 : (k == 1 ? 1 : \sum(0, k-1, \lambda integer i; (i == k-1 ? 1 : 2)))));
    assigns \nothing;
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
		return j[c];
}
