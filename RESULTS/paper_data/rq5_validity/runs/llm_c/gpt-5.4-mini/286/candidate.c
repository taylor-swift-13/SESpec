#include <stdlib.h>

/*@
    requires j >= 1;
    requires \valid((int *)malloc(sizeof(int) * (j + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int jacobsthalNum(int j);

 /*@
    requires j >= 1;
    assigns \nothing;
    ensures \result >= 0;
*/
int jacobsthalNum(int j) {

		int *r = (int *)malloc(sizeof(int) * (j + 1));
int r_len = j + 1;
		r[0] = 0;
		r[1] = 1;
		/*@
            loop invariant 2 <= p <= j + 1;
            loop invariant \forall integer i; 0 <= i < p ==> r[i] >= 0;
            loop assigns p, r[2..j];
            loop variant j - p + 1;
        */
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		return r[j];
}
