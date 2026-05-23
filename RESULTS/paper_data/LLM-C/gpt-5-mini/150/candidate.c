#include <stdlib.h>

/*@
    requires value >= 0;
    requires p >= 0;
    assigns \nothing;
    behavior returns_zero:
        assumes p < 1 || p > value;
        ensures \result == 0;
    behavior returns_from_odds:
        assumes 1 <= p <= (value + 1) / 2;
        ensures \result == 2 * p - 1;
    behavior returns_from_evens:
        assumes (value + 1) / 2 < p <= value;
        ensures \result == 2 * (p - (value + 1) / 2);
    complete behaviors returns_zero, returns_from_odds, returns_from_evens;
    disjoint behaviors returns_zero, returns_from_odds, returns_from_evens;
*/
int getNumber(int value, int p);

int getNumber(int value, int p) {

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
		int c, j = 0;
		/*@
		    loop invariant 0 <= c <= value;
		    loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
		    loop assigns c, result[0..value-1];
		    loop variant value - c;
		*/
		for (c = 0; c < value; c++) {
			result[c] = c + 1;
		}
		/*@
		    loop invariant 0 <= c <= value;
		    loop invariant 0 <= j <= value;
		    loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
		    loop assigns c, j, b[0..value-1];
		    loop variant value - c;
		*/
		for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 != 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		/*@
		    loop invariant 0 <= c <= value;
		    loop invariant 0 <= j <= value;
		    loop invariant \forall integer k; 0 <= k < c ==> b[k] == result[k];
		    loop assigns c, j, b[0..value-1];
		    loop variant value - c;
		*/
		for (c = 0; c < value; c++) {
			b[c] = result[c];
			if (result[c] % 2 == 0) {
				j++;
				if (j == p) {
					return result[c];
				}
			}
		}
		return 0;
}
