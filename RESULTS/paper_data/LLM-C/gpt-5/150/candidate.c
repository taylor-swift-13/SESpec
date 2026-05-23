#include <stdlib.h>

int getNumber(int value, int p);

/*@ 
  requires value >= 0;

  ensures (p <= 0 || p > value) ==> \result == 0;
  ensures 1 <= p && p <= (value + 1) / 2 ==> \result == 2*p - 1;
  ensures (value + 1) / 2 < p && p <= value ==> \result == 2*(p - ((value + 1) / 2));
*/
int getNumber(int value, int p) {

		int *result = (int *)malloc(sizeof(int) * (value));
int result_len = value;
/*@ assert value == 0 || result != \null; */
/*@ assert value == 0 || \valid(result + (0..value-1)); */

		int *b = (int *)malloc(sizeof(int) * (value));
int b_len = value;
/*@ assert value == 0 || b != \null; */
/*@ assert value == 0 || \valid(b + (0..value-1)); */
/*@ assert value == 0 || \separated(result + (0..value-1), b + (0..value-1)); */

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
		  loop invariant 0 <= j <= c;
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
