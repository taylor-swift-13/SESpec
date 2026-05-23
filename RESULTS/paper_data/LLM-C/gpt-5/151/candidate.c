#include <stdlib.h>

int getNumber(int number, int p);

/*@ 
  requires number >= 0;

  ensures (p <= 0 || p > number) ==> \result == 0;
  ensures (1 <= p && p <= number) ==> 
            (\result == (p <= ((number + 1) / 2) ? 2*p - 1 : 2*(p - ((number + 1) / 2))));
  ensures (\result == 0) || (1 <= \result && \result <= number);

  behavior invalid_p:
    assumes p <= 0 || p > number;
    ensures \result == 0;

  behavior valid_p:
    assumes 1 <= p <= number;
    ensures \result == (p <= ((number + 1) / 2) ? 2*p - 1 : 2*(p - ((number + 1) / 2)));

  complete behaviors invalid_p, valid_p;
  disjoint behaviors invalid_p, valid_p;
*/
int getNumber(int number, int p) {

		int *result = (int *)malloc(sizeof(int) * (number));
int result_len = number;
		int *b = (int *)malloc(sizeof(int) * (number));
int b_len = number;
		int c, ii = 0;
		/*@
			loop invariant 0 <= c <= number;
			loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
			loop assigns c, result[0..number-1];
			loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			result[c] = c + 1;
			//@ assert result[c] == c + 1;
		}
		/*@
			loop invariant 0 <= c <= number;
			loop invariant 0 <= ii <= c;
			loop assigns c, ii, b[0..number-1];
			loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			//@ assert result[c] >= 1 && result[c] <= number;
			if (result[c] % 2 != 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
		/*@
			loop invariant 0 <= c <= number;
			loop invariant 0 <= ii <= number;
			loop assigns c, ii, b[0..number-1];
			loop variant number - c;
		*/
		for (c = 0; c < number; c++) {
			b[c] = result[c];
			//@ assert result[c] >= 1 && result[c] <= number;
			if (result[c] % 2 == 0) {
				ii++;
				if (ii == p) {
					return result[c];
				}
			}
		}
		return 0;
}
