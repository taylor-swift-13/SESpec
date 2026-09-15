
#include <stdlib.h>

/*@
  requires 0 <= value;
  requires 0 <= p;
*/

int foo150(int value, int p) {

	int *result = (int *)malloc(sizeof(int) * (value));
	int result_len = value;
	int *b = (int *)malloc(sizeof(int) * (value));
	int b_len = value;
	int c, j = 0;

	/*@
	  loop invariant 0 <= c <= value;
	  loop invariant \forall integer k; 0 <= k < c ==> result[k] == k + 1;
	  loop assigns c, result[0 .. value-1];
	*/
	for (c = 0; c < value; c++) {
		result[c] = c + 1;
	}

	/*@
	  loop invariant 0 <= c <= value;
	  loop invariant 0 <= j;
	  loop assigns c, j, b[0 .. value-1];
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
	  loop invariant 0 <= j;
	  loop assigns c, j, b[0 .. value-1];
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
