#include <stdlib.h>

/*@
    requires num >= 0;
    ensures \result == 2 || \result == 1 || \result > 1;
    assigns \nothing;
*/
int findLucas(int num);

int findLucas(int num) {
    /*@
        requires num >= 0;
        ensures \result == 2 || \result == 1 || \result > 1;
        assigns \nothing;
    */
		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
}
