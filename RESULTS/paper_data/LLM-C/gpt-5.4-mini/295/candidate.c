#include <stdlib.h>

/*@
    requires num >= 1;
    ensures \result >= 1;
    assigns \nothing;
*/
int findLucas(int num);

 /*@
    requires num >= 1;
    ensures \result >= 1;
    assigns \nothing;
*/
int findLucas(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		/*@
		    loop invariant 2 <= l <= num + 1;
		    loop invariant result[0] == 2;
		    loop invariant result[1] == 1;
		    loop assigns l, result[2..num];
		    loop variant num - l + 1;
		*/
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
}
